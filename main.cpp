
#include "topology_API.h"
using namespace std;

int main()
{
	//code for testing
	memory_controls::readJson("topology.json");	
	memory_controls::writeJSON("top1", "done.json");
	std::vector<topology> result=memory_controls::queryTopologies();	
	memory_controls::deleteTopology("top1");


}