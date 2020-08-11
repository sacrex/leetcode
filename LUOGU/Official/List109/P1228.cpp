//
// Created by sacred on 20-7-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//buf数组缓存数组（预读到buf数组）
char Buf[1 << 16], *p = Buf, *q = Buf;
#define Getchar() (p == q && (q = (p = Buf) + fread(Buf, 1, 1 << 16, stdin), p == q) ? EOF : *p++)
inline int Read() {
    char ch = Getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)


// 判断(x, y)是否在(x0, y0)(x1, y1)所包围的区域
bool checkRange(int x, int y, int x0, int y0, int x1, int y1)
{
    return x >= x0 && x <= x1 && y >= y0 && y <= y1;
}

bool checkEqual(int x, int y, int x0, int y0)
{
    return x == x0 && y == y0;
}

/*
 *  二维的递归
 *  思路：见P1228.png的草图理解
 */

//（x0, y0）表示整个方块的左上角坐标, len表示边长, (x, y)表示已涂色的位置
//例如(x0, y0) = (0, 0), len = 8, (x, y) = (3, 3)
void dfs(int x0, int y0, int len, int x, int y)
{
    if (len == 2) {
        if (checkEqual(x0, y0, x, y)) {
            //选1
            //输出 x0+1, y0+1, 1
            cout << x0+1 << " " << y0+1 << " " << 1 << endl;
        } else if (checkEqual(x0, y0+1, x, y)){
            //选2
            //输出 x0+1, y0, 2
            cout << x0+1 << " " << y0 << " " << 2 << endl;
        } else if (checkEqual(x0+1, y0, x, y)) {
            //选3
            //输出 x0, y0+1, 3
            cout << x0 << " " << y0+1 << " " << 3 << endl;
        } else {
            //选4
            //输出 x0, y0, 4
            cout << x0 << " " << y0 << " " << 4 << endl;
        }
        return;
    }

    int x1 = x0+len/2-1, y1 = y0+len/2;   //第一限象需要被染色的空格(假如(x,y)不在第一限象)
    int x2 = x0+len/2-1, y2 = y0+len/2-1; //第二限象需要被染色的空格(假如(x,y)不在第二限象)
    int x3 = x0+len/2, y3 = y0+len/2-1;   //第三限象需要被染色的空格(假如(x,y)不在第三限象)
    int x4 = x0+len/2, y4 = y0+len/2;     //第四限象需要被染色的空格(假如(x,y)不在第四限象)

    //判断（x, y）在哪个限象
    //第一限象范围 (x0, y0+len/2) 对角 (x0+len/2-1, y0+len-1)
    if (checkRange(x, y, x0, y0+len/2, x0+len/2-1, y0+len-1)) {
        //涂2, x0+len/2, y0+len/2-1
        cout << x0+len/2 << " " << y0+len/2-1 << " " << 2 << endl;
        x1 = x, y1 = y;
    }
    //第二限象范围 (x0, y0) 对角 (x0+len/2-1, y0+len/2-1)
    else if (checkRange(x, y, x0, y0, x0+len/2-1, y0+len/2-1)) {
        //涂1 x0+len/2, y0+len/2
        cout << x0+len/2 << " " << y0+len/2 << " " << 1 << endl;
        x2 = x, y2 = y;
    }

    //第三限象范围 (x0+len/2, y0) 对角 (x0+len-1, y0+len/2-1)
    else if (checkRange(x, y, x0+len/2, y0, x0+len-1, y0+len/2-1)) {
        //涂3 x0+len/2-1, y0+len/2
        cout << x0+len/2-1 << " " << y0+len/2 << " " << 3 << endl;
        x3 = x, y3 = y;
    }
    //第四限象范围 (x0+len/2, y0+len/2) 对角 (x0+len-1, y0+len-1)
    else if (checkRange(x, y, x0+len/2, y0+len/2, x0+len-1, y0+len-1)) {
        //涂4，x0+len/2-1, y0+len/2-1
        cout << x0+len/2-1 << " " << y0+len/2-1 << " " << 4 << endl;
        x4 = x, y4 = y;
    }

    dfs(x0, y0+len/2, len/2, x1, y1);       //涂第一限象
    dfs(x0, y0, len/2, x2, y2);             //涂第二限象
    dfs(x0+len/2, y0, len/2, x3, y3);       //涂第三限象
    dfs(x0+len/2, y0+len/2, len/2, x4, y4); //涂第四限象
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    int k, x, y;
    cin >> k >> x >> y;

    dfs(1, 1, 1 << k, x, y);

    return 0;
}