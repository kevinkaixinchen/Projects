#include <iostream>
#include <vector>

using namespace std;

const int INF = 5000000;

struct edge {
    int start;
    int end;
    int length;
};

struct adjList {
    vector <int> inVertices;
    vector <int> l;
};

int bellmanFordNE(adjList G[], int s, int n);

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    adjList G[n];
    edge edges[m];

    for(int i = 0; i < m; i++) {
        cin >> edges[i].start >> edges[i].end >> edges[i].length;
    }

    for(int i = 0; i < m; i++) {
        G[edges[i].end-1].inVertices.push_back(edges[i].start-1);
        G[edges[i].end-1].l.push_back(edges[i].length);
    }

    if(bellmanFordNE(G, s, n)) {
        cout << "False";
    } else { cout << "True"; }

    return 0;
}

int bellmanFordNE(adjList G[], int s, int n) {
    int dist[n];
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[s-1] = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < G[j].inVertices.size(); k++) {
                int x = dist[G[j].inVertices[k]] + G[j].l[k];
                if(x > 4900000) {
                    x = INF;
                }
                if(x < dist[j]) {
                    dist[j] = x;
                }
            }
        }
    }

    int distN[n];

    for(int i = 0; i < n; i++) {
        distN[i] = dist[i];
    }

    for(int j = 0; j < n; j++) {
        for(int k = 0; k < G[j].inVertices.size(); k++) {
            int x = distN[G[j].inVertices[k]] + G[j].l[k];
            if(x > 4900000) {
                x = INF;
            }
            if(x < distN[j]) {
                distN[j] = x;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dist[i] != distN[i]) {
            return 0;
        }
    }
    return 1;
}