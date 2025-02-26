/**
 * 24. Jolly Jumpers
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/** 내가 처음에 구현한 방식 */
// int main(void)
// {
//     //freopen("input.txt", "rt", stdin);
//     int input;

//     cin >> input;

//     vector<int> n(input);

//     for (int i = 0; i < input; ++i)
//         cin >> n[i];
    
//     vector<int> diff;
//     for (int i = 0; i < input - 1; ++i)
//     {
//         int sub = n[i] - n[i + 1];
//         if (sub < 0) sub *= -1;
//         if (sub == 0 || sub > input - 1)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//         diff.push_back(sub);
//     }

//     sort(diff.begin(), diff.end());
    
//     for (size_t i = 0; i < diff.size() - 1; ++i)
//     {
//         if (diff[i + 1] - diff[i] != 1)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//     }

//     cout << "YES" << endl;

//     return 0;
// }


int main(void)
{
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> vec(n);

    int prev, cur, diff;

    cin >> prev; // 처음으로 입력되는 값을 prev에 저장

    for (int i = 1; i < n; ++i)
    {
        cin >> cur;
        diff = abs(cur - prev);
        if (diff > 0 && diff <= n - 1 && vec[diff] == 0) // diff 가 배열에 인덱스와 범위에 포함되는 정수값 역할을 동시에 한다.
            vec[diff] = 1;
        else
        {
            cout << "NO" << endl;
            return 0;
        }
        prev = cur; // prev 값을 갱신
    }
    
    cout << "YES" << endl;

    return 0;
}
