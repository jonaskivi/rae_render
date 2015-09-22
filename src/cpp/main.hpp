// this file is automatically created from Rae programming language module:
///home/joonaz/2015/ohjelmointi/rae_render/src/cpp/main
#ifndef _main_hpp_
#define _main_hpp_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "rae/link.hpp"





/*
#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <vector>
*/

//@cpp

#ifdef __APPLE__
	#define GLFW_INCLUDE_GLCOREARB
#endif
//@end
; // line: 63

#include "GL/glew.hpp"


//@cpp

#include <GLFW/glfw3.h>
GLFWwindow* glfw_window;

//TODO #include "nanovg.h"
//#include "nanovg_gl.h"
//#include "nanovg_gl_utils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//@end
; // line: 77

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

Engine* g_engine = nullptr; // line: 100

//@cpp


void windowSizeCallback(GLFWwindow* glfw_window, int width, int height)
{
	if( g_engine == nullptr )
		return;
	g_engine->osEventResizeWindow(width, height);
}

void windowPixelSizeCallback(GLFWwindow* glfw_window, int width, int height)
{
	if( g_engine == nullptr )
		return;
	g_engine->osEventResizeWindowPixels(width, height);
}

void GLFWonMouseButton(GLFWwindow* set_window, int set_button, int set_action, int set_mods)
{
	if( g_engine == nullptr )
		return;
	/*
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
	*/
}

void GLFWonWindowClose(GLFWwindow* set_window)
{
	if( g_engine == nullptr )
		return;
	g_engine->osEventCloseWindow();
}

#define check_gl_error() _check_gl_error(__FILE__,__LINE__)

void _check_gl_error(const char *file, int line)
{
        GLenum err (glGetError());
 
        while(err!=GL_NO_ERROR) {
                std::string error;
 
                switch(err) {
                        case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
                        case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
                        case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
                        case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
                        case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
                }
 
                std::cerr << "GL_" << error.c_str() << " - " << file << ":" << line << std::endl;
                err = glGetError();
        }
}

//@end
; // line: 168

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



#endif // _main_hpp_

