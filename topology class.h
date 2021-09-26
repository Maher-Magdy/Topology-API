
#pragma once
#include <iostream>
#include <string>
#include <fstream>
//#include <iomanip>
//#include <cstdlib>
//#include <sstream>
//#include <memory>
#include "json.hpp"

using json = nlohmann::json;


class Topology {
private:
    // the actual topology data

public:
    //constructor
    Topology();
    //static functions for memory managament
    static void readJson(std::string FileName);
    static std::string writeJSON(std::string TopologyID, std::string FileName);
    //static TopologyList queryTopologies();
    //static string deleteTopology(std::string TopologyID);
    //static DeviceList queryDevices(std::string TopologyID);
    //static DeviceList queryDevicesWithNetlistNode(std::string TopologyID, std::string NetlistNodeID);

    //destructor
    ~Topology();

};


