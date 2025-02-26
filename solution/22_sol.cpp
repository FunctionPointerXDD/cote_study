/**
 * 22. 온도의 최대값
 */

#include <iostream>

using namespace std;


int main(void)
{
    int n, k;

    //freopen("input.txt", "rt", stdin);

    cin >> n >> k;

    int *arr = new int[n];
    
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    

    int sum = 0;
    for (int i = 0; i < k; ++i) // first sum;
        sum += arr[i];

    int max = sum;
    // for (int i = 1; i <= n - k; ++i)
    // {
    //     sum -= arr[i - 1];
    //     sum += arr[i + k - 1];
    //     if (max < sum)
    //         max = sum;
    // }

    //more simple code
    for (int i = k; i < n; ++i)
    {
        sum = sum + (arr[i] - arr[i - k]);
        if (max < sum)
            max = sum;
    }

    cout << max << endl;
    
    return 0;
}

