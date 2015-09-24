// this file is automatically created from Rae programming language module:
///Users/joonaz/Dropbox/jonas/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Engine
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


	~Engine(); // line: 284
public: 
	
	Engine(GLFWwindow* set_window); // line: 256
	void run();
	
	void update(double time, double delta_time); // line: 193
	void osEventCloseWindow(); // line: 198
	void osEventResizeWindow(int32_t width, int32_t height); // line: 203
	void osEventResizeWindowPixels(int32_t width, int32_t height); // line: 211
	void onMouseButtonPress(int32_t set_button, double x, double y); // line: 219
	protected: 
	
	bool m_isRunning; // line: 257
	
	GLFWwindow* m_window; // line: 259
	
	// timing
	double m_previousTime; // line: 262
	double m_currentTime; // line: 263
	
	// TODO
	//RenderSystem m_renderSystem
	
	float m_currentAngle; // line: 268
	
	Shader shader; // line: 270
	Mesh mesh; // line: 271
	
	//temp
	uint32_t modelViewMatrixUni; // line: 274
	uint32_t viewMatrixUni; // line: 275
	uint32_t modelMatrixUni; // line: 276
	uint32_t lightPositionUni; // line: 277
	uint32_t textureUni; // line: 278
	
	//temp window size stuff:
	
	int32_t m_windowWidth; // line: 282
	int32_t m_windowHeight; // line: 283
	
};



#endif // _rae_3d_Engine_hpp_

