
#include "topology_API.h"
using namespace std;

int main()
{
	//code for testing
	memory_controls::readJson("topology.json");	
	memory_controls::writeJSON("top1", "done.json");
	std::vector<topology> result=memory_controls::queryTopologies();	
	//memory_controls::deleteTopology("top1");
	std::vector<component> device_result=memory_controls::queryDevices("top11");
	//std::cout << device_result[0].get_data();
	std::vector<component> devices_result = memory_controls::queryDevicesWithNetlistNode("top1","n11");
	std::cout << devices_result[0].get_data();
}