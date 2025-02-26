/**
 * 30. 3의 개수는?(large) -> 난이도 상
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 인프런 강의를 참고하자...
int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    int ret = 0;
    int lt, rt, cur, k = 1;
    while (lt != 0)
    {
        lt = n / (k * 10);
        cur = (n / k) % 10;
        rt = n % k;

        if (cur > 3)
            ret += (lt + 1) * k;
        else if (cur < 3)
            ret += (lt * k);
        else if (cur == 3)
            ret += ((lt * k) + (rt + 1));

        k *= 10;
    }

    cout << ret << endl;
    return 0;
}
