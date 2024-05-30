#include "Graph.h"

void Graph::DFS(int node, int** adjacencyMatrix, size_t size, std::vector<bool>& visited, std::vector<int>& component)
{
    visited[node] = true;
    component.push_back(node);

    for (int i = 0; i < size; ++i) {
        if (adjacencyMatrix[node][i] == 1 && !visited[i]) {
            DFS(i, adjacencyMatrix, size, visited, component);
        }
    }
}

std::vector<std::vector<int>> Graph::findConnectedComponents(int** adjacencyMatrix, size_t size)
{
    std::vector<bool> visited(size, false);
    std::vector<std::vector<int>> components;

    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            DFS(i, adjacencyMatrix, size, visited, component);
            components.push_back(component);
        }
    }

    return components;
}