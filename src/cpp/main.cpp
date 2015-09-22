// this file is automatically created from Rae programming language module:
///Users/joonaz/Dropbox/jonas/2015/ohjelmointi/rae_render/src/cpp/main
#include "main.hpp"
; // line: 2



/*
#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <vector>
*/

//@end
; // line: 61

#include "GL/glew.hpp"


//@end
; // line: 75

#include "rae/3d/Mesh.hpp"

#include "rae/3d/Shader.hpp"

#include "rae/3d/Engine.hpp"


/* TODO
#include "Random.hpp"
#include "Animator.hpp"
#include "Shader.hpp"
#include "ComponentType.hpp"
#include "Entity.hpp"
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Material.hpp"
#include "ObjectFactory.hpp"
#include "System.hpp"
#include "RenderSystem.hpp"
#include "Engine.hpp"
using namespace Rae;
*/


//@end
; // line: 165

/* TODO
void GLFWonMouseButton(GLFWwindow* set_window, int set_button, int set_action, int set_mods)
{
	if( g_engine == nullptr )
		return;

	double mx, my;
	glfwGetCursorPos(set_window, &mx, &my);

	//cout << "GLFWMouseButtonPress. x: " << mx << " y: " << my << "\n";
	if(set_action == GLFW_PRESS)
	{
		g_engine->onMouseButtonPress(set_button, mx, my);
	}
	else if(set_action == GLFW_RELEASE)
	{
		//TODO release for a proper click, and add a proper event system.
	}
}
*/

int32_t main(int argc, char* const argv[])
{
	std::cout<<"Rae Render 0.1"<<"\n"; // line: 190
	
	//@cpp


	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	// Enable MSAA (multisample anti-aliasing)
	glfwWindowHint(GLFW_SAMPLES, 4);

	#ifndef _WIN32 // don't require this on win32, and works with more cards
	// Set OpenGL version to 2.1
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	#endif
	
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

	// Create glfw_window

	GLFWmonitor* screen     = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(screen);

	int screenWidth = mode->width - 200;
	int screenHeight = mode->height - 200;

	glfw_window = glfwCreateWindow( mode->width - 200, mode->height - 200, "Rae Render", nullptr, nullptr);
	
	if( glfw_window == nullptr )
	{
		fprintf( stderr, "Failed to open GLFW glfw_window.\n" );
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(glfw_window);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	// GLEW generates GL error because it calls glGetString(GL_EXTENSIONS), we'll consume it here.
	glGetError();

	glfwSwapInterval(0);

	glfwSetInputMode(glfw_window, GLFW_STICKY_KEYS, GL_TRUE);
//@end
; // line: 244
	
	// Load it into a VBO
	
	// TODO pass glfw_window here or something...
	Engine engine(glfw_window); // line: 249
	
	g_engine = &engine; // Set global access point just for GLFW callbacks.
	
	//@cpp

	glfwSetWindowSizeCallback     (glfw_window, windowSizeCallback);
	glfwSetFramebufferSizeCallback(glfw_window, windowPixelSizeCallback); // Support hi-dpi displays
	glfwSetMouseButtonCallback    (glfw_window, GLFWonMouseButton);
	glfwSetWindowCloseCallback    (glfw_window, GLFWonWindowClose);
//@end
; // line: 258
	
	
	engine.osEventResizeWindow(screenWidth, screenHeight); // line: 263
	
	engine.run(); // line: 265
	
	//@cpp

		glfwTerminate();
//@end
; // line: 269
	
	return 0;
}


