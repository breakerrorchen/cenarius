
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

// After the V8 interpreter is released, 
// the Native objects in the interpreter may not be 
// completely released. Need to traverse and delete
class isolate_dispose: public PersistentHandleVisitor {
public:
    explicit isolate_dispose(Isolate* isolate = nullptr) {
        raw_isolate_ = isolate;
    }
    void VisitPersistentHandle(Persistent<Value>* value, uint16_t _) {
        if (!value || !raw_isolate_) return;
        HandleScope handle_scope(raw_isolate_);
        auto _local = value->Get(raw_isolate_);
        auto external = Local<External>::Cast(_local);
        if (external.IsEmpty()) { return; }
        auto base = reinterpret_cast<i_runtime_base*>(external->Value());
        if (nullptr != base) {
            auto ptr = dynamic_cast<i_runtime_release*>(base);
            if (nullptr != ptr) {
                ptr->on_runtime_release();
            }
            base->force_release();
        }
    }
private:
    Isolate* raw_isolate_ = nullptr;
};

/**
 * i_vm decalre
 * represents the isolation of runtime data.
 * representing an interpreter virtual machine instance.
 * */
i_vm::~i_vm() { inner_related_data_reset(); }

i_vm::i_vm() {
    // use for c++11
    // no member named 'make_unique' in namespace 'std'
    auto ptr = std::unique_ptr<inner_t>(new inner_t());
    inner_ = std::move(ptr);
    inner_->create_params_.array_buffer_allocator =
        ArrayBuffer::Allocator::NewDefaultAllocator();
    _$_ = Isolate::New(inner_->create_params_);
}

i_vm::i_vm(i_vm&& from) {
    _$_ = from._$_; from._$_ = nullptr;
    inner_ = std::move(from.inner_);
}

i_vm& i_vm::operator=(i_vm&& from) {
    if (this != &from) {
        inner_related_data_reset();
        _$_ = from._$_; from._$_ = nullptr;
        inner_ = std::move(from.inner_);
    }
    return *this;
}

void i_vm::inner_related_data_reset() {
    if (inner_ && _$_) {
        isolate_dispose rsvisitor(_$_);
        _$_->VisitHandlesWithClassIds(&rsvisitor);
        _$_->Dispose();
        auto& allocator = inner_->
            create_params_.array_buffer_allocator;
        if (nullptr != allocator) {
            delete allocator; allocator = nullptr;
        }
        _$_ = nullptr;
    }
}

#endif//__use_v8_backend__