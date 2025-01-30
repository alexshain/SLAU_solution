#include "Band5Matrix.h"

#include <iostream>
#include <fstream>
#include <regex>

bool Band5Matrix::readMatrixData(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: "+ file_path);
    }

    file.read(reinterpret_cast<char*>(&order_), sizeof(size_t));
    file.read(reinterpret_cast<char*>(&second_side_dist_), sizeof(size_t));
    
    data_.resize(order_);
    side_data_.resize(order_ - 1);
    second_side_data_.resize(order_ - second_side_dist_);
    file.read(reinterpret_cast<char*>(data_.data()), order_ * sizeof(uint64_t));
    file.read(reinterpret_cast<char*>(side_data_.data()), (order_ - 1) * sizeof(uint64_t));
    file.read(reinterpret_cast<char*>(second_side_data_.data()), (order_ - second_side_dist_) * sizeof(uint64_t));
    return true;
}

std::vector<double> Band5Matrix::operator*(const std::vector<double>& vector_) const {
    std::vector<double> result(order_);
    for (int i = 0; i < order_; ++i) {
        if(i > second_side_dist_ - 2) result[i] += second_side_data_[i - second_side_dist_ + 1] * vector_[i - second_side_dist_ + 1];
        if(i < order_ - second_side_dist_ + 1) result[i] += second_side_data_[i] * vector_[i + second_side_dist_ - 1];
        if(i > 0) result[i] += side_data_[i - 1] * vector_[i - 1];
        if(i < order_ - 1)  result[i] += side_data_[i] * vector_[i + 1];
        result[i] += second_side_data_[i] * vector_[i];
    }
    return result;
}
