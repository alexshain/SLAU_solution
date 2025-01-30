#pragma once
#include "Matrix.h"

class DenseMatrix : public Matrix {
private:
    std::vector<double> data_;
public:
    bool readMatrixData(const std::string& file_path) override;
    std::vector<double> operator*(const std::vector<double>& vector_) const override;
};