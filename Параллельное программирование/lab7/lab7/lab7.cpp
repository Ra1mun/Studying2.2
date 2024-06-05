#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <omp.h>
#include <random>
#include <ctime>

#define N 1000
#define SIZE 12

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
            C[i][j] = 0.0;
        }
    }

    // Инициализация матриц A и B
    fillMatrix(A, N);
    fillMatrix(B, N);
    for (int chunk = 1; chunk < 256; chunk *= 2) {
            clock_t start_time = clock();
    #pragma omp parallel for shared(A, B, C) collapse(3) schedule(static, chunk)
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            if (omp_get_thread_num() == 0) {
                std::cout << chunk << '\n';
                std::cout << "Time for i-j-k loop: " << (double)(clock() - start_time) << '\n';
            }

            // Обнуление матрицы C для следующего варианта циклов
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    C[i][j] = 0.0;
                }
            }

            // Вариант циклов k-i-j
            start_time = clock();
    #pragma omp parallel for shared(A, B, C) collapse(3) schedule(static, chunk)
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            // Вариант циклов i-j-k
            if (omp_get_thread_num() == 0) {
                std::cout << chunk << '\n';
                std::cout << "Time for k-i-j loop: " << (double)(clock() - start_time) << '\n';
            }      
    }

    return 0;
}
