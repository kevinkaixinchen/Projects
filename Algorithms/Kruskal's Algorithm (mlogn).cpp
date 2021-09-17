#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int data;
    int height;
    int parent;
};

struct edge {
    int length;
    int a;
    int b;
};

bool sortByLength(edge lhs, edge rhs);
int find(int x, vector <node> &);
void makeUnion(int x, int y, vector <node>&);
void kruskals(int, int, edge []);

int main() {
    int n, m;
    cin >> n >> m;
    edge edges[m];

    for(int i = 0; i < m; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].length;
    }

    kruskals(n, m, edges);
    return 0;
}

bool sortByLength(edge lhs, edge rhs) {
    return lhs.length < rhs.length;
}

int find(int x, vector <node> &nodes) {

    while(x != nodes[x].parent) {
        x = nodes[x].parent;
    }
    return x;
}

void makeUnion(int x, int y, vector <node> &nodes) {
    int rx = find(x, nodes);
    int ry = find(y, nodes);

    if(rx == ry) {
    }
    else if(nodes[rx].height > nodes[ry].height) {
        nodes[ry].parent = rx;
    }
    else if(nodes[rx].height < nodes[ry].height) {
        nodes[rx].parent = ry;
    }
    else {
        nodes[ry].parent = rx;
        nodes[rx].height += 1;
    }
}

void kruskals(int n, int m, edge edges[]) {
    vector <node> nodes;
    sort(edges, edges + m, sortByLength);
    int sum = 0;

    for(int i = 0; i < n; i ++) {
        node pushNode;
        pushNode.data = i;
        pushNode.height = 1;
        nodes.push_back(pushNode);
        nodes[i].parent = i;
    }

    for(int i = 0; i < m; i++) {

        int ru = find(edges[i].a-1, nodes);
        int rv = find(edges[i].b-1, nodes);
        if(ru != rv) {
            sum += edges[i].length;
            makeUnion(ru, rv, nodes);
        }
    }

    cout << sum;
}
