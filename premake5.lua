workspace "DreamNote"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DreamRenderer"
    location "DreamRenderer"
    kind "SharedLib"
    language "C++"
    staticruntime "On"

    targetdir ("build/" .. OutputDir .. "/%{prj.name}")
    targetdir ("build-obj/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "DreamRenderer/src/*.h",
        "DreamRenderer/src/*.cpp"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NDEBUG"
        optimize "On"

    filter "configurations:Dist"
        defines "NDEBUG"
        optimize "On"

project "DreamNote"
    location "Notes"
    kind "ConsoleApp"
    language "C++"
    staticruntime "On"

    targetdir ("build/" .. OutputDir .. "/%{prj.name}")
    objdir ("build-obj/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "**.h",
        "**.cpp"
    }

    includedirs
    {
        "DreamRenderer/src"
    }

    links
    {
        DreamRenderer
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NDEBUG"
        optimize "On"

    filter "configurations:Dist"
        defines "NDEBUG"
        optimize "On"
