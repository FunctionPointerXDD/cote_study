/**
 * 26. 마라톤
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

    vector<int> sc(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> sc[i];

    cout << 1 << ' ';
    for (int i = 2; i <= n; ++i)
    {
        int rank = i; 
        int cur = sc[i];
        for (int j = i - 1; j > 0; --j)
        {
            if (cur > sc[j])
                rank--;
        }
        cout << rank << ' ';
    }

    return 0;
}
