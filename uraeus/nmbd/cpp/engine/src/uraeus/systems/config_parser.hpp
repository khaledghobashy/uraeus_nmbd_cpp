#pragma once

#include <map>
#include <vector>
#include <variant>
#include <any>
#include <functional>

#include <eigen/Eigen/Dense>
#include <eigen/Eigen/Eigen>

#include "uraeus/geometries.hpp"

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>


using namespace rapidjson;

typedef std::map<std::string, std::variant<Eigen::MatrixXd, double, cylinder_geometry> > container;


rapidjson::Document readJSONFile (std::string fileName);

Eigen::MatrixXd array(const rapidjson::Value& array);

container constructInputs(const rapidjson::Value& inputsObject);
void constructConfiguration(std::string fileName);
void constructEvaluations(container& inputsContainer, const Value& evalObject);

//constructors["array"] = array;
//constructors
