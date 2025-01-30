#include "LeastResidualMethod.h"

static std::vector<double> operator-(const std::vector<double>& vector1, const std::vector<double>& vector2){
    size_t N = vector1.size();
    std::vector<double> result(N);
    for(size_t i = 0; i < N; ++i){
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
    std::vector<double> r_k;
    std::vector<double> Ar_k;

    size_t N = right_part_.size();
    std::vector<double> x_k(N);
    if(A.getOrger() != N) throw std::runtime_error("The number of columns in the matrix does not match the number of elements in the vector");
    size_t k = 0;
    double tau_k = 0;

    for (size_t k = 0; k < N; ++k) {
        x_k[k] = 1;
    }

    while (sqrt(vectorScalarMultiple(r_k, r_k)) > 1e-6) {
        k++;
        r_k = A * x_k - right_part_;
        Ar_k = A * r_k;
        tau_k = vectorScalarMultiple(Ar_k, r_k) / vectorScalarMultiple(Ar_k, Ar_k);
        x_k = x_k - tau_k * r_k;
        if(k > 50000){
            throw std::runtime_error("Unable to find a convergent solution");
        }
    }
    solution_ = x_k;
    return true;
}