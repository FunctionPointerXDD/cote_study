/**
 * 자릿수의 합
*/

#include <iostream>

using namespace std;

int digit_sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret = ret + (x % 10);
        x /= 10;
    }
    return ret;
}

int main(void)
{
    // string str("");
    // freopen("input.txt", "rt", stdin);
    // getline(std::cin, str);
    int input;
    cin >> input;

    int max = -2147483648;
    int num, ret, sum;

    for (int i = 0; i < input; ++i)
    {
        cin >> num;
        sum = digit_sum(num);
        if (sum > max)
        {
            max = sum;
            ret = num;
        }
        else if (sum == max)
        {
            if (ret < num)
                ret = num;
        }
    }

    cout << ret << endl;

    return 0;
}


