//
// Created by sacred on 20-8-10.
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

    Number& operator+=(const Number &b) {
        *this = (*this) + b;
        return *this;
    }

    Number& operator/=(int n) {
        *this = *this / n;
        return *this;
    }

    Number operator/(int n) {
        int t = 0;
        vector<int> ret;
        for (int i = len - 1; i >= 0; --i) {
            t = t * 10 + A[i];
            ret.push_back(t / n);
            t %= n;
        }
        reverse(ret.begin(), ret.end());
        while(ret.size() > 1 && ret.back() == 0) ret.pop_back();

        Number r;
        for (int i = 0; i < ret.size(); ++i) {
            r.setNum(i, ret[i]);
        }
        return r;
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

    Number& operator*=(const Number &b) {
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

    string str() {
        string ret;
        for (int i = size() - 1; i >= 0; --i) {
            ret += getNum(i) + '0';
        }
        return ret;
    }
};
ostream& operator<<(ostream& o, Number n) {
    for (int i = n.size() - 1; i >= 0; --i) {
        o << n.getNum(i);
    }
    return o;
}
bool operator<(const Number &a, const Number &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

bool operator==(const Number &a, const Number &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool operator!=(const Number &a, const Number &b) {
    return !(a == b);
}

bool operator<=(const Number &a, const Number &b) {
    return a < b || a == b;
}

bool operator>(const Number &a, const Number &b) {
    return !(a <= b);
}

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

struct Pson {
    int left, right;
    bool operator<(const Pson &o) const {
        return left * right < o.left * o.right;
    }
};
Pson A[10005];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
//    time_t start_time = time(NULL);
#endif

    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> A[i].left >> A[i].right;
    }
    sort(A+1, A+n+1);

    Number sum(1);
    Number Max(1);
    for (int i = 1; i <= n; ++i) {
        sum *= Number(A[i-1].left);
        Number t = sum / A[i].right;
        if (t > Max) {
            Max = t;
        }
    }

    cout << Max << endl;

#ifndef ONLINE_JUDGE
//    time_t end_time = time(NULL);
//    cout << "Cost Time(s): " << end_time - start_time << endl;
#endif

    return 0;
}