/**
 * 27. N!의 표현법
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/** 나의 풀이
 * 
bool isPrime(int &x)
{
    int num = x;

    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    cout << n << '!' << " = ";

    for (int i = 2; i <= n; ++i)
    {
        int cnt = 0;
        if (isPrime(i))
        {
            for (int j = 2; j <= n; ++j)
            {
                int q = j;
                while (q % i == 0) 
                {
                    q /= i;
                    cnt++;
                }
            }
            cout << cnt << ' ';
        }
    }

    return 0;
}

*/


// 소인수 분해를 응용한 풀이
int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        int tmp = i;
        int j = 2;
        while (1)
        {
            // 여기서 j의 값은 i값의 소인수로 전부 소수(prime number)이다.
            // 어떤 수를 소인수 분해하는 과정에서 나오는 인수들은 전부 소수라는 성질을 이용한 것이다.
            if (tmp % j == 0)
            {
                tmp /= j;
                arr[j]++;
            }
            else j++;

            if (tmp == 1) break;
        }
    }

    cout << n << "! = ";
    for (int i = 2; i <= n; ++i)
    {
        if (arr[i] != 0)
            cout << arr[i] << ' ';
    }


    return 0;
}

