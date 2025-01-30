#include "DenseMatrix.h"
#include "Band5Matrix.h"
#include "LeastResidualMethod.h"

#include <iostream>
#include <string>
#include <locale>

template<typename Func>
bool inputFilePath(const std::string& prompt, Func fileOperation);

template<typename MatrixType>
void processMatrix();

void startApplication();