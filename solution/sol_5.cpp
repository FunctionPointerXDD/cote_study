#include <iostream>

using namespace std;

int main(void)
{
    int n, a;
    int max = -2147483648, min = 2147483647;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a > max) max = a;
        if (a < min) min = a;
    }
    cout << max - min << endl;
    return 0;
}