# rae_render
Simple OpenGL example written in the Rae programming language

![ScreenShot](https://cloud.githubusercontent.com/assets/6566641/10018534/432f6db0-6140-11e5-9528-534c135b19d0.png)

# Building

Use the instructions in rae_programming_language project to build and install raec.

	git clone https://github.com/jonaskivi/rae_render.git
	cd rae_render/src
	
    raec ./main.rae
    # There will be about 60 errors, but that's okay :)

    # on OSX:
	premake4 xcode4
    # On Xcode 5 I needed to change the SDK to 10.9 and the C++ dialect and stdlib versions to C++11.
    # Open the project file and build it.
	
    # on Windows:
	premake4 vs2012
    # Open the project file and build it.
    
    # on Linux (use premake4.4beta, not 4.3 which comes with Ubuntu 14.04):
    premake4 gmake
    # I had to install the GL headers:
    sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
    # I installed GLFW3 and GLEW from source, and copied the libs to the lib dir.
    # And finally:
    make
    # cd into the bin directory and run:
    ./rae_render
    
The glfw and glew .a and .lib files are included for OS X and Windows. The premake4 script is not capable of building the libs, but it can be used for including the headers and linking the libs from the lib directory.
Suggestions on making the build script better are welcome!

