#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "uraeus/spatial_algebra.hpp"

#include "config_parser.hpp"

using namespace rapidjson;

std::map<std::string, std::any> constructors
{
    {"array", array}
};

//===========================================================================//

rapidjson::Document readJSONFile (std::string fileName)
{
    std::ifstream ifs { fileName };
    if ( !ifs.is_open() )
    {
        std::cerr << "Could not open file (%s) for reading!\n" << fileName;
    }

    rapidjson::IStreamWrapper isw { ifs };

    rapidjson::Document doc {};
    doc.ParseStream( isw );

    return doc;
};

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

void constructConfiguration(std::string fileName)
{
    rapidjson::Document document = readJSONFile(fileName);
    const Value& inputsObject = document["user_inputs"].GetObject();
    const Value& evalObject   = document["evaluations"].GetObject();

    auto dum = constructInputs(inputsObject);

    std::cout << "Performing the evaluations!" << "\n";
    constructEvaluations(dum, evalObject);


}

container constructInputs(const Value& inputsObject)
{
    static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };


    container inputsContainer;

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
                inputsContainer[elementName] = v;
                printf("Type of member %s is %s\n", elementName, elementType);
                std::cout << v << "\n\n";
            }
            
        }

        else if (value.IsNumber())
        {
            printf("Type of member %s is %s\n", elementName, elementType);
            std::cout << value.GetDouble() << "\n\n";
            inputsContainer[elementName] = value.GetDouble();
        }
    }
    //std::cout << inputsContainer["Pd_rbr_uca"] << "\n";

    return inputsContainer;

}

void constructEvaluations(container& inputsContainer, const Value& evalObject)
{
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

            if (evalObject[elementName]["constructor"] == "Mirrored")
            {
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args = evalObject[elementName]["args"];
                std::string arg_s = args[0].GetString();

                Eigen::Vector3d arg_v = std::get<Eigen::MatrixXd>(inputsContainer[arg_s]);
                auto mirroredVector = mirrored(arg_v);

                inputsContainer[elementName] = mirroredVector;
                
                std::cout << mirroredVector << "\n\n";
            }

            else if (evalObject[elementName]["constructor"] == "Centered")
            {
                std::cout << "Centered" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::vector<Eigen::Vector3d> args_v;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    Eigen::Vector3d v = std::get<Eigen::MatrixXd>(inputsContainer[name]);
                    args_v.push_back(v);
                };

                auto mirroredVector = centered(args_v);

                inputsContainer[elementName] = mirroredVector;
                
                std::cout << mirroredVector << "\n\n";
            }

            else if (evalObject[elementName]["constructor"] == "Oriented")
            {
                std::cout << "Oriented" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::vector<Eigen::Vector3d> args_v;
                for (int j=0; j < args_s.Size(); j++)
                {
                    std::string name = args_s[j].GetString();
                    Eigen::Vector3d v = std::get<Eigen::MatrixXd>(inputsContainer[name]);
                    args_v.push_back(v);
                };

                auto mirroredVector = oriented(args_v);

                inputsContainer[elementName] = mirroredVector;
                
                std::cout << mirroredVector << "\n\n";
            }

            else if (evalObject[elementName]["constructor"] == "Cylinder_Geometry")
            {
                std::cout << "Cylinder_Geometry" << "\n";
                printf("Type of member %s is %s\n", elementName, elementType);

                const Value& args_s = evalObject[elementName]["args"];

                std::string p1_name = args_s[0].GetString();
                std::string p2_name = args_s[1].GetString();
                std::string ro_name = args_s[2].GetString();

                Eigen::Vector3d p1 = std::get<Eigen::MatrixXd>(inputsContainer[p1_name]);
                Eigen::Vector3d p2 = std::get<Eigen::MatrixXd>(inputsContainer[p1_name]);
                double ro = std::get<double>(inputsContainer[ro_name]);

                cylinder_geometry geo = cylinder_geometry(p1, p2, ro);

                inputsContainer[elementName] = geo;
                
                std::cout << geo.R << "\n\n";
            }
            
        }

        else if (value.IsNumber())
        {
            printf("Type of member %s is %s\n", elementName, elementType);
            std::cout << value.GetDouble() << "\n\n";
            inputsContainer[elementName] = value.GetDouble();
        }
    }

} 