//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

class Number {
private:
    Number multi(int k, int j) {
        Number ans;
        int carry = 0;
        for (int i = 0; i < len; ++i) {
            ans[i+j] = (A[i] * k + carry) % 10; //注意这里的 i+j，作为下标的
            carry = (A[i] * k + carry) / 10;
        }
        ans.len = len + j;
        if (carry) {
            ans[ans.len] = carry;
            ans.len ++;
        }
        return ans;
    }
private:
    int A[4010];
    int len;
public:
    //A数组的A[0]表示个位
    explicit Number(const char *L, int l)
    {
        memset(A, 0, sizeof(A));
        len = l;
        for (int i = 0; i < l; ++i) {
            A[l-1-i] = L[i] - '0';
        }
        len = l;
    }

    explicit Number(int i = 0)
    {
        memset(A, 0, sizeof(A));
        int k = 0;
        while(i) {
            A[k++] = i % 10;
            i /= 10;
        }
        len = k;
    }

    Number& operator+=(Number &b) {
        return *this + b;
    }

    Number& operator+(const Number &b)
    {
        int l = max(len, b.len);
        for (int i = 0; i < l; ++i){
            A[i] += b[i];
            A[i+1] += A[i] / 10;
            A[i] = A[i] % 10;
        }
        if (A[len = l]) len++;
        return *this;
    }

    Number& operator*=(Number &b) {
        return *this * b;
    }

    Number& operator*(const Number &b)
    {
        //如果b为0,则 *this = 0
        if (b.isZero()) {
            setNum(0, 0);
            setSize(1);
            return *this;
        }

        Number c, d;
        for (int i = 0; i < b.len; ++i) {
            c = multi(b[i], i); //i作为偏移值
            d = d + c;
        }
        *this = d;
        return *this;
    }

    void setNum(int idx, int digit) {
        if (idx >= size()) {
            setSize(idx+1);
        }
        this->A[idx] = digit;
    }

    int getNum(int idx) const {
        if (idx >= size()) {
            return 0;
        }
        return A[idx];
    }

    int setSize(int len) {
        this->len = len;
    }

    int size() const {
        return len;
    }

    int& operator[](int i) {
        return A[i];
    }

    const int& operator[](int i) const
    {
        return A[i];
    }

    bool isZero() const {
        for (int i = 0; i < size(); ++i) {
            if (getNum(i) != 0)
                return false;
        }
        return true;
    }
};
ostream& operator<<(ostream& o, Number n) {
    for (int i = n.size() - 1; i >= 0; --i) {
        cout << n.getNum(i);
    }
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    FREOPEN("/home/sacred/leetcode/LUOGU/Official/List106/P1591_in");
#endif
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n, a;
        cin >> n >> a;
        Number num(1);
        for(int j = 2; j <= n; ++j) {
            Number t(j);
            num = num * t;
        }
        int ans = 0;
        for (int j = 0; j < num.size(); ++j) {
            if (num[j] == a) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}