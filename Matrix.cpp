//
// Created by click on 4/20/2016.
//

#include "Matrix.h"
#include <cmath>

double changeToradian = 180/3.1416;


Matrix Matrix::getMatrix(unsigned  int rows, unsigned int column) {
    Matrix returnMatrix;
    returnMatrix.matrix.resize(rows);
    for (int i = 0; i < rows; i++){
        returnMatrix.matrix[i].resize(column);
    }
    return returnMatrix;
}
Matrix Matrix::matrixMultiplication(Matrix matrix1, Matrix matrix2) {
    int rows = 4;
    int columns = 4;
    //unsigned int columns2 = matrix2[0].size();

    int n = matrix1.matrix.size();
    int m = matrix1.matrix[0].size();
    int p = matrix2.matrix[0].size();
    Matrix returnMatrix;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            double sumofElements = 0;
            for(int k =0; k < m; k++){
                sumofElements += matrix1.matrix[i][j] * matrix2.matrix[i][j];
            }
            returnMatrix.matrix[i][j] = sumofElements;
        }
    }
    return returnMatrix;
}
// a and b are non empty and are of same size
Matrix Matrix::matrixAddition(Matrix matrix1, Matrix matrix2) {
    unsigned int rows = matrix1.matrix.size();
    unsigned int columns = matrix1.matrix[0].size();
    Matrix returnMatrix;
    double sumOfElements;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j ++){
            sumOfElements = matrix1.matrix[i][j] + matrix2.matrix[i][j];
            returnMatrix.matrix[i][j] = sumOfElements;
        }

        return returnMatrix;
    }

}
//The matrix should be a square matrix
Matrix Matrix::matrixTranspose(Matrix matrix1) {
    unsigned int rows = matrix1.matrix.size();
    for(int i = 0; i < rows -1; i++){
        for(int j = i + 1; j < rows; j ++){
            std::swap(matrix1.matrix[i][j], matrix1.matrix[j][i]);
        }
    }

}
//When matrix is multiplied with an integer
Matrix Matrix::multipleMatrix(Matrix matrix1, double a) {
    unsigned  int rows = matrix1.matrix.size();
    unsigned int columns = matrix1.matrix[0].size();
    Matrix returnMatrix;

    for (int i = 0; i < rows; i++){
        double product = 0;
        for (int j = 0; j < columns; j++){
            product = a * matrix1.matrix[i][j];
            returnMatrix.matrix[i][j] = product;

        }
        return returnMatrix;
    }
}
Matrix Matrix::scale(double a, double b, double c) {
    Matrix returnMatrix;
    returnMatrix.matrix = {{a, 0, 0, 0},{0, b, 0, 0}, {0, 0, c, 0}, {0, 0, 0, 1}};
    return returnMatrix;
}
//rotation by z axis
//cth is the angle of rotation about the Z-axis

Matrix Matrix::rotateZaxis(double cth) {
    Matrix returnMatrix;
    returnMatrix.matrix = {{cos(cth*changeToradian), -sin(cth * changeToradian), 0, 0}, {sin(cth * changeToradian), cos(cth * changeToradian), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    return returnMatrix;
}
Matrix Matrix::tranlate2D(double tx, double ty, double tz) {
    Matrix returnMatrix;
    returnMatrix.matrix = {{1, 0, 0, tx}, {0, 1, 0, ty}, {0, 0, 1, 0}, {0, 0, 0, tz}};

    return returnMatrix;

}

Matrix Matrix::rotateYaxis(double cth) {
    Matrix returnMatrix;
    returnMatrix.matrix = {{cos(cth*changeToradian),0, sin(cth*changeToradian), 0}, {0, 1, 0, 0},
                                            {-sin(cth*changeToradian), 0, cos(cth*changeToradian),0}, {0, 0, 0, 1}};
    return returnMatrix;

}
Matrix Matrix::rotateXaxis(double cth) {
    Matrix returnMatrix;
    returnMatrix.matrix = {{1, 0, 0, 0}, {0, cos(cth*changeToradian),
            -sin(cth*changeToradian), 0}, {0, sin(cth*changeToradian), cos(cth *changeToradian), 0}, {0, 0, 0, 1}};
    return returnMatrix;
}


//Inverse matrices
Matrix Matrix::rotateZaxisInverse(double cth) {
    return matrixTranspose(rotateZaxis(cth));

}
Matrix Matrix::rotateXaxisInverse(double cth) {
    return matrixTranspose(rotateXaxis(cth));
}
Matrix Matrix::rotateYaxisInverse(double cth) {
    return matrixTranspose(rotateYaxis(cth));
}
Matrix Matrix::translateInverse(double tx, double ty, double tz) {
    Matrix returnMatrix;
    returnMatrix.matrix =  {{1, 0, 0, -tx}, {0, 1, 0, -ty}, {0, 0, 1, -tz}, {0, 0, 0, 1}};
    return  returnMatrix;

}
Matrix Matrix::scaleInverse(double a, double b, double c) {
    Matrix returnMatrix;
    returnMatrix.matrix = {{1/a, 0, 0, 0}, {0, 1/b, 0, 0}, {0, 0, 1/c, 0}, {0, 0, 0, 1}};
    return returnMatrix;
}





