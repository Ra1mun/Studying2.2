#include <iostream>
#include <omp.h>

#define SIZE 12

int const n = 10e8;

double f(double x) {
    return exp(-1.46 * x * x) / (3.5 + sin(x));
}

void CheckAnswer(double actual) {
    using namespace std;

    double exception = 0.08;

    cout << "Ответ: " << actual << '\n';
    cout << "Ожидаемый ответ: " << exception << '\n';
    cout << "Погрешность: " << abs(actual - exception) << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    omp_set_num_threads(SIZE);

    double a = 0.3;
    double b = 0.8;

    double integral = 0.0;
    double h = (b - a) / n;

    clock_t start_time = clock();

#pragma omp parallel
    {
#pragma omp for reduction(+ : integral)
        for (int step = 0; step < n / SIZE; step++) {
            double x1 = a + step * h;
            double x2 = a + (step + 1) * h;
            integral += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));
        }
    }

    CheckAnswer(integral);
    std::cout << "Время: " << (double)(clock() - start_time) << '\n';
}
