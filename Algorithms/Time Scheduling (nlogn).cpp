#include <iostream>
#include <algorithm>

using namespace std;

struct job {
    int s;
    int t;
    int v;
};

int binarySearch(job A[], int, int, int);
void DPweighted(job A[], int n);

bool sortByT(job lhs, job rhs) {
    return lhs.t < rhs.t;
}
int main() {
    int n;
    cin >> n;

    job A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i].s >> A[i].t >> A[i].v;
    }

    DPweighted(A, n);

    return 0;
}
int binarySearch(job A[], int k, int a, int b) {

    if(a <= b) {
        int m = (a+b)/2;
        if(A[m].t <= A[k].s) {
            if(A[m+1].t <= A[k].s) {
                return binarySearch(A, k, m+1, b);
            }
            else {
                return m;
            }
        }
        else {
            return binarySearch(A, k, a, m-1);
        }
    }
    return -1;
}

void DPweighted(job A[], int n) {
    int F[n];

    F[0] = 0;
    sort(A, A+n, sortByT);

    F[0] = A[0].v;
    for(int k = 1; k < n; k++) {
        int pre = binarySearch(A, k, 0, k-1);
        if(pre == -1) {
            F[k] = max(F[k-1], A[k].v);
        }
        else {
            F[k] = max(F[k-1], A[k].v + F[pre]);
        }
    }

    cout << F[n-1] << endl;
}