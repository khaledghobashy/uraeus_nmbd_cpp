
// Standard Library Includes.
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

// 3rd Party Includes.
#include "eigen/Eigen/Dense"

typedef std::chrono::steady_clock::time_point time_point;


void ExportResultsCSV(const std::string& name, const std::vector<Eigen::VectorXd>& results);

void print_progress(time_point begin, Eigen::Index samples, int i);
