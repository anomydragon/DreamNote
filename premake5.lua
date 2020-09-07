workspace "DreamNote"
    architecture "x86_64"
    startproject "DreamNote"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "DreamRenderer/3rdParty/GLFW.lua"
include "DreamRenderer/3rdParty/GLAD.lua"

project "DreamRenderer"
    location "DreamRenderer"
    kind "SharedLib"
    language "C++"
    staticruntime "On"

    targetdir ("build/" .. OutputDir .. "/%{prj.name}")
    objdir ("build-obj/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "DreamRenderer/src/**.h",
        "DreamRenderer/src/**.cpp"
    }

    defines
    {
        "GLFW_INCLUDE_NONE"
    }

    includedirs
    {
        "DreamRenderer/src",
        "DreamRenderer/3rdParty/GLAD/include"
    }

    links
    {
        "GLFW",
        "GLAD",
        "dl",
        "pthread"
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
        "Notes/src/**.h",
        "Notes/src/**.cpp"
    }

    includedirs
    {
        "Notes/src",
        "DreamRenderer/src"
    }

    links
    {
        "DreamRenderer"
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
