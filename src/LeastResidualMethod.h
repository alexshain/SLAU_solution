#pragma once
#include "SLAUSolver.h"

class LeastResidualMethod : public SLAUSolver{
public:
    bool solve(const Matrix& A) override;
};

static std::vector<double> operator-(const std::vector<double>& vector1, const std::vector<double>& vector2);
static std::vector<double> operator*(double scalar, const std::vector<double>& vector_);