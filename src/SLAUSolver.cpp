#include "SLAUSolver.h"

#include <iostream>
#include <fstream>
#include <regex>

double SLAUSolver::vectorScalarMultiple(std::vector<double>& first, std::vector<double>& second){
    double result = 0;
    size_t N = first.size();
    for(size_t i = 0; i <N; ++i){
        result += first[i]*second[i];
    }
    return result;
}
