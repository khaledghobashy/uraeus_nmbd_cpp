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


#include "configuration.hpp"


// Constructors map mapping between the constructors' names from the JSON file
// interface and pointers to the construction methods responsible for the 
// objects' construction.
std::map<std::string, void (ConfigurationAssembler::*)(rapidjson::Value::ConstMemberIterator)> Constructors
{
    {"Cylinder_Geometry", &ConfigurationAssembler::Cylinder_Geometry},
    {"Triangular_Prism", &ConfigurationAssembler::Triangular_Prism},
    {"Composite_Geometry", &ConfigurationAssembler::Composite_Geometry},
    {"array", &ConfigurationAssembler::Array},
    {"Mirrored", &ConfigurationAssembler::Mirrored},
    {"Oriented", &ConfigurationAssembler::Oriented},
    {"Centered", &ConfigurationAssembler::Centered},
    {"getattribute", &ConfigurationAssembler::getattribute}

};


// ConfigurationAssembler Class Constructors
// =========================================
ConfigurationAssembler::ConfigurationAssembler()
    :
        config_map()
{
    // The default constructor only initializes the "config_map" container in
    // the initailizer list.

    //std::cout << "\nCalling ConfigurationAssembler::ConfigurationAssembler\n";
    //std::cout << "\n";
};
ConfigurationAssembler::ConfigurationAssembler(const std::string& fileName)
    :
        config_map()
{
    // This constructor takes in the .json file and passes the file to its member
    // method "constructFromJSON(fileName)".

    this->constructFromJSON(fileName);
    //std::cout << "Calling ConfigurationAssembler::ConfigurationAssembler(fileName)" << std::endl;
};


// JSON Document Handlers
// ======================
void ConfigurationAssembler::constructFromJSON(const std::string& fileName)
{
    rapidjson::Document document = this->readFile(fileName);
    this-> constructConfiguration(document);
};

rapidjson::Document ConfigurationAssembler::readFile(const std::string& fileName)
{
    // loading the fileName into a file variable of type ifstream
    std::ifstream file{fileName};

    // checking if the file was opened correctly and terminating otherwise
    if (!file.is_open())
        std::cerr << "Could not open file (%s) for reading!\n" << fileName;
        // std::terminate();

    // loading the file instance into rapidjson IStreamWrapper and constructing a
    // "document" from the acquired stream.
    rapidjson::IStreamWrapper isw{file};
    rapidjson::Document document {};
    document.ParseStream(isw);

    return document;
};


// -------------------------------------------------------------------------
//                           Configuration Assembler
// -------------------------------------------------------------------------
void ConfigurationAssembler::constructConfiguration(rapidjson::Document& document)
{
    const Value& inputsObject = document["user_inputs"].GetObject();
    const Value& evalObject   = document["evaluations"].GetObject();
    const Value& outObject    = document["outputs"].GetObject();
    
    std::cout << "Constructing Inputs!" << "\n";
    constructInputs(inputsObject);
    std::cout << "Inputs Constructed!" << "\n";

    std::cout << "Constructing Helpers!" << "\n";
    constructEvaluations(evalObject);
    std::cout << "Helpers Constructed!" << "\n";
    
    std::cout << "Evaluating Outputs!" << "\n";
    constructOutputs(outObject);
    std::cout << "Outputs Constructed!" << "\n";
};


// -------------------------------------------------------------------------
//                              Inputs Assembler
// -------------------------------------------------------------------------
void ConfigurationAssembler::constructInputs(const rapidjson::Value& inputsObject)
{
    for (Value::ConstMemberIterator itr = inputsObject.MemberBegin();
        itr != inputsObject.MemberEnd(); ++itr)
    {
        const Value& value = itr->value;

        if (value.IsObject())
        {
            std::string constructor_ = value["constructor"].GetString();
            constructObject(constructor_, itr);
        }

        else if (value.IsNumber())
        {
            std::string elementName = itr->name.GetString();
            config_map[elementName] = value.GetDouble();
        }
    }

};

// -------------------------------------------------------------------------
//                      Intermediat Evaluations Assembler
// -------------------------------------------------------------------------
void ConfigurationAssembler::constructEvaluations(const rapidjson::Value& evalObject)
{
    for (Value::ConstMemberIterator itr = evalObject.MemberBegin();
        itr != evalObject.MemberEnd(); ++itr)
    {
        std::string constructor_ = itr->value["constructor"].GetString();
        constructObject(constructor_, itr);
    };
};

// -------------------------------------------------------------------------
//                              Outputs Assembler
// -------------------------------------------------------------------------
void ConfigurationAssembler::constructOutputs(const rapidjson::Value& outObject)
{
    for (Value::ConstMemberIterator itr = outObject.MemberBegin();
        itr != outObject.MemberEnd(); ++itr)
    {
        //std::cout << "In For Loop == True" << "\n";
        const Value& key   = itr->name;
        const Value& value = itr->value;

        const char* elementName = key.GetString();

        if (value.IsObject())
        {
            std::string constructor_ = itr->value["constructor"].GetString();
            constructObject(constructor_, itr);            
        }

        else if(value.IsString())
        {
            std::string arg_s = outObject[elementName].GetString();
            try
            {
                config_map[elementName] = config_map.at(arg_s);
                //std::cout << elementName << " == " << arg_s << std::endl;
            }
            catch (const std::out_of_range e)
            {
                std::cout << e.what() << std::endl;
                std::cout << "Argument not initialized! " << arg_s << std::endl;
            }
            
        };
    };
};


// Generic Object Constructor
// ==========================
void ConfigurationAssembler::constructObject(const std::string& constructor_, 
                                            rapidjson::Value::ConstMemberIterator object)
{
    static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };

    const char* elementType = kTypeNames[object->value.GetType()];
    //printf("Type of member is %s\n", elementType);

    try { (this->*Constructors.at(constructor_))(object); }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        std::cerr << "Constructor " << constructor_ << " has no mapped construction method!" << "\n";
    }
};


// ===========================================================================
//                            Construction Methods
// ===========================================================================

// ----------------------------------------------------------------------------
// Vectors and Matricies Constructor
// ---------------------------------
void ConfigurationAssembler::Array(rapidjson::Value::ConstMemberIterator item)
{

    const rapidjson::Value& array = item->value["args"];
    std::string elementName = item->name.GetString();
    
    //std::cout << "array : " << elementName << "\n";
    //printf("array size = %d\n", array.Size());
    
    // Checking the size of the array to construct the appropriate vector.
    // (3x1) Vector case:
    if (array.Size() == 3)
    {
        //std::cout << "config_map.size() = " << config_map.size() << std::endl;
        //std::cout << "Constructing Vector3d " << elementName << "\n" << "\n";
        // Declaring a (3x1) vector v of type double.
        Eigen::Vector3d v;

        // Populizing the vector with the acquired array values.
        for (SizeType i = 0; i < array.Size(); i++)
        {
            //std::cout << "config_map.size() = " << config_map.size() << std::endl;

            auto x = array[i].GetDouble();
            //std::cout << x << std::endl;
            v[i] = x; // Getting the array value as double
        };

        //std::cout << elementName << "\n" << v << std::endl;
        //config_map.insert(std::pair<std::string,Eigen::Vector3d>(elementName,v)); 
        config_map[elementName] = v;
        //std::cout << "Constructed Array " << elementName << "\n" << v << "\n";
    }
    
    // Checking the size of the array to construct the appropriate vector.
    // (4x1) Quaternion case:
    else if (array.Size() == 4)
    {
        Eigen::Vector4d v;

        for (SizeType i = 0; i < array.Size(); i++)
        {
            v[i] = array[i].GetDouble();
        };
        this->config_map[elementName] = v;
    }

    // Checking the size of the array to construct the appropriate vector.
    // (3x3) Tensor case:
    else if (array.Size() == 9)
    {
        Eigen::Matrix3d v;

        for (SizeType i = 0; i < 3; i++)
        {
            v(i,0) = array[3*i + 0].GetDouble();
            v(i,1) = array[3*i + 1].GetDouble();
            v(i,2) = array[3*i + 2].GetDouble();
        };
        this->config_map[elementName] = v;
    }

};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Cylinder_Geometry Constructor
// -----------------------------
void ConfigurationAssembler::Cylinder_Geometry(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();

    std::string p1_name = value[0].GetString();
    std::string p2_name = value[1].GetString();
    std::string ro_name = value[2].GetString();

    Eigen::Vector3d p1;
    Eigen::Vector3d p2;
    double ro;

    this->get(p1_name, p1);
    this->get(p2_name, p2);
    this->get(ro_name, ro);

    auto geo = cylinder_geometry(p1, p2, ro);

    config_map[elementName] = geo;

    config_map[elementName + std::string(".R")] = geo.R;
    config_map[elementName + std::string(".P")] = geo.P;
    config_map[elementName + std::string(".J")] = geo.J;
    config_map[elementName + std::string(".m")] = geo.m;

    //std::cout << elementName << "\n";
    //std::cout << geo.R << "\n";
    //std::cout << geo.P << "\n";
    //std::cout << geo.m << "\n";
    //std::cout << geo.J << "\n\n";

};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Triangular_Prism Constructor
// -----------------------------
void ConfigurationAssembler::Triangular_Prism(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();

    //std::cout << "triangular_prism" << "\n";
    //printf("Type of member %s is %s\n", elementName, elementType);

    std::string p1_name = value[0].GetString();
    std::string p2_name = value[1].GetString();
    std::string p3_name = value[2].GetString();
    std::string th_name = value[3].GetString();

    Eigen::Vector3d p1;
    Eigen::Vector3d p2;
    Eigen::Vector3d p3;
    double th;

    this->get(p1_name, p1);
    this->get(p2_name, p2);
    this->get(p3_name, p3);
    this->get(th_name, th);

    auto geo = triangular_prism(p1, p2, p3, th);

    config_map[elementName] = geo;

    config_map[elementName + std::string(".R")] = geo.R;
    config_map[elementName + std::string(".P")] = geo.P;
    config_map[elementName + std::string(".J")] = geo.J;
    config_map[elementName + std::string(".m")] = geo.m;

    //std::cout << elementName << "\n";
    //std::cout << geo.R << "\n";
    //std::cout << geo.P << "\n";
    //std::cout << geo.m << "\n";
    //std::cout << geo.J << "\n\n";

};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Composite_Geometry Constructor
// -----------------------------
void ConfigurationAssembler::Composite_Geometry(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();

    //std::cout << "Composite_Geometry" << "\n";

    std::vector<geometry> geometries;
    for (unsigned int j=0; j < value.Size(); j++)
    {
        std::string name = value[j].GetString();
        geometry g;
        this->get(name, g); // = std::get<Eigen::MatrixXd>(config_map[name]);
        geometries.push_back(g);
    };

    auto geo = composite_geometry(geometries);

    config_map[elementName] = geo;

    config_map[elementName + std::string(".R")] = geo.R;
    config_map[elementName + std::string(".P")] = geo.P;
    config_map[elementName + std::string(".J")] = geo.J;
    config_map[elementName + std::string(".m")] = geo.m;
    
    //std::cout << elementName << "\n";
    //std::cout << geo.R << "\n";
    //std::cout << geo.P << "\n";
    //std::cout << geo.m << "\n";
    //std::cout << geo.J << "\n\n";

};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Mirrored Relation Constructor
// -----------------------------
void ConfigurationAssembler::Mirrored(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();
    std::string arg = value[0].GetString();

    if ((arg.rfind("P"   , 0) == 0) || (arg.rfind("Pd"  , 0) == 0) || 
        (arg.rfind("Pdd" , 0) == 0) || (arg.rfind("Jbar", 0)) == 0 )
    {
        //std::cout << arg << std::endl;
        config_map[elementName] = config_map[arg];
    }

    else
    {
        Eigen::Vector3d v;
        this->get(arg, v);
        config_map[elementName] = mirrored(v);
    };
};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Centered Relation Constructor
// -----------------------------
void ConfigurationAssembler::Centered(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();

    //std::cout << "Centered" << "\n";
    //printf("Type of member %s is %s\n", elementName, elementType);

    std::vector<Eigen::Vector3d> args_v;
    for (unsigned int j=0; j < value.Size(); j++)
    {
        std::string name = value[j].GetString();
        Eigen::Vector3d v;
        this->get(name, v);
        args_v.push_back(v);
    };

    config_map[elementName] = centered(args_v);
};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Oriented Relation Constructor
// -----------------------------
void ConfigurationAssembler::Oriented(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();

    //std::cout << "Oriented" << "\n";
    //printf("Type of member %s is %s\n", elementName, elementType);

    std::vector<Eigen::Vector3d> args_v;
    for (unsigned int j=0; j < value.Size(); j++)
    {
        std::string name = value[j].GetString();
        Eigen::Vector3d v;
        this->get(name, v);
        args_v.push_back(v);
    };

    config_map[elementName] = oriented(args_v);
};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// getattribute Relation Constructor
// ---------------------------------
void ConfigurationAssembler::getattribute(rapidjson::Value::ConstMemberIterator item)
{
    const rapidjson::Value& value = item->value["args"];
    std::string elementName = item->name.GetString();

    std::string key = value[0].GetString() + std::string(".") + value[1].GetString();

    try
    {
        config_map[elementName] = config_map.at(key);
        //std::cout << key << std::endl;
        //std::cout << elementName << " = " << key << std::endl;
    }
    catch (const std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Argument (" << key << ") is not initialized!\n";
    }

};


/*
===============================================================================
                            Object Getters Methods
===============================================================================
*/

void ConfigurationAssembler::get(const std::string& name, Eigen::Vector3d& value)
{
    //std::cout << "Getting Vector3d" << "\n";
    //std::cout << "Name = " << name << "\n";
    value = std::get<Eigen::Vector3d>(this->config_map[name]);
};

void ConfigurationAssembler::get(const std::string& name, Eigen::Vector4d& value)
{
    //std::cout << "Getting Vector4d" << "\n";
    //std::cout << "Name = " << name << "\n";
    value = std::get<Eigen::Vector4d>(this->config_map[name]);
};


void ConfigurationAssembler::get(const std::string& name, Eigen::Matrix3d& value)
{
    //std::cout << "Getting Matrix3d" << "\n";
    //std::cout << "Name = " << name << "\n";
    value = std::get<Eigen::Matrix3d>(this->config_map[name]);
};


void ConfigurationAssembler::get(const std::string& name, double& value)
{
    //std::cout << "Getting double" << "\n";
    //std::cout << "Name = " << name << "\n";
    value = std::get<double>(this->config_map[name]);
};


void ConfigurationAssembler::get(const std::string& name, geometry& value)
{
    //std::cout << "Getting geometry" << "\n";
    //std::cout << "Name = " << name << "\n";
    value = std::get<geometry>(this->config_map[name]);
};

void ConfigurationAssembler::get(const std::string& name, std::function<double(double)>& value)
{ };

void ConfigurationAssembler::get(const std::string& name, std::function<Eigen::Vector3d(double)>& value)
{ };
