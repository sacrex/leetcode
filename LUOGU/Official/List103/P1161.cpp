//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

/*
int A[2000005] = {0};
int main(int argc, char **argv)
{
    int N;
    double a, t;
    cin >> N;
    while(N--){
        cin >> a >> t;
        for (int i = 1; i <= t; ++i) {
            int p = a * i;
            A[p] ^= 1;
        }
    }
    for (int i = 1; ;++i) {
        if (A[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
*/


/*
 *
 * 直接异或,因为最后只有一盏灯开着，表示其余关闭的灯都执行了（开关）这两步，也就是执行了任意次的（开关）
 * 组合，所以就是存在偶数次的动作。例如对7号灯最后是关闭的，那么执行的动作可以是
 * 77(开关),7777(开关开关),777777（开关开关开关）,....
 * 所以可以直接用异或就可以获取到开的那盏灯的编号
 */
int main(int argc, char **argv)
{
    int N, ans = 0;
    double a, t;
    cin >> N;
    while(N--){
        cin >> a >> t;
        for (int i = 1; i <= t; ++i) {
            int p = a * i;
            ans ^= p; //直接异或即可
        }
    }
    cout << ans << endl;
    return 0;
}