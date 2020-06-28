#pragma once

// Standard Library Includes.
#include <vector>
#include <functional>

// 3rd Party Includes.
#include "eigen/Eigen/Dense"
#include "eigen/Eigen/Eigen"
#include "eigen/Eigen/Sparse"
#include "boost/math/tools/numerical_differentiation.hpp"


typedef Eigen::SparseMatrix<double, Eigen::ColMajor> SparseBlock;
typedef std::vector<Eigen::MatrixXd> DataBlocks;
typedef std::vector<Eigen::Triplet<double>> TripletList;

double derivative(std::function<double(double)> func, double x, int order);


class MatrixAssembler
{

public:
    MatrixAssembler() = delete;
    MatrixAssembler(Eigen::Ref<Eigen::VectorXi> rows,
                    Eigen::Ref<Eigen::VectorXi> cols,
                    int dof = 0);

    Eigen::Ref<Eigen::VectorXi> rows;
    Eigen::Ref<Eigen::VectorXi> cols;
    
    TripletList container;

public:

    void AssembleTripletList(DataBlocks& data);
    void Assemble(SparseBlock& matrix);
    void Assemble(SparseBlock& matrix, TripletList& extra_triplets);

};
