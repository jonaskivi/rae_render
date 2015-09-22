// this file is automatically created from Rae programming language module:
///Users/joonaz/Dropbox/jonas/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Entity
#ifndef _rae_3d_Entity_hpp_
#define _rae_3d_Entity_hpp_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "rae/link.hpp"




class ComponentIndex
{public:
	
	//-------------Rae boilerplate code-------------
		
	//link management:

	void _rae_link(rae::link<ComponentIndex>& a_link)
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
			_rae_link_list = new rae::LinkList<ComponentIndex>(this, &a_link);
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

	rae::LinkList<ComponentIndex>* _rae_link_list;

	//-------------end Rae boilerplate code-------------


	~ComponentIndex(); // line: 24
public: 
	ComponentIndex(int32_t set_type, int32_t set_id); // line: 22
	/*TODO operator overloading == < <= >= > from one func
	func (int) operatorEquals (ref ComponentIndex other)
	{
		if(other.type == type && other.id == id)
			return 0 # TODO or something...
		return false # todo
	}
	*/
	
	// Components are identified with 1. component type index, 2. component id index
	int32_t type; // line: 23
	int32_t id;
};




class Entity
{public:
	
	//-------------Rae boilerplate code-------------
		
	//link management:

	void _rae_link(rae::link<Entity>& a_link)
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
			_rae_link_list = new rae::LinkList<Entity>(this, &a_link);
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

	rae::LinkList<Entity>* _rae_link_list;

	//-------------end Rae boilerplate code-------------


	public: int32_t id();
protected: 
	void id(int32_t set);
	int32_t m_id; // line: 32
	
public: 
	Entity(int32_t set_id); // line: 31
	~Entity();
	
	void addComponent(int32_t set_type, int32_t set_id); // line: 43
	// let ?
	//func (ref[ComponentIndex]) components { return m_components }
	
protected: 
	std::vector<ComponentIndex > m_components;
};




#endif // _rae_3d_Entity_hpp_

