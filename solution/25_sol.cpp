/**
 * 25. 석차 구하기
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

    vector<int> sc(n);
    for (int i = 0; i < n; ++i)
        cin >> sc[i];

    for (int i = 0; i < n; ++i)
    {
        int rank = 1; 
        int cur = sc[i];
        for (int j = 0; j < n; ++j)
        {
            if (cur < sc[j])
                rank++;
        }
        cout << rank << ' ';
    }

    return 0;
}
