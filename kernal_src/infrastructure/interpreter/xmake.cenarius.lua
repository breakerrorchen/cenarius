
-- true = v8 / false jsc
local is_use_v8_or_jsc = false

if is_plat("android") then
    is_use_v8_or_jsc = true
end

-- if is_plat("macosx") or is_plat("iphoneos") then
--     is_use_v8_or_jsc = false
-- else
--     is_use_v8_or_jsc = true
-- end

target("cenarius")
    add_includedirs ("include")
    add_files       ("src/*.cc");

    if is_use_v8_or_jsc then
        add_defines("__use_v8_backend__")

        -- v8 build for mac
        if is_plat("macosx") then
            add_includedirs ("external/v8/mac/include")
            add_linkdirs    ("external/v8/mac/libs")
            add_links       ("v8_libplatform", "v8_libbase", "v8")
            add_rpathdirs   ("external/v8/mac/libs")
        -- v8 build for android
        elseif is_plat("android") then
            add_includedirs ("external/v8/android/v8.7.2.100/include")
            add_linkdirs    ("external/v8/android/v8.7.2.100/libs/$(arch)")
            add_links       ("v8_libplatform", "v8_base", "v8_libbase", "v8_snapshot")
            add_links       ("v8_libsampler", "v8_init", "v8_initializers")
        end

    else
        -- jsc
        add_defines("__use_javascriptcore_backend__")
        add_frameworks("JavaScriptCore")
    end
    