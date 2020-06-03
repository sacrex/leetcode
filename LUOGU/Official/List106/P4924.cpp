//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int A[505][505], temp[505][505];

//以A[x][y]为左上角, 长度为2*r + 1的正方形，顺时针旋转90
void rotateClock(int a[][505], int x, int y, int r)
{
    for (int i = x; i <= x + 2 * r; ++i) {
        for (int j = y; j <= y + 2 * r; ++j) {
            temp[i][j] = a[i][j];
        }
    }

    for (int i = x; i <= x + 2 * r; ++i) {
        for (int j = y; j <= y + 2 * r; ++j) {
            a[x+j-y][y+2*r+x-i] = temp[i][j];
        }
    }
}

//顺时针选择90度 === 按左对角线对称变换,在左右翻转即可
void rotateClockV2(int a[][505], int x, int y, int r) {
    for(int i = x; i <= x + 2*r; ++i) {
        for (int j = y; j <= y + i - x; ++j) {
            int tmp = a[i][j];
            a[i][j] = a[x+j-y][y+i-x];
            a[x+j-y][y+i-x] = tmp;
        }
    }
    for (int i = x; i <= x + 2*r; ++i) {
        for (int j = y; j < y + r; ++j) {
            swap(a[i][j], a[i][2*y+2*r-j]);
        }
    }
}

//以A[x][y]左上角,长度为２*r+1的正方形,逆时针旋转90
void rotateClockwise(int a[][505], int x, int y, int r) {
    for (int i = x; i <= x + 2 * r; ++i) {
        for (int j = y; j <= y + 2 * r; ++j) {
            temp[i][j] = a[i][j];
        }
    }

    for (int i = x; i <= x + 2 * r; ++i) {
        for (int j = y; j <= y + 2 * r; ++j) {
            a[x+2*r-j+y][y+i-x] = temp[i][j];
        }
    }
}

//逆时针选择90度 === 按左对角线对称变换,在上下翻转即可
void rotateClockwiseV2(int a[][505], int x, int y, int r) {
    for(int i = x; i <= x + 2*r; ++i) {
        for (int j = y; j <= y + i - x; ++j) {
            int tmp = a[i][j];
            a[i][j] = a[x+j-y][y+i-x];
            a[x+j-y][y+i-x] = tmp;
        }
    }
    for (int i = x; i < x + r; ++i) {
        for (int j = y; j <= y + 2*r; ++j) {
            swap(a[i][j], a[2*x+2*r-i][j]);
        }
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            A[i][j] = ++cnt;
        }
    }

    int x, y, r, z;
    for (int i = 1; i <= M; ++i) {
        cin >> x >> y >> r >> z;
        x -= r;
        y -= r;
        if(z) {
            rotateClockwiseV2(A, x, y, r);
        } else {
            rotateClockV2(A, x, y, r);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (j != 1) printf(" ");
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}