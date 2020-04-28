//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    switch (T) {
        case 1:
            cout << "I love Luogu!" << endl;break;
        case 2:
            cout << 6 << " " << 4 << endl;break;
        case 3:
            cout << 3 << "\n" << 12 << "\n" << 2 << endl;break;
        case 4:
            printf("%.3f\n", 500.0 / 3);break;
        case 5:
            cout << 15 << endl;break;
        case 6:
            cout << sqrt(117) << endl; break;
        case 7:
            cout << 110 << "\n" << 90 << "\n" << 0 << endl;break;
        case 8:
            cout << 5 * 2 * 3.141593 << "\n" << 3.141593 * 25 << "\n" << 4.0 / 3 * 3.141593 * 125 << "\n";
            break;
        case 9:
            cout << 22 << endl;break;
        case 10:
            cout << 9 << endl;break;
        case 11:
            cout << 100.0 / 3 << endl;break;
        case 12:
            cout << 'M' - 'A' + 1 << "\n";
            printf("%c\n", 'A' + 17);
            break;
        case 13:
            {
                double V = 4.0 / 3 * 3.141593 * 1064;
                cout << (int) (pow(10, log10(V) * 1.0 / 3)) << endl;
            }
            break;
        case 14:
            cout << 50 << endl;break;
        default:
            break;
    }

    return 0;
}