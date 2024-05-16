#include <iostream>
#include <ctime>
#include <float.h>
#include "Point.h"
#include "Sort.h"
#include "Graph.h"

double distance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double minWeight(double* weights, int& minIndex, size_t size) {
    using namespace std;
    double result = DBL_MAX;
    for (int i = 0; i < size; i++) {
        if (weights[i] < result) {
            result = weights[i];
            minIndex = i;
        }

    }

    return result;
}

Point calculateMaxCoordinats(const Point* points, size_t size) {
    int maxX = INT16_MIN;
    int maxY = INT16_MIN;
    for (int i = 0; i < size; i++) {
        if (points[i].x > maxX && points[i].y > maxY) {
            maxX = points[i].x;
            maxY = points[i].y;
        }
    }

    return Point(maxX, maxY);
}

Point calculateMinCoordinats(const Point* points, size_t size) {
    int minX = INT16_MAX;
    int minY = INT16_MAX;
    for (int i = 0; i < size; i++) {
        if (points[i].x < minX && points[i].y < minY) {
            minX = points[i].x;
            minY = points[i].y;
        }
    }

    return Point(minX, minY);
}

Point calculateCentroid(const Point* points, int size) {
    int totalSumX = 0;
    int totalSumY = 0;

    for (int i = 0; i < size; i++) {
        totalSumX += points[i].x;
        totalSumY += points[i].y;
    }
    int centroidX = totalSumX / size;
    int centroidY = totalSumY / size;

    return Point(centroidX, centroidY);
}

int main()
{
    using namespace std;

    srand(time(nullptr));

    int N = 8;
    int K = 5;
    int minPosition = -40, maxPosition = 40;


    //сгенерировать N случайных точек
    Point* points = new Point[N];
    for (int i = 0; i < N; i++) {
        Point newPoint(rand() % (maxPosition - minPosition + 1) + minPosition,
            rand() % (maxPosition - minPosition + 1) + minPosition);

        points[i] = newPoint;
    }

    //считая данные точки вершинами полного взвешенного графа (веса – расстояния между парами точек),
    //выделить ребра минимального остова
    double* minLengths = new double[N - 1];
    int** indexMinConnectedPoints = new int* [N - 1];
    for (int i = 0; i < N - 1; i++) {
        indexMinConnectedPoints[i] = new int[2];
        indexMinConnectedPoints[i][0] = i;
    }

    for (int currentPoint = 0; currentPoint < N - 1; currentPoint++) {
        double* weights = new double[N - currentPoint - 1];
        int countPoints = 0;
        for (int j = currentPoint + 1; j < N; j++) {
            weights[countPoints] = distance(points[currentPoint], points[j]);
            countPoints++;
        }

        int index;
        minLengths[currentPoint] = minWeight(weights, index, N - currentPoint - 1);
        indexMinConnectedPoints[currentPoint][1] = currentPoint + index + 1;

        delete[] weights;
    }

    //отсортировать ребра остова по возрастанию весов
    int* id = new int[N - 1];
    for (int i = 0; i < N - 1; i++)
        id[i] = i;

    Sort<double> sort;
    sort.PiramidSort(minLengths, id, N - 1);

    //по начальным N-K ребрам отсортированного массива построить матрицу смежности неориентированного графа
    //и выделить K компонент связности (вершины каждой компоненты образуют один кластер)


    int** adjacencyMatrix = new int*[N];
    for (int i = 0; i < N; i++) {
        adjacencyMatrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    //построение матрицы смежности
    for (int i = 0; i < N - K; i++) {
        int x = indexMinConnectedPoints[id[i]][0];
        int y = indexMinConnectedPoints[id[i]][1];

        adjacencyMatrix[x][y] = 1;
        adjacencyMatrix[y][x] = 1;
    }

    //нахождение компонентов связанности
    Graph extension;
    vector<vector<int>> connectedComponents = extension.findConnectedComponents(adjacencyMatrix, N);

    //Результат работы
    for (int i = 0; i < connectedComponents.size(); i++) {
        cout << "Number of vertices on connected components " << i + 1 << ": " << connectedComponents[i].size() << '\n';

        int length = connectedComponents[i].size();
        Point* connectedPoints = new Point[length];
        for (int j = 0; j < length; j++) {
            connectedPoints[j] = points[connectedComponents[i][j]];
        }

        cout << "Min Coordinates: " << calculateMinCoordinats(connectedPoints, length);
        cout << "Max Coordinates: " << calculateMaxCoordinats(connectedPoints, length);
        cout << "Centroid Coordinates: " << calculateCentroid(connectedPoints, length);
    }

    for (int i = 0; i < N - 1; i++) {
        delete[] indexMinConnectedPoints[i];
    }

    for (int i = 0; i < N; i++) {
        delete[] adjacencyMatrix[i];
    }

    delete[] indexMinConnectedPoints;
    delete[] adjacencyMatrix;
    delete[] points;
    delete[] minLengths;

    return 0;
}

