/**
 * 숫자의 총 개수 (Large)
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

    int num_dig = 0;
    int tmp_num = num;
    while (tmp_num > 0)
    {
        tmp_num /= 10;
        num_dig++;
    }

    int mul_ten = 1;
    for (int i = 1; i < num_dig; ++i)
    {
        cnt += 9 * mul_ten * i; 
        mul_ten *= 10; 
    }

    cnt += (num - mul_ten + 1) * num_dig;

    cout << cnt << endl;

    return 0;
}


