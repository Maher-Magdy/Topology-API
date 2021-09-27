# Topology-API
This projects is an API to Provide the functionality to access, manage and store device topologies.
it contains 3 classes :
class memory_controls which have static methods to execute the required functionalities.
class topology : can store topology data and has basic get ,set methods.
class component : can store devices data and has basic get ,set methods .
class memory_controls has six methods : { readJSON() writeJSON() queryTopologies() deleteTopology() queryDevices() queryDevicesWithNetlistNode() }
All explained in the code files.


Installation :
The API is written entirely in C++ utilizing two open source libraries : nlohmann json.hpp(for working with json files and format) and gtest.h (for code automated testing) .
 no further dependencies are required to use the API.
