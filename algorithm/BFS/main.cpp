#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<std::vector<int>> graph = {
    {1, 2},
    {0, 3, 4},
    {0, 5},
    {1},
    {1},
    {2}
};
int size = graph.size();
std::vector<bool> visited(size, false);
std::queue<int> q;
void bfs()
{
    while (!q.empty())
    {
        int cur = q.front();
        std::cout << cur << " ";
        q.pop();
        for (auto i : graph[cur])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int start = 1;
    visited[start] = true;
    q.push(start);
    bfs();
}
