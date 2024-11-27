#ifndef HW5_IMPL_H
#define HW5_IMPL_H

#include <string>
#include <vector>
#include <queue>
#include <stack>

#include "hw5.h"
using namespace std;
void add_edge(std::vector<std::vector<int>>& graph, int from, int to) {
  // COMPLETE AQUI
    if (from >= graph.size()) {
        graph.resize(from + 1);
    }
    if (to >= graph.size()) {
        graph.resize(to + 1);
    }

    graph[from].push_back(to);
}

int n_vertices(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  return graph.size();
  //return 0;
}

int n_edges(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  int count = 0;
    for (const auto& neighbors : graph) {
        count += neighbors.size();  
    }
    return count;
  //return 0;
}

std::vector<int> BFS(std::vector<std::vector<int>> const& graph, int from) {
  // COMPLETE AQUI
  vector<int> visitedNodes;
  if (from >= graph.size()){
    return visitedNodes;
  } 

    vector<bool> visited(graph.size(), false);
    queue<int> queue;

    visited[from] = true;
    queue.push(from);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        visitedNodes.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
  return visitedNodes;
}

std::vector<int> DFS(std::vector<std::vector<int>> const& graph, int from) {
  // COMPLETE AQUI
  vector<int> visitedNodes;
  if (from >= graph.size()){ 
    return visitedNodes;
    }

    vector<bool> visited(graph.size(), false);
    stack<int> nodeStack;
    nodeStack.push(from);

    while (!nodeStack.empty()) {
        int node = nodeStack.top();
        nodeStack.pop();

        if (!visited[node]) {
            visited[node] = true;
            visitedNodes.push_back(node);

            const vector<int>& neighbors = graph[node];
            for (int i = neighbors.size() - 1; i >= 0; --i) {
                if (!visited[neighbors[i]]) {
                    nodeStack.push(neighbors[i]);
                }
            }
        }
    }
  return visitedNodes;
}

std::vector<std::vector<int>> connected_components(
  std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  vector<vector<int>> components;
  vector<bool> visited(graph.size(), false);

    for (size_t i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            vector<int> component;
            queue<int> nodeQueue;
            nodeQueue.push(i);
            visited[i] = true;

            while (!nodeQueue.empty()) {
                int node = nodeQueue.front();
                nodeQueue.pop();
                component.push_back(node);

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodeQueue.push(neighbor);
                    }
                }
            }

             components.push_back(component);
        }
    }
  return  components;

}

int n_connected_components(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  return connected_components(graph).size();
  //return 0;
}

#endif
