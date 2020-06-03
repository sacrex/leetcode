//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

struct Pos{
   int start_pos_x;
   int start_pos_y;
   int cur_pos_x;
   int cur_pos_y;
   int d; //0　北 1 东 2 南 3 西
}J, C;

//保存John和牛的状态
struct Stat {
    int J_cur_pos_x;
    int J_cur_pos_y;
    int J_d;

    int C_cur_pos_x;
    int C_cur_pos_y;
    int C_d;
};
vector<Stat> stats;

char m[20][20];

int dir[4][2] = {
        {-1, 0}, //向北走一步,
        {0, 1}, //向东走一步,
        {1, 0}, //向南走一步
        {0, -1}, //向西走一步
};

void init() {
    for (int i = 1; i <= 10; ++i) {
        cin >> &m[i][1];
        for (int j = 1; j <= 10; ++j) {
            if (m[i][j] == 'F') {
                J.start_pos_x = J.cur_pos_x = i;
                J.start_pos_y = J.cur_pos_y = j;
                J.d = 0;
            } else if (m[i][j] == 'C') {
                C.start_pos_x = C.cur_pos_x = i;
                C.start_pos_y = C.cur_pos_y = j;
                C.d = 0;
            }
        }
    }
}

/*
 * stats这个集合用于存储曾经的状态
 */
bool comeback_to_previous_pos() {
    for (int i = 0; i < stats.size(); ++i) {
        if (stats[i].J_cur_pos_x == J.cur_pos_x && stats[i].J_cur_pos_y == J.cur_pos_y &&
                stats[i].J_d == J.d && stats[i].C_cur_pos_x == C.cur_pos_x && stats[i].C_cur_pos_y == C.cur_pos_y &&
                stats[i].C_d == C.d) {
            return true;
        }
    }
    return false;
}

//走下一步
void next_step() {
    int jx = J.cur_pos_x, jy = J.cur_pos_y;
    jx += dir[J.d][0];
    jy += dir[J.d][1];
    if (m[jx][jy] == '*' || jx > 10 || jx < 1 || jy > 10 || jy < 1) {
        J.d = (++J.d) % 4; //顺时针转90，不需要改变位置
    } else {
        J.cur_pos_x = jx;
        J.cur_pos_y = jy;
    }

    int cx = C.cur_pos_x, cy = C.cur_pos_y;
    cx += dir[C.d][0];
    cy += dir[C.d][1];
    if (m[cx][cy] == '*' || cx > 10 || cx < 1 || cy > 10 || cy < 1) {
        C.d = (++C.d) % 4;
    } else {
        C.cur_pos_x = cx;
        C.cur_pos_y = cy;
    }
}

/*
 * 走到一起
 */
bool together() {
    if (J.cur_pos_x == C.cur_pos_x && J.cur_pos_y == C.cur_pos_y) {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    init();
    int minute = 0;
    while(true) {
        next_step();
        if(comeback_to_previous_pos()) { //如果回到曾经的某一个状态，表明John和牛将会一直循环，不可能相遇了
            minute = 0;
            break;
        }

        Stat stat;
        stat.J_cur_pos_x = J.cur_pos_x;
        stat.J_cur_pos_y = J.cur_pos_y;
        stat.J_d = J.d;
        stat.C_cur_pos_x = C.cur_pos_x;
        stat.C_cur_pos_y = C.cur_pos_y;
        stat.C_d = C.d;
        stats.push_back(stat); //!!!记录状态，用来判断是否会走回先前的某一个状态，那样的话就是永远不会相遇
        minute++;

        if (together()) {
            break;
        }
    }
    cout << minute << endl;

    return 0;
}