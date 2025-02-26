/**
 * 숫자의 총 개수 (small)
 */

#include <iostream>

using namespace std;


int main(void)
{
    // string str("");
    // freopen("input.txt", "rt", stdin);
    // getline(std::cin, str);

    int num;
    cin >> num;

    int cnt = 0;
    for (int i = 1; i <= num; ++i)
    {
        int tmp = i;
        while (tmp > 0)
        {
            tmp /= 10;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}


