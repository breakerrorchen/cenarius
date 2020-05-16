
includes("infrastructure/css_pattern/xmake.cenarius.lua")
includes("infrastructure/crypto/xmake.cenarius.lua")
includes("infrastructure/kv-store/xmake.cenarius.lua")
includes("infrastructure/interpreter/xmake.cenarius.lua")
includes("infrastructure/serialize/xmake.cenarius.lua")
includes("infrastructure/net/xmake.cenarius.lua")
includes("infrastructure/archiver/xmake.cenarius.lua")
includes("infrastructure/audio/xmake.cenarius.lua")
includes("infrastructure/renderer/xmake.cenarius.lua")
includes("infrastructure/renderer_x/xmake.cenarius.lua")

includes("platform/xmake.lua")

target("cenarius")
    --add_cxflags("-O3  -fdata-sections -ffunction-sections")
    --add_ldflags("-Wl,--gc-sections")
    
    set_languages("c99", "cxx17")

    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    
    --add_rules("mode.debug")
    set_kind("shared")
    -- add_cxflags("-fsanitize=address")
    -- add_ldflags("-fsanitize=address")
    -- add_shflags("-fsanitize=address")

    add_cxflags("-Wall", "-Wreturn-type", "-Werror=return-type")
    add_cxflags("-Oz", 
        "-fvisibility=hidden", 
        "-fvisibility-inlines-hidden", 
        "-flto", 
        "-fno-stack-protector")
    add_shflags("-flto", "--gc-sections")
    add_ldflags("-flto", "-Wl", "--gc-sections")

    -- include
    add_includedirs(".");

    -- src
    add_files       ("common/*.cc")
    add_files       ("kernal/asynchronous/*.cc")
    add_files       ("kernal/asynchronous/command_buffer/*.cc")
    add_files       ("kernal/asynchronous/runnable/*.cc")
    add_files       ("kernal/asynchronous/syncer/*.cc")
    add_files       ("kernal/bale/*.cc")
    add_files       ("kernal/basis_service/*.cc")
    add_files       ("kernal/bestead/*.cc")
    add_files       ("kernal/cc/*.cc")
    add_files       ("kernal/isolate/*.cc")

    add_files       ("kernal/components/*.cc")
    add_files       ("kernal/components/audio/*.cc")
    add_files       ("kernal/components/bridger/*.cc")
    add_files       ("kernal/components/device/*.cc")
    add_files       ("kernal/components/event/*.cc")
    add_files       ("kernal/components/fs/*.cc")
    add_files       ("kernal/components/graphics/*.cc")
    add_files       ("kernal/components/graphics/canvas/*.cc")
    add_files       ("kernal/components/graphics/render_context_2d/*.cc")
    add_files       ("kernal/components/graphics/render_context_2d_gradient/*.cc")
    add_files       ("kernal/components/graphics/render_context_2d_pattern/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_active_info/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_buffer/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_constants/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_framebuffer/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_program/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_renderbuffer/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_shader/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_shader_precison/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_texture/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_uniform_location/*.cc")
    add_files       ("kernal/components/graphics/render_context_3d_vertex_array/*.cc")
    add_files       ("kernal/components/image/*.cc")
    add_files       ("kernal/components/image_data/*.cc")
    add_files       ("kernal/components/inspector/*.cc")
    add_files       ("kernal/components/interaction/*.cc") 
    add_files       ("kernal/components/lifecycle/*.cc")
    add_files       ("kernal/components/maintain/*.cc")
    add_files       ("kernal/components/misc/*.cc")
    add_files       ("kernal/components/network/*.cc")
    add_files       ("kernal/components/performance/*.cc")
    add_files       ("kernal/components/storage/*.cc")
    add_files       ("kernal/components/system/*.cc")
    add_files       ("kernal/components/timer/*.cc")
    add_files       ("kernal/components/worker/*.cc")


    add_files       ("kernal/scheduler/*.cc")
    add_files       ("kernal/test/*.cc")

    add_files       ("benchmark/*.cc")
    -- add_linkdirs    ("infrastructure/electric-fence")
    -- add_links       ("efence")
    