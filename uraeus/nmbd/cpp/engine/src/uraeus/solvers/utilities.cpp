
#include "utilities.hpp"

const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "", "", "", "\n");

void ExportResultsCSV(const std::string& name, const std::vector<Eigen::VectorXd>& results)
{
    std::ofstream results_file;
    results_file.open (name + ".csv");
    int i = 0;
    for (auto x : results)
    {
        //results_file << "i";
        //results_file << x.transpose().format(CSVFormat) ;
        i++;
    };
    results_file.close();
    std::cout << "Results Saved as : " << name + ".csv" << "\n";
};


void print_progress(time_point begin, Eigen::Index samples, int i)
{
    const int barWidth = 40;

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    auto pos = barWidth * i/samples ;
    int progress = (double(i)/samples)*100;

    std::cout << "[";
    for (int p = 0; p < barWidth; ++p) 
    {
        if (p < pos) std::cout << "=" ;
        else if (p == pos) std::cout << ">" ;
        else std::cout << " " ;
    }
    std::cout << "] " << progress << "% | CPU Time(s) = " << duration*1e-3 <<" \r" ;
    std::cout.flush() ;
}

