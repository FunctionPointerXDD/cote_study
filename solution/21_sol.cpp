/**
 * 21. 카드게임
 */

#include <iostream>

using namespace std;

#define A 1
#define B 2
#define D 3

int eval_winner(int a, int b)
{
    if (a == b)
        return D;
    else if (a > b)
        return A; // A win
    else
        return B; // B win
}


int main(void)
{
    int a[10] = { 0 };
    int b[10] = { 0 };

    for (int i = 0; i < 10; ++i)
        cin >> a[i];
    for (int i = 0; i < 10; ++i)
        cin >> b[i];
    
    int score_a = 0, score_b = 0;
    char winner;
    int draw = 0;
    
    for (int i = 0; i < 10; ++i)
    {
        int eval = eval_winner(a[i], b[i]);
        if (eval == A)
        {
            score_a += 3;
            winner = 'A';
        }
        else if (eval == B)
        {
            score_b += 3;
            winner = 'B';
        }
        else
        {
            score_a++;
            score_b++;
            draw++;
        }
    }

    cout << score_a << ' ' << score_b << '\n';
    if (draw == 10)
    {
        cout << 'D' << endl;
        return 0;
    }

    if (score_a > score_b)
        cout << 'A' << endl;
    else if (score_a < score_b) 
        cout << 'B' << endl;
    else if (score_a == score_b)
        cout << winner << endl;
    
    return 0;
}

