#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct edge {
    int start;
    int end;
};

struct adjList {
    vector <int> endVertices;
};

int DFS(adjList G[], int n, int order[], stack <int> *postList);

void explore(adjList G[], int x, int visited[], int num_cc, stack <int> *postList);

int main() {
    int n;
    int m;
    cin >> n >> m;

    edge edges[m];
    adjList G[n];

    for(int i = 0; i < m; i++) {
        cin >> edges[i].start >> edges[i].end;
    }

    for(int i = 0; i < m; i++) {
        G[edges[i].start-1].endVertices.push_back(edges[i].end-1);
    }

    adjList Gr[n];
    for(int i = 0; i < m; i++) {
        Gr[edges[i].end-1].endVertices.push_back(edges[i].start-1);
    }

    int order[n];

    for(int i = 0; i < n; i++) {
        order[i] = i;
    }

    stack <int> postList;

    DFS(Gr, n, order, &postList);

    for(int i = 0; i < n; i ++) {
        order[i] = postList.top();
        postList.pop();
    }

    cout << DFS(G, n, order, &postList);
    return 0;
}

int DFS(adjList G[], int n, int order[], stack<int> *postList) {
    int num_cc = 0;
    int visited[n] = {0};
    for(int i = 0; i < n; i++) {
        if(visited[order[i]] == 0) {
            num_cc += 1;
            explore(G, order[i], visited, num_cc, postList);
        }
    }

    return num_cc;
}

void explore(adjList G[], int v, int visited[], int num_cc, stack<int> *postList) {
    visited[v] = num_cc;
    for(int i = 0; i < G[v].endVertices.size(); i++) {
        if(visited[G[v].endVertices[i]] == 0) {
            explore(G, G[v].endVertices[i], visited, num_cc, postList);
        }
    }
    postList->push(v);
}