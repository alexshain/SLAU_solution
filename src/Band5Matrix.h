#pragma once
#include "Matrix.h"

class Band5Matrix : public Matrix {
private:
	uint64_t m;
    std::vector<double> diagonal_el;
	std::vector<double> secondary_el;
	std::vector<double> second_secondary_el;
	
public:
    bool readData(const std::string& file_path) override;
    std::vector<double> operator*(const std::vector<double>& vector_) const override;
};