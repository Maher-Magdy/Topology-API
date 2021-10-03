

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
    static topology find(std::string TopologyID, std::vector<topology> topology_list);
};
