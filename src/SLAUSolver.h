#pragma once
#include "Matrix.h"
#include <fstream>
#include <regex>

class SLAUSolver {
protected:
    std::vector<double> right_part_;
    std::vector<double> solution_;
    double vectorScalarMultiple(std::vector<double>& first, std::vector<double>& second);
    
public:
    bool readRightPart(const std::string& file_path);
    bool writeSolution(const std::string& file_path);
    virtual bool solve(const Matrix& A) = 0;
};