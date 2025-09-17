#include<iostream>
#include<vector>
#include<queue>
#include<utility>

std::vector<std::vector<int>> graph =
{
  {0,1,4},
  {0,2,8},
  {1,4,6},
  {2,3,2},
  {3,4,10}, 
  {1,2,2}, 
};

std::vector<int> dp(5, INT32_MAX);
std::vector<bool> visited(5, false);
int numV = 5;


struct compare
{
    bool operator()(std::pair<int, int> a, std::pair<int, int> b)
    {
        return a.second > b.second;
    }
};

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> pq;

void dijkstra(int start)
{
    dp[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int curNode = cur.first;
        if (visited[curNode]) continue;
        visited[curNode] = true;
        for (auto edge : graph)
        {
            if (edge[0] == curNode || edge[1] == curNode)
            {
                int nextNode = (edge[0] == curNode) ? edge[1] : edge[0];
                int newCost = dp[curNode] + edge[2];
                if (newCost < dp[nextNode])
                {
                    dp[nextNode] = newCost;
                    pq.push({nextNode, newCost});
                }
            }
        }
    }
}

int main()
{
    dijkstra(2);
    for (int i = 0; i < numV; i++)
    {
        std::cout << "0 to " << i << " : " << dp[i] << "\n";
    }
    return 0;
}

