#include "topology_API.h"

//constructor
topology::topology() {}
//destructor
topology::~topology() {}
void topology::set_topology(json data)
{
	this->topology_data = data;
}
json topology::get_topology_data()
{
	return this->topology_data;
}


//static members
std::vector<topology>  memory_controls::topology_list;

//constructor
memory_controls::memory_controls(){}
//destructor
memory_controls::~memory_controls(){}

//static functions for memory managament
 void memory_controls::readJson(std::string FileName)
{
	 json parsed_topology;
	//read json
	std::ifstream infile(FileName);//open json file	
	infile >> parsed_topology; //copy file to variable
	infile.close(); //close file
	
	topology result;
	//set the result topology to json data
	result.set_topology(parsed_topology);

	//insert the topology object to topology list
	topology_list.push_back(result);
	
	
}


 void memory_controls::writeJSON(std::string TopologyID, std::string FileName)
 {
	
	
	 json found_json;
	 //search for the topology
	 for (int i =0;i< topology_list.size();i++)
	 {
		 if(topology_list[i].get_topology_data()["id"]==TopologyID)
		 //if (topology_list[23].topology_data["id"] == TopologyID)
		 {
			 found_json = topology_list[i].get_topology_data();
			 //write to a json file
			 std::ofstream outfile(FileName);
			 outfile << std::setw(4) << found_json << std::endl;
			 outfile.close();
			 return;
		 }
		
	 }
	 
		
	 
	
	 
	
 }


 //json parsed_topology = json::parse(file_data);
	//parsed_topology.value("id","");

