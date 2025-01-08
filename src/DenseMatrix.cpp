#include "DenseMatrix.h"

#include <iostream>
#include <fstream>
#include <regex>

bool DenseMatrix::readData(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл: " + file_path);
    }

    file.read(reinterpret_cast<char*>(&n), sizeof(size_t));
    if (!file) {
        throw std::runtime_error("Ошибка чтения заголовка файла.");
    }

    uint64_t total_elements = n*n;

    matrix.resize(total_elements);
    file.read(reinterpret_cast<char*>(matrix.data()), total_elements);
    return true;
}

std::vector<double> DenseMatrix::operator*(const std::vector<double>& vector_) const {
    std::vector<double> result(n);
    for(size_t i = 0; i<n; ++i){
        for(size_t j = 0; j<n; ++j){
            result[i] += matrix[i*n+j]*vector_[j];
        }
    }
    return result;
}