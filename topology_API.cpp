#include "topology_API.h"

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


//static members
std::vector<topology>  memory_controls::topology_list;

//constructor
memory_controls::memory_controls(){}
//destructor
memory_controls::~memory_controls(){}

//static functions for memory managament
 topology memory_controls::readJson(std::string FileName)
{
	json parsed_topology;
	topology result;
	try
	{
		//read json
		std::ifstream infile(FileName);//open json file	
		infile >> parsed_topology; //copy file to variable
		infile.close(); //close file

		
		//set the result topology to json data
		result.set_data(parsed_topology);

		//insert the topology object to topology list
		topology_list.push_back(result);
		
	}
	catch (const std::exception&)
	{

	}
	
	return result;
}


 void memory_controls::writeJSON(std::string TopologyID, std::string FileName)
 {
	
	
	 json found_json;
	 //search for the topology
	 for (int i =0;i< topology_list.size();i++)
	 {
		 if(topology_list[i].get_data()["id"]==TopologyID)
		 
		 {
			 found_json = topology_list[i].get_data();
			 //write to a json file
			 std::ofstream outfile(FileName);
			 outfile << std::setw(4) << found_json << std::endl;
			 outfile.close();
			 return;
		 }
		
	 }	 
	
 }

 //returns a vector of object topology containing all the topologies in memory
 std::vector<topology> memory_controls::queryTopologies()
 {
	 std::vector <topology>result;
	 //search for the topology
	 for (int i = 0; i < topology_list.size(); i++)
	 {
		 result.push_back(topology_list[i]);
		 
	 }
	 return result;
 }

 void memory_controls::deleteTopology(std::string TopologyID)
 {
	
	 int i = 0;
	 for (auto it = topology_list.begin(); it != topology_list.end(); it++) 
	 {
		 if (topology_list[i].get_data()["id"] == TopologyID)
		 {
			 topology_list.erase(it);
			 return;
		 }
		 i++;
	 }

 }

 //
 std::vector<component> memory_controls::queryDevices(std::string TopologyID)
 {
	 json found_json;
	 component result;
	 std::vector<component> result_vector;
	 bool no_component_found = 1;
	 //search for the topology
	 for (int i = 0; i < topology_list.size(); i++)
	 {
		 if (topology_list[i].get_data()["id"] == TopologyID)
		 {
			 found_json = topology_list[i].get_data()["components"];			 
			 no_component_found = 0;
			 break;
		 }
		 
	 }
	 //found
	 int i = 0;
	 for (auto it = found_json.begin(); it != found_json.end(); it++)
	 {
		 result.set_data(found_json[i]);
		 result_vector.push_back(result);
		 i++;
	 }
	 
	 if (no_component_found) { result_vector.push_back(result); }//in case of null
	 return result_vector;

 }
 
 //
 std::vector<component> memory_controls::queryDevicesWithNetlistNode(std::string TopologyID, std::string NetlistNodeID)
 {
	 json found_json;
	 component result;
	 std::vector<component> result_vector;
	 bool no_component_found = 1;
	 //search for the topology
	 for (int i = 0; i < topology_list.size(); i++)
	 {
		 if (topology_list[i].get_data()["id"] == TopologyID)
		 {
			 found_json = topology_list[i].get_data()["components"];			
		 }		 		 
	 }

	 //search through all components with net list node ID
	 std::string result_string;
	 int i = 0;
	 for (auto it = found_json.begin(); it != found_json.end(); it++)
	 {
		 
		 //store the json in string
		 
		 //write
		 std::ofstream outfile("temp.txt");
		 outfile << found_json[i]["netlist"] << std::endl;
		 outfile.close();

		 //read 	 
		 std::ifstream infile("temp.txt");//open  file	
		 infile >> result_string; //copy file to a variable
		 infile.close(); //close file

		 //search string
		 size_t found = result_string.find(NetlistNodeID);
		 if (found != std::string::npos)
		 {
			 //found
			 no_component_found = 0;
			 result.set_data(found_json[i]);
			 result_vector.push_back(result);
		 }

		 //last increment i
		 i++;
	 }
	

	 //delete temp.txt file
	 remove("temp.txt");
	 if (no_component_found) { result_vector.push_back(result); }//in case of null
	 return result_vector;

 }

 //json parsed_topology = json::parse(file_data);
	//parsed_topology.value("id","");

