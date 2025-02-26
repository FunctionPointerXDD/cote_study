#include <iostream>

using namespace std;

int main(void) 
{
    int num , i, sum = 1;
    cin >> num;

    cout << "1";

    for (i = 2; i < num; i++)
    {
        if (num % i == 0) 
        {
            sum += i;
            cout << " + " << i;
        }
    }
    cout << " = " << sum << endl;

    return 0;
}