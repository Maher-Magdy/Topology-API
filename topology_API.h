#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <iomanip>
//#include <iomanip>
//#include <cstdlib>
//#include <sstream>
//#include <memory>
#include "json.hpp"

using json = nlohmann::json;


class topology
{
private:
    // the actual topology data
    json topology_data;

public:
    //constructor
    topology();
    //destructor
    ~topology();
    void set_topology(json data);
    json get_topology_data();
};

class memory_controls {
private:
    //a list of all topologies in memory
    static std::vector<topology> topology_list;
   
public:
    //constructor
    memory_controls();
    //static functions for memory managament
    static void readJson(std::string FileName);
    static void writeJSON(std::string TopologyID, std::string FileName);
    //static TopologyList queryTopologies();
    //static string deleteTopology(std::string TopologyID);
    //static DeviceList queryDevices(std::string TopologyID);
    //static DeviceList queryDevicesWithNetlistNode(std::string TopologyID, std::string NetlistNodeID);

    //destructor
    ~memory_controls();

};
