//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[100][100];

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    int first_col = 1, last_col = n, first_line = 1, last_line = n;
    int middle = (1 + n)/2;

    A[1][middle] = 1;
    int k = 2;
    int line = 1, col = middle;
    while(k <= n * n) {
        if (line == first_line && col != last_col) {
            A[last_line][col+1] = k;
            line = last_line, col = col + 1;
        } else if (col == last_col && line != first_line) {
            A[line-1][first_col] = k;
            line = line - 1, col = first_col;
        } else if (line == first_line && col == last_col) {
            A[line+1][col] = k;
            line = line + 1;
        } else if (line != first_line && col !=  last_col) {
            if (A[line-1][col+1] == 0) {
                A[line-1][col+1] = k;
                line = line - 1, col = col + 1;
            } else {
                A[line+1][col] = k;
                line = line + 1;
            }
        }
        k++;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j != 1) printf(" %d", A[i][j]);
            else printf("%d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}