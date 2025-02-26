/**
 * 18. 층간소음
 */

#include <iostream>
#include <string>

using namespace std;


int main(void)
{
    //string str("");
    //freopen("input.txt", "rt", stdin);
    //getline(std::cin, str);
    int n, m;
    int cnt = 0;
    int max = -2147483648;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int alert;
        cin >> alert;
        if (alert > m)
            cnt++;
        else
            cnt = 0;
            
        if (max < cnt)
            max = cnt;
    }

    if (max == 0)
        cout << -1 << endl;
    else
        cout << max << endl;


    return 0;
}
