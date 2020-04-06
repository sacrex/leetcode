//
// Created by sacred on 20-2-23.
//

/**
 * ReverseInteger: 没有太多的技巧，只是考虑的-2^31的特殊情况（这个数不能通过abs取绝对值）
 * 其他数就是判断符号，去绝对值，并求逆序存数组，strtoll,求解
 */

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x == 0x80000000)
            return 0;

        bool sign = x > 0; //正数为真

        long long a = abs(x);
        char c[128] = {0};
        int i = 0;
        while(a > 0) {
            c[i++] = a % 10 + '0';
            a /= 10;
        }
        i = 0;
        while(c[i] == '0') i++;
        long long b = strtoll(c + i, nullptr, 10);
        if (sign && b > INT_MAX || !sign && -b < INT_MIN) {
            return 0;
        }
        return ((int)b) * (sign > 0 ? 1 : -1);
    }
};

int main(int argc, char **argv) {

    cout << 0x80000000 << endl;

    cout << Solution().reverse(0x80000000) << endl;

    return 0;
}

