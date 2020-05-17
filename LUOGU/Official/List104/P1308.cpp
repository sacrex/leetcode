//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

int main(int argc, char **argv)
{
    string word, article;
    getline(cin, word);
    getline(cin, article);

    for_each(word.begin(), word.end(),
    [](char &a) {
        a = tolower(a);
    });

    for_each(article.begin(), article.end(),
    [](char &a){
        a = tolower(a);
    });

    int i = 0, cnt = 0, p, first = 1;
    while (i < article.size()) {
        i = article.find(word, i);
        if (i == string::npos) {
            break;
        }
        if ((i == 0 || (i-1 >= 0 && article[i-1] == ' ')) &&
            (i + word.size() == article.size() || (article[i+word.size()] == ' '))) {
            if (first) p = i;
            cnt++;
            first = 0;
        }
        i += word.size();
    }
    if (!cnt) cout << -1 << endl;
    else cout << cnt << " " << p << endl;

    return 0;
}