
#include <uraeus/systems/configuration.hpp>


Eigen::MatrixXd array(const rapidjson::Value& array)
{
    // Checking the size of the array to construct the appropriate vector.
    // (3x1) Vector case:
    if (array.Size() == 3)
    {
        // Declaring a (3x1) vector v of type double.
        Eigen::Vector3d v;

        // Populizing the vector with the acquired array values.
        for (SizeType i = 0; i < array.Size(); i++)
        {
            v[i] = array[i].GetDouble(); // Getting the array value as double
        };
        return v;
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
        return v;
    }
    
    // Checking the size of the array to construct the appropriate vector.
    // (3x3) Tensor case:
    else if (array.Size() == 9)
    {
        Eigen::Matrix3d v;

        for (SizeType i = 0; i < array.Size(); i++)
        {
            v(i/3,i) = array[i].GetDouble();
        };
        return v;
    }

};


ConfigurationAssembler::ConfigurationAssembler(std::string fileName)
{
    rapidjson::Document document = this->readFile(fileName);

    const Value& inputsObject = document["user_inputs"].GetObject();
    const Value& evalObject   = document["evaluations"].GetObject();
    const Value& outObject    = document["outputs"].GetObject();

    this->constructInputs(inputsObject);

    std::cout << "Performing the evaluations!" << "\n";
    this->constructEvaluations(evalObject);
    std::cout << "Evaluating Outputs!" << "\n";
    this->constructOutputs(outObject);

};

rapidjson::Document ConfigurationAssembler::readFile(std::string fileName)
{
    std::ifstream file{fileName};
    if (!file.is_open())
    {
        std::cerr << "Could not open file (%s) for reading!\n" << fileName;
    }

    rapidjson::IStreamWrapper isw{file};

    rapidjson::Document document {};
    document.ParseStream(isw);

    return document;
};

void ConfigurationAssembler::constructInputs(const rapidjson::Value& inputsObject)
{
    static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };


    auto& config_map = this-> config_map;

    for (Value::ConstMemberIterator itr = inputsObject.MemberBegin();
        itr != inputsObject.MemberEnd(); ++itr)
    {
        const Value& key   = itr->name;
        const Value& value = itr->value;

        const char* elementName = key.GetString();
        const char* elementType = kTypeNames[value.GetType()];

        if (value.IsObject())
        {

            if (inputsObject[elementName]["constructor"] == "array")
            {
                const Value& array_values = inputsObject[elementName]["args"];
                auto v = array(array_values);
                config_map[elementName] = v;
                //printf("Type of member %s is %s\n", elementName, elementType);
                //std::cout << v << "\n\n";
            }
            
        }

        else if (value.IsNumber())
        {
            //printf("Type of member %s is %s\n", elementName, elementType);
            //std::cout << value.GetDouble() << "\n\n";
            config_map[elementName] = value.GetDouble();
        }
    }

};


void ConfigurationAssembler::constructEvaluations(const rapidjson::Value& evalObject)
{
    auto& config_map = this-> config_map;

    static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };

    for (Value::ConstMemberIterator itr = evalObject.MemberBegin();
        itr != evalObject.MemberEnd(); ++itr)
    {
        //std::cout << "In For Loop == True" << "\n";
        const Value& key   = itr->name;
        const Value& value = itr->value;

        const char* elementName = key.GetString();
        const char* elementType = kTypeNames[value.GetType()];

        if (value.IsObject())
        {
            std::string constructor_ = evalObject[elementName]["constructor"].GetString();

            if (constructor_ == "Mirrored")
            {
                //printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args = evalObject[elementName]["args"];
                std::string arg_s = args[0].GetString();

                Eigen::Vector3d arg_v;
                this->get(arg_s, arg_v);

                Eigen::MatrixXd out_v = mirrored(arg_v);

                config_map[elementName] = out_v;
                
                //std::cout << out_v << "\n\n";
            }

            else if (constructor_ == "Centered")
            {
                //std::cout << "Centered" << "\n";
                //printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::vector<Eigen::Vector3d> args_v;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    Eigen::Vector3d v;
                    this->get(name, v);
                    args_v.push_back(v);
                };

                Eigen::MatrixXd out_v = centered(args_v);

                config_map[elementName] = out_v;
                
                //std::cout << out_v << "\n\n";
            }

            else if (constructor_ == "Oriented")
            {
                //std::cout << "Oriented" << "\n";
                //printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::vector<Eigen::Vector3d> args_v;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    Eigen::Vector3d v;
                    this->get(name, v); // = std::get<Eigen::MatrixXd>(config_map[name]);
                    args_v.push_back(v);
                };

                Eigen::MatrixXd out_v = oriented(args_v);

                config_map[elementName] = out_v;
                
                //std::cout << out_v << "\n\n";
            }

            else if (constructor_ == "Cylinder_Geometry")
            {
                //std::cout << "Cylinder_Geometry" << "\n";
                //printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::string p1_name = args_s[0].GetString();
                std::string p2_name = args_s[1].GetString();
                std::string ro_name = args_s[2].GetString();

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

                //std::cout << geo.R << "\n\n";
            }

            else if (constructor_ == "Triangular_Prism")
            {
                //std::cout << "triangular_prism" << "\n";
                //printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::string p1_name = args_s[0].GetString();
                std::string p2_name = args_s[1].GetString();
                std::string p3_name = args_s[2].GetString();
                std::string th_name = args_s[3].GetString();

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
                //std::string s_R = elementName + std::string(".R");
                config_map[elementName + std::string(".R")] = geo.R;
                config_map[elementName + std::string(".P")] = geo.P;
                config_map[elementName + std::string(".J")] = geo.J;
                config_map[elementName + std::string(".m")] = geo.m;
                
                //std::cout << geo.R << "\n\n";
            }

            else if (constructor_ == "Composite_Geometry")
            {
                std::cout << "Composite_Geometry" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];
                std::vector<geometry> geometries;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    geometry g;
                    this->get(name, g); // = std::get<Eigen::MatrixXd>(config_map[name]);
                    geometries.push_back(g);
                };

                auto geo = composite_geometry(geometries);

                config_map[elementName] = geo;
                std::string s_R = elementName + std::string(".R");
                config_map[elementName + std::string(".R")] = geo.R;
                config_map[elementName + std::string(".P")] = geo.P;
                config_map[elementName + std::string(".J")] = geo.J;
                config_map[elementName + std::string(".m")] = geo.m;
                
                std::cout << geo.R << "\n\n";
            }
            
        };
    };
};


void ConfigurationAssembler::constructOutputs(const rapidjson::Value& outObject)
{
    auto& config_map = this-> config_map;

    static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };

    for (Value::ConstMemberIterator itr = outObject.MemberBegin();
        itr != outObject.MemberEnd(); ++itr)
    {
        //std::cout << "In For Loop == True" << "\n";
        const Value& key   = itr->name;
        const Value& value = itr->value;

        const char* elementName = key.GetString();
        const char* elementType = kTypeNames[value.GetType()];

        if (value.IsObject())
        {
            std::string constructor_ = outObject[elementName]["constructor"].GetString();

            if (constructor_ == "Mirrored")
            {
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args = outObject[elementName]["args"];
                std::string arg_s = args[0].GetString();

                if (arg_s.rfind("P", 0) == 0 | 
                    arg_s.rfind("Pd", 0) == 0 | 
                    arg_s.rfind("Pdd", 0) == 0 |
                    arg_s.rfind("Jbar", 0) == 0)
                {
                    std::cout << arg_s << std::endl;
                    Eigen::MatrixXd arg_v;
                    this->get(arg_s, arg_v);
                    config_map[elementName] = arg_v;
                    std::cout << arg_v << "\n\n";
                }

                else
                {
                    Eigen::Vector3d arg_v;
                    this->get(arg_s, arg_v);

                    Eigen::MatrixXd out_v = mirrored(arg_v);

                    config_map[elementName] = out_v;
                    std::cout << out_v << "\n\n";

                }

            }

            else if (constructor_ == "Centered")
            {
                std::cout << "Centered" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = outObject[elementName]["args"];

                std::vector<Eigen::Vector3d> args_v;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    Eigen::Vector3d v;
                    this->get(name, v);
                    args_v.push_back(v);
                };

                Eigen::MatrixXd out_v = centered(args_v);

                config_map[elementName] = out_v;
                
                std::cout << out_v << "\n\n";
            }

            else if (constructor_ == "Oriented")
            {
                std::cout << "Oriented" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = outObject[elementName]["args"];

                std::vector<Eigen::Vector3d> args_v;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    Eigen::Vector3d v;
                    this->get(name, v); // = std::get<Eigen::MatrixXd>(config_map[name]);
                    args_v.push_back(v);
                };

                Eigen::MatrixXd out_v = oriented(args_v);

                config_map[elementName] = out_v;
                
                std::cout << out_v << "\n\n";
            }

            else if (constructor_ == "getattribute")
            {
                std::cout << "getattribute" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                std::string key;

                const Value& args_s = outObject[elementName]["args"];

                key = args_s[0].GetString() + std::string(".") + args_s[1].GetString();

                try
                {
                    config_map[elementName] = config_map.at(key);
                    std::cout << key << std::endl;
                    std::cout << elementName << " = " << key << std::endl;

                }
                catch (const std::out_of_range e)
                {
                    std::cout << e.what() << std::endl;
                    std::cout << "Argument not initialized! " << key << std::endl;
                }
                                
            }
            
        }
        else if(value.IsString())
        {
            std::string arg_s = outObject[elementName].GetString();
            try
            {
                config_map[elementName] = config_map.at(arg_s);
                std::cout << elementName << " == " << arg_s << std::endl;
            }
            catch (const std::out_of_range e)
            {
                std::cout << e.what() << std::endl;
                std::cout << "Argument not initialized! " << arg_s << std::endl;
            }
            
        };
    };
};



void ConfigurationAssembler::get(std::string name, Eigen::Vector3d& value)
{
    //std::cout << "Getting Vector3d" << "\n";
    //std::cout << "Name = " << name << "\n";
    value = std::get<Eigen::MatrixXd>(this->config_map[name]);
};

void ConfigurationAssembler::get(std::string name, double& value)
{
    value = std::get<double>(this->config_map[name]);
};

void ConfigurationAssembler::get(std::string name, Eigen::MatrixXd& value)
{
    value = std::get<Eigen::MatrixXd>(this->config_map[name]);
};

void ConfigurationAssembler::get(std::string name, geometry& value)
{
    value = std::get<geometry>(this->config_map[name]);
};
