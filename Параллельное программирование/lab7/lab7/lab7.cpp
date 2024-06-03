#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <omp.h>
#include <random>

#define N 1000
#define SIZE 2

void fillMatrix(double** A, int size) {
    using namespace std;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = dis(gen);
        }
    }
}

int main()
{
    omp_set_num_threads(SIZE);

    double** A = new double*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
    }

    double** B = new double* [N];
    for (int i = 0; i < N; i++) {
        B[i] = new double[N];
    }

    double** C = new double* [N];
    for (int i = 0; i < N; i++) {
        C[i] = new double[N];
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
        }
    }

    // Инициализация матриц A и B
    fillMatrix(A, N);
    fillMatrix(B, N);

    // Вариант циклов i-j-k
    double start_time = omp_get_wtime();
#pragma omp parallel for shared(A, B, C) collapse(3) schedule(static)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_time = omp_get_wtime();
    std::cout << "Time for i-j-k loop: " << end_time - start_time << " seconds" << std::endl;

    // Обнуление матрицы C для следующего варианта циклов
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
        }
    }

    // Вариант циклов k-i-j
    start_time = omp_get_wtime();
#pragma omp parallel for shared(A, B, C) collapse(3) schedule(static)
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end_time = omp_get_wtime();
    std::cout << "Time for k-i-j loop: " << end_time - start_time << " seconds" << std::endl;

    return 0;
}
