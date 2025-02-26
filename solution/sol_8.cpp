#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str("");

    //freopen("input.txt", "rt", stdin);
    cin >> str; 

    string ans;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
            ans += str[i];
    }

    int num = stoi(ans);
    int cnt = 0;
    for (int i = 1; i <= num; ++i) 
    {
        if (num % i == 0)
            cnt++;
    }
    cout << num << '\n' << cnt << endl;

    return 0;
}