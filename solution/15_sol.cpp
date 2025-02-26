/**
 * 소수의 개수
 */

#include <iostream>

using namespace std;


bool isPrime(int x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;
    // 약수의 배수 관계를 고려하면, x의 제곱근 까지만 비교해도 충분하다. 
    // 구현시에는 편의상 i의 제곱으로 구현.
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    //freopen("input.txt", "rt", stdin);
    //getline(std::cin, str);
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isPrime(i))
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}


