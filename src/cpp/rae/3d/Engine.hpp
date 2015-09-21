// this file is automatically created from Rae programming language module:
//c:\Users\jonaz\Dropbox\jonas\2015\ohjelmointi\rae_render\src/cpp/rae/3d/Engine
#ifndef _rae_3d_Engine_hpp_
#define _rae_3d_Engine_hpp_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "rae/link.hpp"



#include "rae/3d/Entity.hpp"

#include "rae/3d/Shader.hpp"

#include "rae/3d/Mesh.hpp"

#include "GL/glew.hpp"

#include "glm/glm.hpp"


//@cpp

#ifdef __APPLE__
	#define GLFW_INCLUDE_GLCOREARB
#endif
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/gtc/matrix_transform.hpp>
//@end
; // line: 18

// if we don't have bindings, we can just quickly use functions and classes by using the extern keyword.




class Engine
{public:
	
	//-------------Rae boilerplate code-------------
		
	//link management:

	void _rae_link(rae::link<Engine>& a_link)
	{
		#ifdef RAE_DEBUG
			std::cout<<"Tester._rae_link()\n";
		#endif

		if(a_link.obj != nullptr)
		{
			std::cout<<"link Error. The link is already in use.\n";
		}

		if(_rae_link_list)// != nullptr)
		{
			//we already have a link_list (and have been linked)
			_rae_link_list->addLink(&a_link);
		}
		else
		{
			_rae_link_list = new rae::LinkList<Engine>(this, &a_link);
		}
	}

	void _rae_unlink_all()
	{
		#ifdef RAE_DEBUG
			std::cout<<"Tester._rae_unlink() by POINTER: "<<this<<" VALUE: "<<*this<<"\n";
		#endif

		if(_rae_link_list)
		{
			#ifdef RAE_DEBUG
				std::cout<<"val.unlink calling _rae_link_list->unlinkByValue."<<"\n";
			#endif

			_rae_link_list->unlinkAllByValue();
			
			delete _rae_link_list;
			_rae_link_list = nullptr;
		}
		#ifdef RAE_DEBUG
		else
		{
			std::cout<<"Tester is already unlinked since _rae_link_list is nullptr.\n";
		}
		#endif
	}

	rae::LinkList<Engine>* _rae_link_list;

	//-------------end Rae boilerplate code-------------


	~Engine(); // line: 286
public: 
	
	Engine(GLFWwindow* set_window); // line: 258
	void run();
	
	void update(double time, double delta_time); // line: 194
	void osEventCloseWindow(); // line: 199
	void osEventResizeWindow(int32_t width, int32_t height); // line: 204
	void osEventResizeWindowPixels(int32_t width, int32_t height); // line: 212
	void onMouseButtonPress(int32_t set_button, double x, double y); // line: 220
	protected: 
	
	bool m_isRunning; // line: 259
	
	GLFWwindow* m_window; // line: 261
	
	// timing
	double m_previousTime; // line: 264
	double m_currentTime; // line: 265
	
	// TODO
	//RenderSystem m_renderSystem
	
	float m_currentAngle; // line: 270
	
	Shader shader; // line: 272
	Mesh mesh; // line: 273
	
	//temp
	uint32_t modelViewMatrixUni; // line: 276
	uint32_t viewMatrixUni; // line: 277
	uint32_t modelMatrixUni; // line: 278
	uint32_t lightPositionUni; // line: 279
	uint32_t textureUni; // line: 280
	
	//temp window size stuff:
	
	int32_t m_windowWidth; // line: 284
	int32_t m_windowHeight; // line: 285
	
};



#endif // _rae_3d_Engine_hpp_

