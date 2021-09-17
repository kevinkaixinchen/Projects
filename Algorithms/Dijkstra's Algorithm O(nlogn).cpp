#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 5000000;

struct edge {
    int start;
    int end;
    int length;
};

struct adjList {
    vector <int> endVertices;
};

void dijkstra(adjList G[], edge edges[], int n, int m, int s);

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    edge edges[m];

    for(int i = 0; i < m; i++) {
        cin >> edges[i].start >> edges[i].end >> edges[i].length;
    }

    adjList G[n+1];

    for(int i = 0; i < m; i++) {
        G[edges[i].start].endVertices.push_back(edges[i].end);
    }

    dijkstra(G, edges, n, m, s);
    return 0;
}

void dijkstra(adjList G[], edge edges[], int n, int m, int s) {
    int dist[n+1];
    for(int i = 0; i < n+1; i ++) {
        dist[i] = INF;
    }

    dist[s] = 0;


    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 1 ; i < n+1; i ++) {
        if(i == s) {
            pq.push(make_pair(0, i));
        }
        else {
            pq.push(make_pair(INF, i));
        }
    }

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i < G[u].endVertices.size(); i++) {

            int l;
            for(int j = 0; j < m; j++) {
                if(edges[j].start == u && edges[j].end == G[u].endVertices[i]) {
                    l = edges[j].length;
                }
            }
            int x = dist[G[u].endVertices[i]];
            int y = dist[u]+l;
            if(x >= 5000000 && y >= 5000000) {
                continue;
            }
            if(dist[G[u].endVertices[i]] > (dist[u]+l)) {
                dist[G[u].endVertices[i]] = (dist[u]+l);
                pq.push(make_pair((dist[u]+l), G[u].endVertices[i]));
            }
        }
    }


    for(int i = 1; i < n+1; i++) {
        if(dist[i] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }
}