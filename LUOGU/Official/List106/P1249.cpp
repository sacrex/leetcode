//
// Created by sacred on 20-4-19.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 0x80000000;
#define FREOPEN(x) freopen(x, "r", stdin)

/*
 * 以下实现了一个贪心算法，也就是找出sum = ２+3+...+x > n的ｘ,
 * 若sum - n == 1，则去除２，并让ｘ+1, 故选取了3,4,...,x+1
 * 若sum - n == t > 1，　那么去除t, 故选取了２，３，..t-1,t+1,...x.
 * 最后就是利用Number类实现大数乘法.
 *
 * 还有利用动态规划求解的方法（看成01背包问题以及化积为和）
 * https://www.luogu.com.cn/problem/solution/P1249
 *
 */


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
#endif

    int n;
    vector<int> ans;

    cin >> n;

    if (n == 3) {
        cout << "1 2" << "\n" << 2 << endl;
        return 0;
    }
    if (n == 4) {
        cout << "1 3" << "\n" << 3 << endl;
        return 0;
    }

    int sum = 0;
    for(int i = 2; i < n; ++i) {
        if (sum + i > n) {
            if (sum+i - n == 1) {
                ans.push_back(i+1);
                ans[0] = 0; //将ans[0]中存储的2改为0,表示删除２
            } else {
                ans.push_back(i);
                ans[sum+i-n-2] = 0; //删除ans中存储的sum+i-n这个数字（他刚好在sum+i-n-2这个位置）
            }
            break;
        }
        ans.push_back(i); //ans[i-2] = i;
        sum += i;
    }

    Number num(1);
    for(int i = 0; i < ans.size(); ++i) {
        if (ans[i]) {
            num = num * Number(ans[i]);
        }
    }

    //output
    for(int i = 0; i < ans.size(); ++i) {
        if (ans[i]) {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    cout << num << endl;

    return 0;
}