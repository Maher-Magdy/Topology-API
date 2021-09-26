
#include "topology_API.h"
using namespace std;

int main()
{
	memory_controls::readJson("topology.json");
	memory_controls::writeJSON("top1", "done.json");
	

}