#include "component.h"

//for class topology
//constructor
component::component() {}
//destructor
component::~component() {}
void component::set_data(json data)
{
	this->component_data = data;
}
json component::get_data()
{
	return this->component_data;
}
