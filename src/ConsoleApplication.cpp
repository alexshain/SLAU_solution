#include "ConsoleApplication.h"

template<typename Func>
bool inputFilePath(const std::string& prompt, Func fileOperation) {
    std::string path;
    while (true) {
        std::cout << prompt;
        std::cin >> path;
        // Проверка на команду выхода
        if (path == "exit") {
            std::cout << "Exit from path input.\n";
            return false;
        }

        try {
            fileOperation(path);
            return true;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
            std::cout << "Re-enter the path or type 'exit' to cancel..\n";
        }
    }
}

template<typename MatrixType>
void processMatrix() {
    while (true) {
        MatrixType myMatrix;
        LeastResidualMethod solve;

        if (!inputFilePath("Enter the path to the matrix file (or type 'exit' for cancel): ", [&](const std::string& path) {
            myMatrix.readMatrixData(path);
            })) {
            return; 
        }


        if (!inputFilePath("Enter the path to the file with the right part (or type 'exit' to cancel): ", [&](const std::string& path) {
            solve.readRightPart(path);
            })) {
            return; 
        }

        try {
            solve.solve(myMatrix);
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
            std::cout << "Please re-enter your data.\n";
            continue;
        }


        if (!inputFilePath("Enter the path to the output file (or type 'exit' to cancel): ", [&](const std::string& path) {
            solve.writeSolution(path);
            })) {
            return; 
        }
        break;
    }
}

void startApplication() {
    while (true)
    {
        std::cout << "To start working, enter the matrix type (-dm - dense matrices, -d5m - five-diagonal matrices, exit - to terminate the program): ";
        std::string str;
        while (true)
        {
            std::cin >> str;
            if (str == "-dm") {
                processMatrix<DenseMatrix>();
            }
            else if (str == "-d5m") {
                processMatrix<Band5Matrix>();
            }
            else if (str == "exit") {
                exit(0);
            }
            else
            {
                std::cout << "An incorrect query was entered, try to enter a good one" << std::endl;
            }
        }
    }
}