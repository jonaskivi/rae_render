# rae_render
Simple OpenGL example written in the Rae programming language

![ScreenShot](https://cloud.githubusercontent.com/assets/6566641/10018534/432f6db0-6140-11e5-9528-534c135b19d0.png)

# Building

	git clone https://github.com/jonaskivi/rae_render.git
	cd rae_render/src
	# on OSX:
	premake4 xcode4
	# on Windows:
	premake4 vs2012

Open the project file and build it. (On Xcode 5 I needed to change the SDK to 10.9 and the C++ dialect and stdlib versions to C++11.)
The glfw and glew .a and .lib files are included for OS X and Windows.

