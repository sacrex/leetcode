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
    int A[1500];
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
#endif
    int P;
    cin >> P;
    cout << ceil(P * log10(2)) << endl;


    map<int, Number> mp; //存入 2^k 对应的number
    vector<int> vec;

    Number n(2);
    int cnt = 1; //累计乘２的次数
    while(cnt <= P) {
        if (cnt * 2 > P) {
            int left = P - cnt;
            for(int i = vec.size() - 1; i >= 0; --i) {
                if (left >= vec[i]) {
                    left -= vec[i];
                    n = n * mp[vec[i]];
                    if (n.size() > 520) n.setSize(520); //保留最低的520位，就可以精确的保留最低的500位
                }
            }
            if (left) {
                for (int i = 1; i <= left; ++i) {
                    n = n * Number(2);
                    if (n.size() > 520) n.setSize(520);
                }
            }
            break;
        }
        n = n * n; //快速幂
        if (n.size() > 520) n.setSize(520);
        cnt *= 2;
        mp[cnt] = n;
        vec.push_back(cnt);
    }

    n[0] -= 1; //减１
    for (int i = 499; i >=0 ; --i) {
        if (i !=499 && (i+1) % 50 == 0) cout << "\n";
        cout << n[i];
    }

    return 0;
}