-- premake4.lua
solution "Solution"
   configurations { "Debug", "Release" }

   -- A project defines one build target
   project "main"
      kind "WindowedApp"
      language "C++"
      files { "main.cpp" }

      configuration { "windows" }
        -- for freeglut
        -- links { "FreeGLUT", "glu32", "opengl32"}

        -- for GLUT
        defines { "GLUT_DISABLE_ATEXIT_HACK" }
        links { "glut32", "glu32", "opengl32"}

      configuration { "macosx" }
        linkoptions { "-framework OpenGL -framework GLUT" }

      configuration { "not windows", "not macosx" }
        links { "X11", "GL", "GLU", "GLUT" }

      configuration "Debug"
         defines { "DEBUG" } -- -DDEBUG
         flags { "Symbols" }

      configuration "Release"
         defines { "NDEBUG" } -- -NDEBUG
         flags { "Optimize" }
