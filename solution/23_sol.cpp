/**
 * 23. 연속 부분 증가수열
 */

#include <iostream>

using namespace std;


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int length = 1;
    int max = -2147483648;

    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] <= arr[i + 1])
            length++;
        else
        {
            if (max < length)
                max = length;
            length = 1;
        }
    }

    if (length == n) // 모든 부분에서 증가하는 경우, max값이 교체가 한번도 안되므로 예외처리를 해준다.
        max = length;

    cout << max << endl;

    return 0;
}

