//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;

class Number {
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
    int A[500];
    int len;

public:
    Number(int i = 0) {
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

    Number& operator+(Number &b)
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

    Number& operator*(Number &b)
    {
        Number c, d;
        for (int i = 0; i < b.len; ++i) {
            c = multi(b[i], i); //i作为偏移值
            d = d + c;
        }
        *this = d;
        return *this;
    }

    void print() {
        for (int i = len - 1; i >= 0; --i) {
            printf("%d", A[i]);
        }
    }

    int size() const {
        return len;
    }

    int& operator[](int i)
    {
        return A[i];
    }
};

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    Number a(1), ans;
    for (int i = 1; i <= n; i ++) {
        Number c(i);
        a *= c;
        ans += a;
    }
    ans.print();
    cout << endl;
    return 0;
}