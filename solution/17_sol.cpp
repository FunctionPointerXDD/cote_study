/**
 * 17. 선생님 퀴즈
 */

#include <iostream>

using namespace std;


int main(void)
{
    //string str1("");
    //freopen("input.txt", "rt", stdin);
    //getline(std::cin, str);
    string str("");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num, res;
        cin >> num >> res;

        int ans = 0;
        for (int j = 1; j <= num; ++j)
            ans += j;
        
        if (ans == res)
            str += "YES\n";
        else
            str += "NO\n";
    }

    cout << str;

    return 0;
}
