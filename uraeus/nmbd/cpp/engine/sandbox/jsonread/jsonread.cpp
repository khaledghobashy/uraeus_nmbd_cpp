#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "uraeus/systems/config_parser.hpp"


void readFile()
{
    using namespace rapidjson;

    std::string fileName = "front_axle.json";

    auto doc = readJSONFile(fileName);

    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    doc.Accept(writer);

    // Output
    // std::cout << buffer.GetString() << std::endl;
    std::cout << doc["information"]["topology_name"].GetString() << std::endl;

    //const Value& array_values = doc["user_inputs"]["Pd_rbr_uca"]["args"];

    //auto v = array(array_values);
    //std::cout << "Array = " << v << std::endl;

    constructConfiguration(fileName);


    // Save content to file
    //std::ofstream outputfile ("rapidjson.json");
    //std::string content(buffer.GetString(), buffer.GetSize());
    //outputfile << content;

}

int main()
{
    readFile();
    return 0;

};
