/**
 * 자연수 의 합 구하기
 */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int a, b, i, sum = 0;

    cin >> a >> b;

    for (i = a; i <= b; i++)
    {
        sum += i;
        cout << i;
        if (i != b)
            cout << "+";
    }
    cout << "=" << sum << endl;
    
    return 0;
}