#pragma once

// Standard Library Includes.
#include <vector>
#include <functional>

// 3rd Party Includes.
#include "eigen/Eigen/Dense"
#include "eigen/Eigen/Eigen"
#include "eigen/Eigen/Sparse"
#include "eigen/Eigen/SparseLU"
#include "boost/math/tools/numerical_differentiation.hpp"


typedef Eigen::SparseMatrix<double, Eigen::ColMajor> SparseBlock;
typedef std::vector<int> Indicies;
typedef std::vector<Eigen::MatrixXd> DataBlocks;
typedef std::vector<Eigen::Triplet<double>> Container;

double derivative(std::function<double(double)> func, double x, int order);
void SparseAssembler(SparseBlock& mat, Indicies& rows, Indicies& cols, DataBlocks& data);
void DenseAssembler(Eigen::MatrixXd& mat, Indicies& rows, Indicies& cols, DataBlocks& data);


class MatrixAssembler
{

public:
    MatrixAssembler() = delete;
    MatrixAssembler(Indicies& rows, Indicies& cols, Container& container);

    Indicies& rows;
    Indicies& cols;
    Container& container;

public:
    void Assemble(SparseBlock& matrix, DataBlocks& data);

};
