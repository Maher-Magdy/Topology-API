/*
* this header file contains declarations for 3 main classes :  
* class memory_controls which have static methods to execute the required functionalities
* class topology : can store topology data and has basic get ,set methods
* class component : can store devices data and has basic get ,set methods
*/

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
    //a list (vector) of all topologies in memory
    static std::vector<topology> topology_list;
   
public:
    //constructor
    memory_controls();

    //static functions for memory managament

    //return a topology object conataining the read data from the json file and stores it in memory
    static topology readJson(std::string FileName);
    //write a the topology data into a json file
    static void writeJSON(std::string TopologyID, std::string FileName);
    //returns a vector of object topology containg all the topologies in memory
    static std::vector<topology> queryTopologies();  
    //deletes a topology from memory given its id
    static void deleteTopology(std::string TopologyID);
    //returns a vector of devices in a topology given its id
    static  std::vector<component> queryDevices(std::string TopologyID);
    //returns a vector of devices connected to the same node in a topology given its id as well as the nodeID
    static  std::vector<component> queryDevicesWithNetlistNode(std::string TopologyID, std::string NetlistNodeID);

    //destructor
    ~memory_controls();
};
