#include "pch.h"
using namespace std;

//create global variables and objects
topology test_topology;
component test_component;
json test_json;
std::vector<component> test_components;
std::vector<topology> test_topologies;

TEST(setup, memory_controls_test)
{
	//assign test.json
//topology
	test_json = json::parse("{\"id\":\"test\",\"components\":[{\"id\":\"res\",\"netlist\":{\"drain\": \"vss\"}}]}");
	test_topology.set_data(test_json);
	test_topologies.push_back(test_topology);
	//devices
	test_json = json::parse("{\"id\":\"res\",\"netlist\":{\"drain\": \"vss\"}}");
	test_component.set_data(test_json);
	test_components.push_back(test_component);

}
TEST(readJson_test, memory_controls_test) 
{
	//test for readJson
	EXPECT_EQ(test_topology.get_data(),memory_controls::readJson("test.json").get_data());
	
}
TEST(writeJson_test, memory_controls_test)
{
	//test for writeJson
	memory_controls::writeJSON("test", "done.json");
	
}
TEST(queryTopologies_test , memory_controls_test)
{
	//test for queryTopologies
	EXPECT_EQ(test_topologies[0].get_data(), memory_controls::queryTopologies()[0].get_data());
	

}
TEST(queryDevices_test , memory_controls_test)
{
	//test for queryDevices
	EXPECT_EQ(test_components[0].get_data(), memory_controls::queryDevices("test")[0].get_data());
	
}
TEST(queryDevicesWithNetlistNode_test , memory_controls_test)
{
	//test for queryDevicesWithNetlistNode
	EXPECT_EQ(test_components[0].get_data(), memory_controls::queryDevicesWithNetlistNode("test", "vss")[0].get_data());
	
}
TEST(deleteTopology_test , memory_controls_test)
{
	//test for deleteTopology
	memory_controls::deleteTopology("test");
}

int main(int argc ,char* argv[])
{
	//run all tests
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();	
}