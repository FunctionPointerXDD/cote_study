/** 모두의 약수 
 * 1초 안에 50000을 넣어도 제한시간안에 통과되어야 함.
*/

#include <iostream>

using namespace std;

// 나의 풀이
// int main(void)
// {
//     // string str("");
//     // freopen("input.txt", "rt", stdin);
//     // getline(std::cin, str);
//     int n;
//     cin >> n;

//     cout << 1 << ' ';

//     for (int i = 2; i <= n; ++i)
//     {
//         int cnt = 1;
//         for (int j = 1; j <= i / 2; ++j)
//         {
//             if (i % j == 0) cnt++;
//         }
//         cout << cnt << ' ';
//     }

//     return 0;
// }

/** 더 빠른 방법!  */
int cnt[50001];

int main(void)
{
    int n;
    cin >> n;


    // i의 배수인 배열에 1씩 증가시켜준다. 메모리 상 공간은 더 차지하게 되지만 속도가 nlogn 에 근접해진다.
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
            cnt[j]++;
    }

    for (int i = 1; i <= n; ++i)
        cout << cnt[i] << ' ';
    return 0;
}

