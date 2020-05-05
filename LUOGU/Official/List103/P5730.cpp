//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

char A[10][500];

char *tpl[10] = {"XXX", "X.X", "..X", "X.."};

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    memset(A, 0, sizeof(A));

    int cnt = 1;
    for (int i = 0; i < str.size(); ++i) {
        if (i) {
            strcpy(A[1]+cnt, ".");
            strcpy(A[2]+cnt, ".");
            strcpy(A[3]+cnt, ".");
            strcpy(A[4]+cnt, ".");
            strcpy(A[5]+cnt, ".");
            cnt++;
        }
        switch(str[i]) {
            case '0':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[1]);
                strcpy(A[3]+cnt, tpl[1]);
                strcpy(A[4]+cnt, tpl[1]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            case '1':
                strcpy(A[1]+cnt, tpl[2]);
                strcpy(A[2]+cnt, tpl[2]);
                strcpy(A[3]+cnt, tpl[2]);
                strcpy(A[4]+cnt, tpl[2]);
                strcpy(A[5]+cnt, tpl[2]);
                break;
            case '2':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[2]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[3]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            case '3':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[2]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[2]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            case '4':
                strcpy(A[1]+cnt, tpl[1]);
                strcpy(A[2]+cnt, tpl[1]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[2]);
                strcpy(A[5]+cnt, tpl[2]);
                break;
            case '5':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[3]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[2]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            case '6':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[3]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[1]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            case '7':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[2]);
                strcpy(A[3]+cnt, tpl[2]);
                strcpy(A[4]+cnt, tpl[2]);
                strcpy(A[5]+cnt, tpl[2]);
                break;
            case '8':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[1]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[1]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            case '9':
                strcpy(A[1]+cnt, tpl[0]);
                strcpy(A[2]+cnt, tpl[1]);
                strcpy(A[3]+cnt, tpl[0]);
                strcpy(A[4]+cnt, tpl[2]);
                strcpy(A[5]+cnt, tpl[0]);
                break;
            default:
                break;
        }
        cnt += 3;
    }

    for (int i = 1; i <= 5; ++i){
        printf("%s\n", A[i]+1);
    }
    printf("\n");

    return 0;
}