#include <cstdio>
#include <queue>
#include <vector>
#define INF 0xfffffff

using namespace std;

struct road
{
    int weight;
    int vertex;
    int express;
};

struct compare_road
{
    bool operator()(road const &r1, road const &r2)
    {
        return r1.weight > r2.weight;
    }
};

int shortest_path(vector<vector<road>> &Graph, int source)
{
    priority_queue<road, vector<road>, compare_road> pq;
    vector<int> distance(Graph.size(), INF);
    pq.push({0, source, 0});
    distance[source] = 0;
    vector<bool> f(Graph.size(), false);
    while (not pq.empty())
    {
        int u = pq.top().vertex;
        int come_from_express = pq.top().express;
        pq.pop();
        if(f[u])
            continue;
        printf("current = %d express = %d\n", u, come_from_express);
        f[u] = true;
        for (auto &i : Graph.at(u))
        {
            int v = i.vertex;
            int weight = i.weight;
            int express = i.express;
            // if (f[v] == false and distance[v] > distance[u] + weight)
            // {
            //     if(!express)
            //     {
            //         distance[v] = distance[u] + weight;
            //         pq.push({distance[v], v,come_from_express});
            //     }
            //     else if(!come_from_express)
            //     {
            //         distance[v] = distance[u] + weight;
            //         pq.push({distance[v], v,1});
            //     }
            // }
            if(!express)
            {
                if(f[v] == false and dis[v][1]>dis[u])
            }
            else if(!come_from_express)
        }
    }
    if (distance[Graph.size() - 1] == INF)
    {
        return -1;
    }
    return distance[Graph.size() - 1];
}

int main()
{
    int n, m;
    int from, too, time, isExpress;
    scanf("%d %d", &n, &m);
    vector<vector<road>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &from, &too, &time, &isExpress);
        graph.at(from - 1).push_back({time, too - 1, isExpress});
        graph.at(too - 1).push_back({time, from - 1, isExpress});
    }
    int sp = shortest_path(graph, 0);
    printf("%d\n", sp);
    return 0;
}
fin_toofast.cpp
2 KB