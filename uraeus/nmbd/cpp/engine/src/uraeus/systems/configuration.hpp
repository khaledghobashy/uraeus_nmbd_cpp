/*
============================================================================
                            uraeus.nmbd.cpp
============================================================================

Use of this source code is governed by a BSD-style license that can be found
in the LICENSE file at the top level of the distribution.

Authors:
    - Khaled Ghobashy


============================================================================
                                Summary
============================================================================

*/


# pragma once

// Standard Library Includes.
#include <map>
#include <vector>
#include <variant>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <functional>

// 3rd Party Includes.
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>

#include <eigen/Eigen/Eigen>
#include <eigen/Eigen/Dense>

// Local Libraries Includes.
#include <uraeus/numerics/geometries.hpp>
#include <uraeus/numerics/spatial_algebra.hpp>


using namespace rapidjson;

typedef std::variant<double,
                    geometry,
                    Eigen::Vector3d, 
                    Eigen::Vector4d, 
                    Eigen::Matrix3d,
                    std::function<double(double)>,
                    std::function<Eigen::Vector3d(double)> > variants;

typedef std::map<std::string, variants> container;


class ConfigurationAssembler
{

public:
    container config_map;

public:
    ConfigurationAssembler();
    ConfigurationAssembler(const std::string& fileName);
    void constructFromJSON(const std::string& fileName);
    
    void get(const std::string& name, double& value);
    void get(const std::string& name, geometry& value);
    void get(const std::string& name, Eigen::Vector3d& value);
    void get(const std::string& name, Eigen::Vector4d& value);
    void get(const std::string& name, Eigen::Matrix3d& value);
    void get(const std::string& name, std::function<double(double)>& value);
    void get(const std::string& name, std::function<Eigen::Vector3d(double)>& value);

    void constructObject(const std::string& constructor_, 
                        rapidjson::Value::ConstMemberIterator object);

private:
    rapidjson::Document readFile(const std::string& fileName);
    void constructConfiguration(rapidjson::Document& document);
    void constructInputs(const rapidjson::Value& inputsObject);
    void constructEvaluations(const rapidjson::Value& evalObject);
    void constructOutputs(const rapidjson::Value& outObject);


public:

    void Cylinder_Geometry(rapidjson::Value::ConstMemberIterator object);
    void Sphere_Geometry(rapidjson::Value::ConstMemberIterator object);
    void Triangular_Prism(rapidjson::Value::ConstMemberIterator object);
    void Composite_Geometry(rapidjson::Value::ConstMemberIterator object);
    void Array(rapidjson::Value::ConstMemberIterator object);
    void Mirrored(rapidjson::Value::ConstMemberIterator object);
    void Oriented(rapidjson::Value::ConstMemberIterator object);
    void Centered(rapidjson::Value::ConstMemberIterator object);
    void getattribute(rapidjson::Value::ConstMemberIterator object);
    

};


