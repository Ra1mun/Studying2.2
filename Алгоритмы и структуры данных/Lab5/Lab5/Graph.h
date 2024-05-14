#pragma once
#include <iostream>
#include <vector>

class Graph
{
private:
    void DFS(int node, int** adjacencyMatrix, size_t size, std::vector<bool>& visited, std::vector<int>& component);
public:
    std::vector<std::vector<int>> findConnectedComponents(int** adjacencyMatrix, size_t size);
};

