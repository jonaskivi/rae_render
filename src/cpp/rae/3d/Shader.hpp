// this file is automatically created from Rae programming language module:
///home/joonaz/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Shader
#ifndef _rae_3d_Shader_hpp_
#define _rae_3d_Shader_hpp_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "rae/link.hpp"



//@cpp

#include <fstream>
#include <algorithm>
#include <stdlib.h> // TODO get rid of getchar()
//@end
; // line: 8

//#include <string.h>

#include "GL/glew.hpp"



class Shader
{public:
	
	//-------------Rae boilerplate code-------------
		
	//link management:

	void _rae_link(rae::link<Shader>& a_link)
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
			_rae_link_list = new rae::LinkList<Shader>(this, &a_link);
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

	rae::LinkList<Shader>* _rae_link_list;

	//-------------end Rae boilerplate code-------------


	~Shader(); // line: 142
public: 
	
	uint32_t shaderID;
	
	Shader(); // line: 17
	Shader(std::string vertex_file_path, std::string fragment_file_path); // line: 17
	void use();
	
	uint32_t loadShader(std::string vertex_file_path, std::string fragment_file_path); // line: 34
	
};



#endif // _rae_3d_Shader_hpp_

