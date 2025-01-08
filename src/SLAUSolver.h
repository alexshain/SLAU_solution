#pragma once
#include "matrix.h"
#include <fstream>
#include <regex>

class SLAUSolver {
protected:
    std::vector<double> right_part;
    std::vector<double> solution;
    double vectorScalarMultiple(std::vector<double>& first, std::vector<double>& second);
public:
    virtual bool solve(const Matrix& A) = 0;
};