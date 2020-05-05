//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

int main(int argc, char **argv)
{
    int a, b, c;
    cin >> a >> b >> c;
    
    string s;
    cin >> s;
    
    int Min = min(a, min(b, c));
    int Max = max(a, max(b, c));
    int Mid = a + b  + c - Min - Max;
    
    int ans[3];
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            ans[i] = Min;
        } else if (s[i] == 'B') {
            ans[i] = Mid;
        } else {
            ans[i] = Max;
        }
    }
    
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    
    return 0;
}