#include <iostream>
#include <vector>

void DFS(int node, std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited, std::vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int i = 0; i < adjacencyMatrix[node].size(); ++i) {
        if (adjacencyMatrix[node][i] == 1 && !visited[i]) {
            DFS(i, adjacencyMatrix, visited, component);
        }
    }
}

std::vector<std::vector<int>> findConnectedComponents(std::vector<std::vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> components;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            DFS(i, adjacencyMatrix, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

int main() {
    // Пример таблицы смежности для графа
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };

    std::vector<std::vector<int>> connectedComponents = findConnectedComponents(adjacencyMatrix);

    for (int i = 0; i < connectedComponents.size(); ++i) {
        std::cout << "Connected component " << i + 1 << ": ";
        for (int j = 0; j < connectedComponents[i].size(); ++j) {
            std::cout << connectedComponents[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}