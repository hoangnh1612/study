#include<iostream>
#include<vector>
#include<queue>
#include <utility>

std::vector<std::vector<int>> graph = {
    {1,2},
    {0, 3, 4},
    {0,5},
    {1},
    {1},
    {2}
};
auto size = graph.size();
std::vector<bool> visited(size, false);
void dfs(int start)
{
    std::cout << start << " ";
    for (auto node : graph[start])
    {
        if (!visited[node])
        {
            visited[node] = true;
            dfs(node);
        }
    }
}
int main()
{
    visited[1] = true;
    dfs(1);
    return 0;
}