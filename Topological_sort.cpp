#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[v] = true; //теперь текущая вершина посещенная
    for (int neighbour : graph[v]) { // проходимся по всем соседям тек.вершины
        if (!visited[neighbour]) {
            dfs(neighbour, graph, visited, result);
        }
    }
    result.push_back(v); // добавляем тек.вершину в итоговый список вершин
}

vector<int> topologicalSort(int v, vector<vector<int>>& graph) {
    vector<bool> visited(v, false);
    vector<int> result;

    for (int i = 0; i < v; ++i) { // dfs (поиск в глубину) для каждой непосещенной вершины
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
    }
    reverse(result.begin(), result.end()); // переворачиваем результат - получится топологический порядок
    return result;
}

//ф-ция добавления ребра в граф
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int v = 6; // кол-во вершин в графе
    vector<vector<int>> graph(v); // создаем граф
    addEdge(graph, 5, 0);
    addEdge(graph, 5, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);

    vector<int> topoSorted = topologicalSort(v, graph);

    cout << "Топологическая сортировка: ";
    for (int v : topoSorted) {
        cout << v << " ";
    }
    cout << "" << endl;
    cout << "Временная сложность: O(V+E)";
    return 0;
}