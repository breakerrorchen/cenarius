
target("cenarius")
    add_files("*.cc")
    add_links("log", "android", "EGL", "GLESv3", "z")