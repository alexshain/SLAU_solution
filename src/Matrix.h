#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <math.h>

class Matrix {
protected:
    uint64_t order_;

public:
    virtual bool readMatrixData(const std::string& file_path) = 0;
    virtual std::vector<double> operator*(const std::vector<double>& vector) const = 0;
    virtual ~Matrix() = default;

    uint64_t getOrger() const {
        return order_;
    }
};

