#include "SLAUSolver.h"

#include <iostream>
#include <fstream>
#include <regex>

double SLAUSolver::vectorScalarMultiple(std::vector<double>& first, std::vector<double>& second){
    double result = 0;
    size_t N = first.size();
    for(size_t i = 0; i < N; ++i){
        result += first[i] * second[i];
    }
    return result;
}

bool SLAUSolver::readRightPart(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + file_path);
    }

    uint64_t data_size;
    file.read(reinterpret_cast<char*>(&data_size), sizeof(uint64_t));

    right_part_.resize(data_size);
    file.read(reinterpret_cast<char*>(right_part_.data()), data_size*sizeof(double));
    return true;
}

bool SLAUSolver::writeSolution(const std::string& file_path){
    std::ofstream file(file_path, std::ios_base::binary);
    std::regex re("^.*$");
    if (!std::regex_match(file_path, re)) {
        throw std::runtime_error("The file name cannot contain the following characters: ^.*$");
    }
    uint64_t number = solution_.size();
    file.write(reinterpret_cast<char*>(&number), sizeof(double));
    if (!file) {
        throw std::runtime_error("Error writing data. There may be no such path.");
    }

    file.write(reinterpret_cast<char*>(solution_.data()), number*sizeof(double));
    file.close();
    return true;
}

