//素数判断(x >= 0)
bool isPrime(int x)
{
    if (x == 0 || x == 1)
        return false;

    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i <= int(sqrt(x)); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

//计算C(n, k)
long long C(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;

    long long ans = 1, t = 1;
    for (int i = 0; i < k; ++i) {
        ans *= (n - i);
        if (i) t *= i;
        //处理越界(例如计算C(30, 20),在30 * 29 * .... * 11时可能就已越界)
        if (ans % t == 0) {
            ans /= t;
            t = 1;
        }
    }
    ans /= (t * k);
    return ans;
}