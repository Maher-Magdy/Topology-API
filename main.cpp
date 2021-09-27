#include "topology_API.h"
using namespace std;

//code for manual testing
int main()
{
		
	memory_controls::readJson("topology.json");
	//memory_controls::writeJSON("top1", "done.json");
	vector<topology> result = memory_controls::queryTopologies();
	//memory_controls::deleteTopology("top1");
	vector<component> device_result = memory_controls::queryDevices("top11");
	//cout << device_result[0].get_data();
	vector<component> devices_result = memory_controls::queryDevicesWithNetlistNode("top1", "v");
	//cout << devices_result[1].get_data();
}