#include "DenseMatrix.h"

#include <iostream>
#include <fstream>
#include <regex>

bool DenseMatrix::readMatrixData(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл: " + file_path);
    }

    file.read(reinterpret_cast<char*>(&order_), sizeof(size_t));

    uint64_t total_elements = order_ * order_;

    data_.resize(total_elements);
    file.read(reinterpret_cast<char*>(data_.data()), total_elements);
    return true;
}

std::vector<double> DenseMatrix::operator*(const std::vector<double>& vector_) const {
    std::vector<double> result(order_);
    for(size_t i = 0; i < order_; ++i){
        for(size_t j = 0; j < order_; ++j){
            result[i] += data_[i * order_ + j] * vector_[j];
        }
    }
    return result;
}