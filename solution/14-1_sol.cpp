/**
 * 뒤집은 소수
 */

#include <iostream>

using namespace std;

int reverse(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret *= 10;
        ret += (x % 10);
        x /= 10;
    }
    return ret;
}

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;

    for (int i = 3; i < x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    string str("");
    //freopen("input.txt", "rt", stdin);
    //getline(std::cin, str);
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num; 
        int rev = reverse(num);
        if (isPrime(rev))
            cout << rev << ' ';
    }

    return 0;
}


