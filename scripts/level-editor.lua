--
-- Copyright (c) 2012-2017 Daniele Bartolini and individual contributors.
-- License: https://github.com/taylor001/crown/blob/master/LICENSE
--

local CROWN_DIR = (path.getabsolute("..") .. "/")
local CROWN_BUILD_DIR = (CROWN_DIR .. "build/")

-- FIXME: Fix this in GENie
premake.valac.valac = premake.valac.valac .. " --gresources=" .. CROWN_DIR .. "tools/ui/resources.xml" .. " --target-glib=2.38"

project "level-editor"
	kind "ConsoleApp"
	language "Vala"

	configuration { "debug" }
		defines {
			"CROWN_DEBUG",
		}

	configuration { "linux" }
		defines {
			"CROWN_PLATFORM_LINUX"
		}

	configuration { "windows" }
		defines {
			"CROWN_PLATFORM_WINDOWS"
		}

	configuration { "linux-*" }
		targetdir (CROWN_BUILD_DIR .. "linux64" .. "/bin")
		objdir (CROWN_BUILD_DIR .. "linux64" .. "/obj")

	configuration { "mingw" }
		targetdir (CROWN_BUILD_DIR .. "mingw64" .. "/bin")
		objdir (CROWN_BUILD_DIR .. "mingw64" .. "/obj")

	configuration {}

	links {
		"gdk-3.0",
		"gee-0.8",
		"gio-2.0",
		"glib-2.0",
		"gtk+-3.0",
		"posix",
	}

	buildoptions {
		"-lm",
		"-Wno-deprecated-declarations",
		"-Wno-incompatible-pointer-types",
		"-Wno-discarded-qualifiers",
		"-Wno-sign-compare",
		"-Wno-unused-function",
		"-Wno-unused-label",
		"-Wno-unused-variable",
		"-Wno-unused-parameter",
		"-Wno-unused-but-set-variable",
	}

	files {
		CROWN_DIR .. "tools/**.vala",
		CROWN_DIR .. "tools/ui/resources.c",
	}

	configuration {}

