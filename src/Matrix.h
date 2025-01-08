#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <math.h>

class Matrix {
public:
    uint64_t n;
    virtual bool readData(const std::string& file_path) = 0;
    virtual std::vector<double> operator*(const std::vector<double>& vector) const = 0;
    virtual ~Matrix() = default;
};

