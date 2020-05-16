
target("cenarius")
    add_includedirs ("include")
    add_files       ("src/*.cc");
    add_includedirs ("external/leveldb/include")
    add_linkdirs    ("external/libs/$(plat)/$(arch)")
    add_links       ("leveldb")
    