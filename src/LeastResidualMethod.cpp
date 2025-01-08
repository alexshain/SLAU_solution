#include "LeastResidualMethod.h"

static std::vector<double> operator-(const std::vector<double>& vector1, const std::vector<double>& vector2){
    size_t N = vector1.size();
    std::vector<double> result(N);
    for(size_t i = 0; i<N; ++i){
        result[i] = vector1[i] - vector2[i];
    }
    return result;
}

static std::vector<double> operator*(double scalar, const std::vector<double>& vector_) {
    size_t N = vector_.size();
    std::vector<double> result(N);
    for(size_t i = 0; i < N; ++i){
        result[i] = scalar*vector_[i];
    }
    return result;
}

bool LeastResidualMethod::solve(const Matrix& A) {
    size_t N = right_part.size();
    if(A.n != N) throw std::runtime_error("The number of columns in the matrix does not match the number of elements in the vector");
    size_t k = 0;
    double tau_k = 0;
    std::vector<double> x_k(N);	
    std::vector<double> r_k;
    std::vector<double> Ar_k;

    for (size_t k = 0; k < N; ++k) {
        x_k[k] = 1;
    }

    do {
        k++;
        r_k = A*x_k - right_part;
        Ar_k = A*r_k;
        tau_k = vectorScalarMultiple(Ar_k, r_k)/vectorScalarMultiple(Ar_k, Ar_k);
        x_k = x_k - tau_k * r_k;
        if(k > 50000){
            throw std::runtime_error("Unable to find a convergent solution");
        };
    } while (sqrt(vectorScalarMultiple(r_k, r_k)) > 1e-6);
    solution = x_k;
    std::cout << "Done" << std::endl;
    return true;
}