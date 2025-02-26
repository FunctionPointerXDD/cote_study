/**
 * 28. N!에서 0의 개수 (소인수 분해 응용)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    int mul_two, mul_five = 0;
    for (int i = 2; i <= n; ++i)
    {
        int tmp = i;
        int j = 2;
        while (tmp > 1)
        {
            if (tmp % j == 0)
            {
                if (j == 2)
                    mul_two++;
                if (j == 5)
                    mul_five++;
                tmp /= j;
            }
            else j++;
        }
    }
    
    // 2와 5의 곱으로 표현될 수 있는 짝의 최대 개수를 출력한다.
    if (mul_two < mul_five)
        cout << mul_two << endl;
    else
        cout << mul_five << endl;

    return 0;
}
