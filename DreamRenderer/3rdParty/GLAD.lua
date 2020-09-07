project "GLAD"
    kind "StaticLib"
    language "C"
    architecture "x86_64"
    
    targetdir ("build/" .. OutputDir .. "/%{prj.name}")
    objdir ("build-obj/" .. OutputDir .. "/%{prj.name}")
    
    includedirs { "GLAD/include" }

    files
    {
        "GLAD/include/glad/glad.h",
        "GLAD/include/KHR/khrplatform.h",
        "GLAD/src/glad.c"
    }
    
    filter "system:windows"
        systemversion "latest"

    filter "system:linux"
        pic "On"	

        systemversion "latest"
	staticruntime "On"

	defines
    	{
	    "_GLAD_X11"
	}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
