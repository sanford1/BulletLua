solution "BulletLua"
    configurations { "Debug", "Release" }
    platforms { "native", "x32", "x64" }

    project "BulletLua"
        language "C++"
        kind "StaticLib"
        buildoptions { "-std=c++11" }

        includedirs { "include", "ext/sol" }
        files { "src/**" }

        targetdir "lib"
        targetname "bulletlua"

        ---------------------------------------
        -- Link static libraries and config
        libdirs { "ext/libbulletml/lib" }
        links { "lua" }

        ---------------------------------------
        -- Build rules
        configuration "Debug"
        defines "DEBUG"
        flags { "Symbols", "ExtraWarnings" }

        configuration "Release"
            flags { "Optimize", "ExtraWarnings" }

    project "Test"
        language "C++"
        buildoptions { "-std=c++11" }

        includedirs { "include", "ext/sol/" }
        files { "example/src/**" }

        targetdir "example/bin"
        targetname "Test"

        ---------------------------------------
        -- Link static libraries and config
        libdirs { "lib" }
        links { "sfml-graphics", "sfml-window", "sfml-system", "lua", "bulletlua" }

        configuration "linux"
            targetprefix "linux_"

        configuration "windows"
            targetprefix "windows_"

        configuration { "native or x64" }
            targetsuffix "64"

        configuration "x32"
            targetsuffix "32"

        ---------------------------------------
        -- Build rules
        configuration "Debug"
            kind "ConsoleApp"
            defines "DEBUG"
            flags { "Symbols", "ExtraWarnings" }

        configuration "Release"
            kind "ConsoleApp"
            flags { "Optimize", "ExtraWarnings" }
