#include "memory  controls.h"

//for class topology
//constructor
topology::topology() {}
//destructor
topology::~topology() {}
void topology::set_data(json data)
{
	this->topology_data = data;
}
json topology::get_data()
{
	return this->topology_data;
}
topology topology::find(std::string TopologyID, std::vector<topology> topology_list)
{
	topology found_topology;
	//search for the topology
	for (int i = 0; i < topology_list.size(); i++)
	{
		if (topology_list[i].get_data()["id"] == TopologyID)
		{
			return found_topology = topology_list[i];	
		}
	}
	//if not found	
	found_topology.set_data("not found");
	return found_topology;
}