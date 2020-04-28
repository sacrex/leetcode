//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{

    int n, m;
    cin >> n >> m;
    
    int y = 0;
    if (n % 100 == 0) {
        y = n % 400 == 0 ? 1 : 0;
    } else {
        y = n % 4 == 0 ? 1 : 0;
    }
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31\n");
            break;
        case 2:
            printf("%d\n", y == 1 ? 29 : 28);
            break;
        default:
            printf("30\n");
    }
    
    return 0;
}