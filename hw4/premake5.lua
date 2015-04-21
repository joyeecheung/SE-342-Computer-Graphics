-- premake5.lua
solution "TracingBall"
   configurations { "Debug", "Release" }

   -- A project defines one build target
   project "main"
      kind "ConsoleApp"
      language "C++"
      files { "src/*.cpp" }

      configuration { "windows" }
        links { "FreeGLUT", "glu32", "opengl32"}
        libdirs { "lib" }
        includedirs { "include" }

      configuration { "macosx" }
        linkoptions { "-framework Carbon -framework OpenGL -framework GLUT" }

      configuration { "not windows", "not macosx" }
        links { "X11", "GL", "GLU", "GLUT" }

      configuration "Debug"
         defines { "DEBUG" } -- -DDEBUG
         flags { "Symbols" }

      configuration "Release"
         defines { "NDEBUG" } -- -NDEBUG
         flags { "Optimize" }
