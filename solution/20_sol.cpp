/**
 * 20. 가위 바위 보
 */

#include <iostream>

using namespace std;

#define S 1
#define R 2
#define P 3

int eval_winner(int a, int b)
{
    if (a == b)
        return 0;
    else if ((a == S && b == P) || (a == R && b == S) || (a == P && b == R))
        return 1; // A win
    else
        return -1; // B win
}


int main(void)
{
    int n;
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];


    for (int i = 0; i < n; ++i)
    {
        int eval = eval_winner(a[i], b[i]);
        if (eval == 1)
            cout << "A" << '\n';
        else if (eval == -1)
            cout << "B" << '\n';
        else
            cout << "D" << '\n';
    }

    delete []a;
    delete []b;

    return 0;
}

