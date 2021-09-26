#include "topology class.h"

//constructor
Topology::Topology()
{}
//static functions for memory managament
void Topology::readJson(std::string FileName)
{

	std::string file_data = "";
	std::string line;
	//File name should have double backshalsh \\
	//reading
	std::ifstream infile(FileName);

	if (infile.is_open())
	{

		while (getline(infile, line))
		{
			file_data += line + "\n";
		}

	}
	infile.close();

	json parsed_topology = json::parse(file_data);
	std::cout<<parsed_topology.value("id","");
}

/*

	//writing
	ofstream outfile(FileName);
	if (outfile.is_open())
	{
		outfile << file_data << endl;
	}
	outfile.close();
*/