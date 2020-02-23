//
// Created by sacred on 20-2-23.
//

#include "common.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;

        long long r = 0, t = x;
        while (t > 0) {
            r = r * 10 + t % 10;
            t /= 10;
        }

        return (int)r == x;
    }
};


int main(int argc, char **argv)
{
    cout << Solution().isPalindrome(-121) << endl;
    cout << Solution().isPalindrome(121) << endl;
    cout << Solution().isPalindrome(10) << endl;

    return 0;
}
