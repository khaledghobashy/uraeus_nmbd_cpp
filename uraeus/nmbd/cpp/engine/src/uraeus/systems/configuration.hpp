# pragma once

#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <vector>
#include <variant>
#include <map>
#include <any>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>

#include <eigen/Eigen/Eigen>
#include <eigen/Eigen/Dense>

#include <uraeus/geometries.hpp>
#include <uraeus/spatial_algebra.hpp>


using namespace rapidjson;

typedef std::variant<Eigen::MatrixXd, 
                    Eigen::Vector3d, 
                    Eigen::Vector4d, 
                    Eigen::Matrix<double, 3, 3>,
                    std::function<double(double)>,
                    double,
                    geometry> variants;

typedef std::map<std::string, variants> container;



class ConfigurationAssembler
{

public:
    container config_map;

public:
    ConfigurationAssembler(std::string);

    void get(std::string name, Eigen::Vector3d& value);
    void get(std::string name, Eigen::Vector4d& value);
    void get(std::string name, Eigen::Matrix<double, 3, 3>& value);
    void get(std::string name, Eigen::MatrixXd& value);

    void get(std::string name, double& value);
    void get(std::string name, std::function<double(double)>& value);

    void get(std::string name, geometry& value);



private:
    rapidjson::Document readFile(std::string fileName);
    void constructInputs(const rapidjson::Value& inputsObject);
    void constructEvaluations(const rapidjson::Value& evalObject);
    void constructOutputs(const rapidjson::Value& outObject);


};
