workspace "Spearmint"
	location "../../"

	configurations
	{
		"Debug", "Relase"
	}

	platforms
	{
		"Win64"
	}

	filter "platforms:Win64"
		system "Windows"
		architecture "x86_64"
	filter ""

	startproject "Spearmint"

	group "Core"

		project "Spearmint"
			location "%{wks.location}"

			kind "ConsoleApp"
			language "C++"
			cppdialect "C++17"

			staticruntime "On"
			rtti "Off"
			exceptionhandling "Off"
			characterset "Unicode"

			targetname "Spearmint"
			targetdir "%{wks.location}/Binaries/%{cfg.platform}/%{cfg.buildcfg}"
			objdir "%{wks.location}/Intermediate/%{cfg.buildcfg}/%{prj.name}"

			files
			{
				"%{prj.location}/Source/**.h",
				"%{prj.location}/Source/**.cpp"
			}

			includedirs
			{
				"%{prj.location}/Source"
			}

			filter "platforms:Win64"
				systemversion "lastest"
				defines
				{
					"SM_PLATFORM_WINDOWS=1"
				}

			filter "configurations:Debug"
				optimize "Off"
				symbols "On"
				runtime "Debug"
				defines
				{
					"SM_CONFIGURATION_DEBUG=1"
				}

			filter "configurations:Release"
				optimize "On"
				symbols "On"
				defines
				{
					"SM_CONFIGURATION_RELEASE=1"
				}

			filter ""


	group ""