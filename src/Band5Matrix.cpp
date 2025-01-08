#include "Band5Matrix.h"

#include <iostream>
#include <fstream>
#include <regex>

bool Band5Matrix::readData(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл: "+ file_path);
    }

    file.read(reinterpret_cast<char*>(&n), sizeof(size_t));
    if (!file) {
        throw std::runtime_error("Ошибка чтения заголовка файла.");
    }

    file.read(reinterpret_cast<char*>(&m), sizeof(size_t));
    if (!file) {
        throw std::runtime_error("Ошибка чтения заголовка файла.");
    }
    
    diagonal_el.resize(8*n);
    secondary_el.resize(8*(n-1));
    second_secondary_el.resize(8*(n-m));
    file.read(reinterpret_cast<char*>(diagonal_el.data()), 8*n);
    file.read(reinterpret_cast<char*>(secondary_el.data()), 8*(n-1));
    file.read(reinterpret_cast<char*>(second_secondary_el.data()), 8*(n-m));
    if (!file) {
        throw std::runtime_error("Ошибка чтения данных массива.");
    }
    return true;
}

std::vector<double> Band5Matrix::operator*(const std::vector<double>& vector_) const {
    std::vector<double> result(n);
    for (int i = 0; i < n; ++i) {
        if (i > m - 2) result[i] += second_secondary_el[i - m + 1] * vector_[i - m + 1];
        if (i < n - m + 1) result[i] += second_secondary_el[i] * vector_[i + m - 1];
        if (i > 0) result[i] += secondary_el[i - 1] * vector_[i - 1];
        if(i < n - 1)  result[i] += secondary_el[i] * vector_[i + 1];
        result[i] += diagonal_el[i] * vector_[i];
    }
    return result;
}
