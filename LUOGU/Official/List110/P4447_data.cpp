#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    freopen("/home/sacred/leetcode/LUOGU/Official/List110/P4447.in", "w", stdout);

    int n = 100000;
    cout << n << endl;

    for (int i = 0; i < n; ++i) {
        cout << rand() % 100000000 << " ";
    }
    cout << endl;

}