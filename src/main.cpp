bool DenseMatrix::readData(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw ExceptionMessenger("Не удалось открыть файл: " + file_path);
    }

    file.read(reinterpret_cast<char*>(&n), sizeof(size_t));
    if (!file) {
        throw ExceptionMessenger("Ошибка чтения заголовка файла.");
    }

    uint64_t total_elements = n*n;

    matrix.resize(total_elements);
    file.read(reinterpret_cast<char*>(matrix.data()), total_elements);
    return true;
}

bool SolverSlau::readData(const std::string& file_path){
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw ExceptionMessenger("Failed to open file: " + file_path);
    }

    uint64_t n;
    file.read(reinterpret_cast<char*>(&n), sizeof(uint64_t));
    if (!file) {
        throw ExceptionMessenger("Error reading array data.");
    }
    right_part.resize(n);
    file.read(reinterpret_cast<char*>(right_part.data()), n*sizeof(double));
    return true;
}

int main() {
    return 0;
}