//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int dir[4][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

//表示农夫和牛的状态
struct Stat {
    int fx, fy, fd;
    int cx, cy, cd;

    bool operator==(const struct Stat& o) {
        return o.fx == fx && o.fy == fy && o.fd == fd && o.cx == cx && o.cy == cy && o.cd == cd;
    }

    Stat(int fx = -1, int fy = -1, int fd = 0, int cx = -1, int cy = -1, int cd = 0)
            : fx(fx), fy(fy), fd(fd), cx(cx), cy(cy), cd(cd) {}

//    int statFlag() {
//        return (fx-1) + (fy-1) * 10 + (cx-1) * 100 + (cy-1) * 1000 + fd * 10000 + cd * 40000;
//    }
};
struct Stat stat[160005]; //10*10*10*10*4*4
int stat_length = 0;

//int statFlag[160005];

char mp[20][20];
struct Stat currentStat;

void init() {
    for (int i = 1; i <= 10; ++i) {
        cin >> &mp[i][1];
//        scanf("%s", &mp[i][1]);
    }
    for (int i =1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (mp[i][j] == 'F') {
                currentStat.fx = i;
                currentStat.fy = j;
            }
            if (mp[i][j] == 'C') {
                currentStat.cx = i;
                currentStat.cy = j;
            }
        }
    }
}

bool come_together() {
    return currentStat.fx == currentStat.cx && currentStat.fy == currentStat.cy;
}

bool comeback_to_previous_postion() {
    for (int i = 0; i < stat_length; ++i) {
        if (currentStat == stat[i]) return true;
    }
//    if (statFlag[currentStat.statFlag()]) return true;
    return false;
}

void next_step() {
    int nfx = currentStat.fx + dir[currentStat.fd][0], nfy = currentStat.fy + dir[currentStat.fd][1];
    if (nfx > 10 || nfx < 1 || nfy > 10 || nfy < 1 || mp[nfx][nfy] == '*') {
        currentStat.fd = ++currentStat.fd % 4;
    } else {
        currentStat.fx = nfx;
        currentStat.fy = nfy;
    }

    int ncx = currentStat.cx + dir[currentStat.cd][0], ncy = currentStat.cy + dir[currentStat.cd][1];
    if (ncx > 10 || ncx < 1 || ncy > 10 || ncy < 1 || mp[ncx][ncy] == '*') {
        currentStat.cd = ++currentStat.cd % 4;
    } else {
        currentStat.cx = ncx;
        currentStat.cy = ncy;
    }
}

/**
 * 注释的那些代码使用了状态压缩，而当前的版本是用一个数组存储一个结构体集合（该结构体表示一个状态）
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif
    init();
    int step = 0;
    while(true) {
        if (come_together()) {
            break;
        }
        if (comeback_to_previous_postion()) {
            step = 0;
            break;
        }
        stat[stat_length++] = currentStat;
//        statFlag[currentStat.statFlag()] = 1;
        next_step();
        step++;
    }
    cout << step << endl;
//    printf("%d\n", step);

    return 0;
}