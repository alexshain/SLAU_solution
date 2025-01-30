#pragma once
#include "Matrix.h"

class Band5Matrix : public Matrix {
private:
	uint64_t second_side_dist_;
    std::vector<double> data_;
	std::vector<double> side_data_;
	std::vector<double> second_side_data_;
	
public:
    bool readMatrixData(const std::string& file_path) override;
    std::vector<double> operator*(const std::vector<double>& vector_) const override;
};