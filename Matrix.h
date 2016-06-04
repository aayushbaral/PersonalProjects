//
// Created by click on 4/20/2016.
//
#pragma once
#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H
#include <vector>



using namespace std;


class Matrix {

private:
    unsigned  int rows;
    unsigned int columns;

public:
    Matrix(){};
    vector<vector<double>> matrix = vector<vector<double>>({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

    //Getters and setters
    void setRows(unsigned int rows) {
        Matrix::rows = rows;
    }

    void setColumns(unsigned int columns) {
        Matrix::columns = columns;
    }

    Matrix(unsigned int _rows, unsigned int _columns){
        _rows = rows;
        _columns = columns;

    };

    unsigned int getColumns() const {
        return columns;
    }

    unsigned int getRows() const {
        return rows;
    }
    Matrix getMatrix(unsigned int rows, unsigned int column );
    Matrix matrixMultiplication(Matrix matrix1,Matrix matrix2);
    Matrix matrixAddition(Matrix matrix1, Matrix matrix2);
    Matrix matrixTranspose(Matrix matrix1);
    Matrix multipleMatrix(Matrix matrix1, double a);
    Matrix scale(double a, double b, double c);
    Matrix rotateZaxis(double cth);
    Matrix rotateYaxis(double cth);
    Matrix rotateXaxis(double cth);
    Matrix tranlate2D(double tx, double ty, double tz);
    Matrix rotateZaxisInverse(double cth);
    Matrix rotateXaxisInverse(double cth);
    Matrix rotateYaxisInverse(double cth);
    Matrix translateInverse(double tx, double ty, double tz);
    Matrix scaleInverse(double a, double b, double c);

















};


#endif //RAYTRACER_MATRIX_H
