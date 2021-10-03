
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <stdio.h>
#include <iomanip>
#include "json.hpp"
#include "topology.h"
using json = nlohmann::json;
//
class component 
{
private:
    // the actual topology data
    json component_data;

public:
    //constructor
    component();
    //destructor
    ~component();
    void set_data(json data);
    json get_data();
};
