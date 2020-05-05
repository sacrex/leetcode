//素数判断(x >= 2)
bool isPrime(int x)
{
    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i <= int(sqrt(x)); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}