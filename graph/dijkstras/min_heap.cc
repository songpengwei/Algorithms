#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <utility>
#include <set>

using namespace std;

class Graph{
    private:
        int V;
        vector< pair<int, int> > *edges;
    public:
        Graph(int v) {
            V = v;
            edges = new vector< pair<int, int> >[V];
        }

        void addEdge(int u, int v, int w) {
            edges[u].push_back(make_pair(v, w));
            edges[v].push_back(make_pair(u, w));
        }

        void shortestPath(int src) {
            set< pair<int, int> > setd;

            vector<int> dist(V, INT_MAX);

            dist[src] = 0;
            setd.insert(make_pair(0, src));

            while (!setd.empty()) {
                pair<int, int> now = *(setd.begin());
                setd.erase(setd.begin());

                int u = now.second;
                for (int i = 0; i < edges[u].size(); ++i) {
                    int v = edges[u][i].first;
                    int w = edges[u][i].second;

                    if (dist[v] > dist[u] + w) {
                        if (dist[v] != INT_MAX) {
                            setd.erase(setd.find(make_pair(dist[v], v)));
                        }

                        dist[v] = dist[u] + w;
                        setd.insert(make_pair(dist[v], v));
                    }
                }
            }

            cout << "Vertex Distance from source:" << endl;
            for (int i = 0; i < V; ++i) {
                printf("%d\t%d\n", i, dist[i]);
            }
        }
};

int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
