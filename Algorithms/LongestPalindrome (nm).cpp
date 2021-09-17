#include <iostream>

using namespace std;

void longestPalindrome(string x);

int main() {
    string x;
    cin >> x;
    longestPalindrome(x);
    return 0;
}

void longestPalindrome(string x) {

    int tb[x.length()][x.length()];
    //for(int i = 0; i < x.length(); i++) {
    //    for(int j = 0; j < x.length(); j++) {
    //        tb[i][j] = 0;
    //    }
    //}

    for(int i = 0; i < x.length(); i++) {
        tb[i][i] = 1;
    }

    for(int k = 1; k < x.length(); k++) {
        for(int i = 0; i < x.length()-k+1; i++) {

            if(x[i] == x[i+k] && k == 1) {
                tb[i][i+k] = 2;
            }
            else if(x[i] == x[i+k] && k != 1) {
                tb[i][i+k] = tb[i+1][i+k-1] + 2;
            }
            else {
                if(tb[i][i+k-1] >= tb[i+1][i+k]) {
                    tb[i][i+k] = tb[i][i+k-1];
                }
                else {
                    tb[i][i+k] = tb[i+1][i+k];
                }
            }
        }
    }

    //for(int i = 0; i < x.length(); i++) {
    //    for(int j = 0; j < x.length(); j++) {
    //        cout << tb[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << tb[0][x.length()-1];
}