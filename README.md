# rae_render
Simple OpenGL example written in the Rae programming language

# Building

	git clone https://github.com/jonaskivi/rae_render.git
	cd rae_render/src
	# on OSX:
	premake4 xcode4
	# on Windows:
	premake4 vs2012

Open the project file and build it. (On Xcode 5 I needed to change the SDK to 10.9 and the C++ compiler and stdlib versions to C++11.)
The glfw and glew .a and .lib files are included for OS X and Windows.

