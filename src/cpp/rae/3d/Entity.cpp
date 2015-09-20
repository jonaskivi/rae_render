// this file is automatically created from Rae programming language module:
//c:\Users\jonaz\Dropbox\jonas\2015\ohjelmointi\rae_render\src/cpp/rae/3d/Entity
#include "Entity.hpp"
; // line: 2


//class ComponentIndex

ComponentIndex::~ComponentIndex()
{ //-------------Rae boilerplate code-------------
	_rae_unlink_all();
	//-------------end Rae boilerplate code-------------


}

ComponentIndex::ComponentIndex(int32_t set_type, int32_t set_id)
: type(0)
, id(0)
{//-------------Rae boilerplate code-------------
	_rae_link_list = nullptr;
	//-------------end Rae boilerplate code-------------


	type = set_type; // line: 9
	id = set_id;
}




//class Entity

int32_t Entity::id() { return m_id; }

void Entity::id(int32_t set) { m_id = set; }

Entity::Entity(int32_t set_id)
: m_id(0)
{ //-------------Rae boilerplate code-------------
	_rae_link_list = nullptr;
	//-------------end Rae boilerplate code-------------


}

Entity::~Entity()
{ //-------------Rae boilerplate code-------------
	_rae_unlink_all();
	//-------------end Rae boilerplate code-------------


}

void Entity::addComponent(int32_t set_type, int32_t set_id)
{
	m_components.emplace_back(set_type, set_id);
}





