
#pragma once

#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <atomic>
#include <functional>
#include <leveldb/db.h>
#include <leveldb/write_batch.h>

namespace cenarius { namespace infrastructure { namespace persistence {
    class kv_store final {
    public:
        kv_store() = default;
        kv_store(const char*);
        kv_store(const kv_store&) = delete;
        kv_store(kv_store&&) = delete;
        kv_store& operator=(const kv_store&) = delete;
        kv_store& operator=(kv_store&&) = delete;
    
    public:
        bool is_useable() const;

    public:
        bool open  (const char*);
		bool set   (const char*, std::string&);
		bool get   (const char*, std::string&);
		bool remove(const char*);
		bool clear ();
		bool close ();

    private:
		bool atomic_lock(bool v);

    private:
        std::shared_ptr<leveldb::DB> db_;
        std::atomic_flag locker_ = ATOMIC_FLAG_INIT;
    };
}}} // end cenarius.infrastructure.persistence