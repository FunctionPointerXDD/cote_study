/**
 * 29. 3의 개수는? (small)
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

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = i;
        while (tmp > 0)
        {
            if (tmp % 10 == 3)
                cnt++;
            tmp /= 10; 
        }
    }

    cout << cnt << endl;
    return 0;
}
