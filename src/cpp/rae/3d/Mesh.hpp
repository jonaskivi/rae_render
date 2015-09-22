// this file is automatically created from Rae programming language module:
///home/joonaz/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Mesh
#ifndef _rae_3d_Mesh_hpp_
#define _rae_3d_Mesh_hpp_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "rae/link.hpp"



//TODO import cpp.glm.glm
//using glm
//TODO import cpp.GL.glew

// using keyword is TODO
#include "glm/glm.hpp"
// using glm

//TODO private import:
// priv import GL.glew
#include "GL/glew.hpp"



class Mesh
{public:
	
	//-------------Rae boilerplate code-------------
		
	//link management:

	void _rae_link(rae::link<Mesh>& a_link)
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
			_rae_link_list = new rae::LinkList<Mesh>(this, &a_link);
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

	rae::LinkList<Mesh>* _rae_link_list;

	//-------------end Rae boilerplate code-------------


	Mesh(); // line: 469
	~Mesh(); // line: 473
public: 
	
	/*
	func init()
	{
		id = 32
	}

	func init(int set_id)
	{
		id = set_id
	}
	
	func free
	{
		#Semicolons don't work at the moment, so don't use them

		glDeleteBuffers(1, vertexBufferID) # in C++: glDeleteBuffers(1, &vertexBufferID);
		glDeleteBuffers(1, uvBufferID)
		glDeleteBuffers(1, normalBufferID)
		glDeleteBuffers(1, indexBufferID)
	}

	int id

*/
	
	/*
	prop int id { get; set : priv }

	prop int id2
	{
		get
		set : priv
	}

	prop int id3
	{
		get return id3
		set id3 = set : priv
	}

	prop int id4
	{
		get
		{
			return id4 + something
		}
		set
		{
			id4 = cos(set)
		}
	}
	*/
	
	void generateBox();
	
	void createVBOs();
	
	void render(uint32_t set_shader_program_id); // line: 428
	protected: 
	std::vector<glm::vec3 > vertices; // line: 465
	std::vector<glm::vec2 > uvs; // line: 466
	std::vector<glm::vec3 > normals; // line: 467
	std::vector<uint16_t> indices; // line: 468
	
	uint32_t vertexBufferID; // line: 470
	uint32_t uvBufferID; // line: 471
	uint32_t normalBufferID; // line: 472
	uint32_t indexBufferID;
};


#endif // _rae_3d_Mesh_hpp_

