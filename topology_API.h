#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <stdio.h>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

//
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
    void set_data(json data);
    json get_data();
};
//
class component : public topology
{

}; 

class memory_controls {
private:
    //a list of all topologies in memory
    static std::vector<topology> topology_list;
   
public:
    //constructor
    memory_controls();
    //static functions for memory managament
    static topology readJson(std::string FileName);
    static void writeJSON(std::string TopologyID, std::string FileName);
    static std::vector<topology> queryTopologies();   
    static void deleteTopology(std::string TopologyID);
    static  std::vector<component> queryDevices(std::string TopologyID);
    static  std::vector<component> queryDevicesWithNetlistNode(std::string TopologyID, std::string NetlistNodeID);

    //destructor
    ~memory_controls();
};
