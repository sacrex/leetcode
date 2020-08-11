//
// Created by sacred on 20-7-2.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

//buf数组缓存数组（预读到buf数组）
char Buf[1 << 16], *p = Buf, *q = Buf;
#define Getchar() (p == q && (q = (p = Buf) + fread(Buf, 1, 1 << 16, stdin), p == q) ? EOF : *p++)
inline int Read() {
    char ch = Getchar();
    int x = 0,f = 1;
    while (ch < '0'|| ch > '9') {
        if(ch=='-')
            f=-1;
        ch = Getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x=10 * x + ch - '0';
        ch = Getchar();
    }
    return x*f;
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

class Number {
private:
    static Number multi(const Number &n, int k, int j) {
        Number ans;

        int carry = 0;
        for (int i = 0; i < n.size(); ++i) {
            ans[i+j] = (n.A[i] * k + carry) % 10; //注意这里的 i+j，作为下标的
            carry = (n.A[i] * k + carry) / 10;
        }
        ans.len = n.len + j;
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

    Number(const Number& other) {
        memcpy(A,  other.A, sizeof(A));
        len = other.len;
    }

    Number& operator+=(Number &b) {
        *this = (*this) + b;
        return *this;
    }

    Number operator+(const Number &b)
    {
        Number ret(*this);

        int l = max(ret.len, b.len);
        for (int i = 0; i < l; ++i){
            ret.A[i] += b[i];
            ret.A[i+1] += ret.A[i] / 10;
            ret.A[i] = ret.A[i] % 10;
        }
        ret.len = l;
        if (ret.A[l]) ret.len++;
        return ret;
    }

    Number& operator*=(Number &b) {
        *this = (*this) * b;
        return *this;
    }

    Number operator*(const Number &b)
    {
        //如果b为0,则 *this = 0
        Number d;
        if (b.isZero()) {
            d.setNum(0, 0);
            d.setSize(1);
            return d;
        }

        Number c;
        for (int i = 0; i < b.len; ++i) {
            c = multi(*this, b[i], i); //i作为偏移值
            d = d + c;
        }
        return d;
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

Number f[5005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
#endif

    int N;
    cin >> N;
    if (N == 0) {
        cout << 0 << endl;
    } else if (N == 1) {
        cout << 1 << endl;
    } else if (N == 2) {
        cout << 2 << endl;
    } else {
        f[1] = Number(1), f[2] = Number(2);
        for (int i = 3; i <= N; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        cout << f[N] << endl;
    }

    cout << (Number(32) * Number(12)) << endl;

    return 0;
}