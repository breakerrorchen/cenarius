
#include "kv.h"
using namespace cenarius;
using namespace infrastructure;
using namespace persistence;

kv_store::kv_store(const char* v) {
    open(v);
}

bool kv_store::is_useable() const {
    return (bool)db_;
}

bool kv_store::open(const char* src) {
    if (nullptr == src) return false;
    bool is_success = false;

    atomic_lock(true);
    db_ = nullptr;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::DB* db = nullptr;
    auto status = leveldb::DB::Open(options, src, &db);
    is_success = status.ok() && db;
    if (is_success) {
        db_ = std::shared_ptr<leveldb::DB>(db);
    }
    atomic_lock(false);
    return is_success;
}

bool kv_store::set(const char* k, std::string& v) {
    if (nullptr == k) return false;
    std::shared_ptr<leveldb::DB> database;
    atomic_lock(true); 
    database = db_; 
    atomic_lock(false);
    if (!database) return false;
    return database->Put(leveldb::WriteOptions(), k,  v).ok();
}

bool kv_store::get(const char* k, std::string& v) {
    if (nullptr == k) return false;
    std::shared_ptr<leveldb::DB> database;
    atomic_lock(true); 
    database = db_; 
    atomic_lock(false);
    if (!database) return false;
    return database->Get(leveldb::ReadOptions(), k, &v).ok();
}

 bool kv_store::remove(const char* k) {
    if (nullptr == k) return false;
    std::shared_ptr<leveldb::DB> database;
    atomic_lock(true); 
    database = db_; 
    atomic_lock(false);
    if (!database) return false;
    return db_->Delete(leveldb::WriteOptions(), k).ok();
 }

bool kv_store::clear() {
    std::shared_ptr<leveldb::DB> database;
    atomic_lock(true); 
    database = db_; 
    atomic_lock(false);
    if (!database) return false;
    leveldb::WriteBatch batch;
    auto iter = db_->NewIterator(leveldb::ReadOptions());
    if (nullptr == iter) return false;
    for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
        batch.Delete(iter->key());
    }
    delete iter; iter = nullptr;
    return db_->Write(leveldb::WriteOptions(), &batch).ok();
}

bool kv_store::close() {
    atomic_lock(true);  db_ = nullptr; atomic_lock(false);
    return true;
}

bool kv_store::atomic_lock(bool v) {
    if (v) {
        while(locker_.test_and_set(std::memory_order_acquire)) {
            ;
        }
    } else {
        locker_.clear(std::memory_order_release);
    }
    return true;
}