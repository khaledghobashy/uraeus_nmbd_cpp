
#include "helpers.hpp"


MatrixAssembler::MatrixAssembler(Indicies& rows, Indicies& cols, Container& container)
    :
        rows(rows), cols(cols), container(container)
    {
        container.reserve(rows.size());
    };

void MatrixAssembler::Assemble(SparseBlock& matrix, DataBlocks& data)
{

    container.clear();

    int row_counter = 0;
    int col_counter = 0;
    Eigen::Index prev_rows_size = 0;
    Eigen::Index prev_cols_size = 0;
    Eigen::Index m = 0;
    Eigen::Index n = 0;
    const Eigen::Index nnz = rows.size();

    //std::cout << "Starting Main for loop" << "\n";
    for (Eigen::Index v = 0; v < nnz; v++)
    {
        auto& vi = rows[v];
        auto& vj = cols[v];
        auto& mat_block = data[v]; 

        if (vi != row_counter)
        {
            row_counter += 1;
            prev_rows_size += m;
            prev_cols_size  = 0;
        }

        m = mat_block.rows();
        n = mat_block.cols();

        prev_cols_size = 7 * (vj/2) ;
        if (n == 4) {prev_cols_size += 3;};
        
        for (Eigen::Index j = 0; j < n; j++)
        {
            for (Eigen::Index i = 0; i < m; i++)
            {
                auto& value = mat_block(i, j);
                if (std::abs(value) > 1e-5)
                {
                    container.emplace_back(
                        Eigen::Triplet<double>(prev_rows_size+i, prev_cols_size+j, value));
                }
            }
        }
    }
    matrix.setFromTriplets(container.begin(), container.end());
    matrix.makeCompressed();
};




double derivative(std::function<double(double)> func, double x, int order = 1)
{
    using namespace boost::math::tools;

    if(order == 1)
    {
        return finite_difference_derivative(func, x);
    }
    else
    {
        return derivative([&func](double y) { return finite_difference_derivative(func, y); }, x, order-1);
    };

};


void SparseAssembler(SparseBlock& mat, Indicies& rows, Indicies& cols, DataBlocks& data)
{
    //Declaring Local Variables

    int row_counter = 0;
    int col_counter = 0;
    int prev_rows_size = 0;
    int prev_cols_size = 0;
    int m = 0;
    int n = 0;
    const Eigen::Index nnz = rows.size();

    std::vector<Eigen::Triplet<double>> container;
    container.reserve(nnz);

    //std::cout << "Starting Main for loop" << "\n";
    for (Eigen::Index v = 0; v < nnz; v++)
    {
        auto& vi = rows[v];
        auto& vj = cols[v];
        auto& mat_block = data[v]; 

        if (vi != row_counter)
        {
            row_counter += 1;
            prev_rows_size += m;
            prev_cols_size  = 0;
        }

        m = mat_block.rows();
        n = mat_block.cols();

        prev_cols_size = 7 * (vj/2) ;
        if (n == 4) {prev_cols_size += 3;};
        //if (n == 3) { prev_cols_size = 7*(vj/2);}
        //else { prev_cols_size = 7*(vj/2) + 3;};
        
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                auto& value = mat_block(i, j);
                if (std::abs(value) > 1e-5)
                {
                    container.emplace_back(
                        Eigen::Triplet<double>(prev_rows_size+i, prev_cols_size+j, value));
                }
            }
        }
    }
    mat.setFromTriplets(container.begin(), container.end());
    mat.makeCompressed();
};



void DenseAssembler(Eigen::MatrixXd& mat, Indicies& rows, Indicies& cols, DataBlocks& data)
{
    //std::cout << "Declaring Local Variables" << "\n";

    int row_counter = 0;
    int col_counter = 0;
    int prev_rows_size = 0;
    int prev_cols_size = 0;
    const int nnz = rows.size();
    int vi, vj, m, n;
    double value;

    //std::vector<Eigen::Triplet<double>> container;
    //container.reserve(nnz);

    //std::cout << "Starting Main for loop" << "\n";
    for (size_t v = 0; v < nnz; v++)
    {
        //std::cout << "row = " << rows[v] << " : cols = " << cols[v] << "\n" << data[v] << "\n\n";
        //std::cout << "loop v = " << v << "\n";
        vi = rows[v];
        vj = cols[v];
        //std::cout << "vi = " << vi << "\n";
        //std::cout << "vj = " << vj << "\n";

        if (vi != row_counter)
        {
            //std::cout << "if vi != row_counter " << "\n";
            row_counter += 1;
            prev_rows_size += m;
            prev_cols_size  = 0;
            //std::cout << "row_counter = " << row_counter << "\n";
            //std::cout << "prev_rows_size = " << prev_rows_size << "\n";
            //std::cout << "prev_cols_size = " << prev_cols_size << "\n";
            //std::cout << "Exit if" << "\n";
        }

        //std::cout << "setting m and n " << "\n";
        m = data[v].rows();
        //std::cout << "data[v].rows() = " << data[v].rows() << "\n";
        n = data[v].cols();
        //std::cout << "m = " << m << "\n";
        //std::cout << "n = " << n << "\n";

        if (n == 3)
        {
            //std::cout << "if n == 3" << "\n";
            prev_cols_size = 7*(vj/2);
            //std::cout << "prev_cols_size = " << prev_cols_size << "\n";
        }
        else
        {
            //std::cout << "if n!= 3" << "\n";
            prev_cols_size = 7*(vj/2) + 3;
            //std::cout << "prev_cols_size = " << prev_cols_size << "\n";
        }
        
        //std::cout << "Entring for (size_t i = 0; i < m; i++)" << "\n";
        for (size_t i = 0; i < m; i++)
        {
            //std::cout << "i = " << i << "\n";
            //std::cout << "Entring for (size_t j = 0; j < n; j++)" << "\n\n";
            for (size_t j = 0; j < n; j++)
            {
                value = data[v](i,j);
                //std::cout << "j = " << j << "\n";
                if (std::abs(value) > 1e-5)
                {
                    //std::cout << "if (std::abs(data[v](i,j))>1/1000) = " << std::abs(data[v](i,j)) << "\n";
                    //std::cout << "Inserting Data " << "\n";
                    //std::cout << "mat(" << prev_rows_size+i << "," << prev_cols_size+j << ") = " << data[v](i,j) << "\n";
                    mat(prev_rows_size+i, prev_cols_size+j) = value;
                    //std::cout << "Done" << "\n";
                }
            }
        }
    }
};



