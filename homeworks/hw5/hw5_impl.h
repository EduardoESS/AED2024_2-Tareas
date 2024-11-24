#ifndef HW5_IMPL_H
#define HW5_IMPL_H

#include <string>
#include <vector>

#include <queue>//borrar?
#include <stack>//borrar?

#include "hw5.h"

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
  std::vector<int> ret;
  if (from >= graph.size()) return ret;

    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;

    visited[from] = true;
    q.push(from);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ret.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
  return ret;
}

std::vector<int> DFS(std::vector<std::vector<int>> const& graph, int from) {
  // COMPLETE AQUI
  std::vector<int> ret;
  if (from >= graph.size()) return ret;

    std::vector<bool> visited(graph.size(), false);
    std::stack<int> s;

    s.push(from);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            ret.push_back(node);

            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
  return ret;
}

std::vector<std::vector<int>> connected_components(
  std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  std::vector<std::vector<int>> ret;
  std::vector<bool> visited(graph.size(), false);

    for (size_t i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            std::vector<int> component;
            std::queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                component.push_back(node);

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            ret.push_back(component);
        }
    }
  return ret;

}

int n_connected_components(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  return connected_components(graph).size();
  //return 0;
}

#endif
