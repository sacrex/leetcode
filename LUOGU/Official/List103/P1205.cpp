//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)


char A[20][20], B[20][20], tmp[20][20], src[20][20];

//转90
void turn90(char A[20][20], int n)
{
    memcpy(tmp, A, sizeof(char) * 20 * 20);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            A[j][n+1-i] = tmp[i][j];
        }
    }
}

//反射
void reflect(char A[20][20], int n)
{
    int mid = (1 + n) / 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= mid; j++) {
            char tmp = A[i][j];
            A[i][j] = A[i][n+1-j];
            A[i][n+1-j] = tmp;
        }
    }
}

bool check(char a[20][20], char b[20][20], int n)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j){
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    string str;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for(int j = 1; j <= n; ++j) {
            src[i][j] = A[i][j] = str[j - 1];
        }
    }

    for (int i = 1; i <=n ; ++i) {
        cin >> str;
        for (int j = 1; j <= n; ++j) {
            B[i][j] = str[j-1];
        }
    }

    turn90(A, n);
    if (check(A, B, n)) {
        cout << 1 << endl;
        return 0;
    }
    turn90(A, n);
    if (check(A, B, n)) {
        cout << 2 << endl;
        return 0;
    }
    turn90(A, n);
    if (check(A, B, n)) {
        cout << 3 << endl;
        return 0;
    }

    turn90(A, n); //=src
    reflect(A, n);
    if (check(A, B, n)) {
        cout << 4 << endl;
        return 0;
    }

    turn90(A, n);
    if (check(A, B, n)) {
        cout << 5 << endl;
        return 0;
    }
    turn90(A, n);
    if (check(A, B, n)) {
        cout << 5 << endl;
        return 0;
    }
    turn90(A, n);
    if (check(A, B, n)) {
        cout << 5 << endl;
        return 0;
    }


    if (check(src, B, n)) {
        cout << 6 << endl;
        return 0;
    }
    cout << 7 << endl;

    return 0;
}