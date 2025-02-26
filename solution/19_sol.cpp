/**
 * 19. 분노 유발자
 */

#include <iostream>
#include <string>

using namespace std;


// int main(void)
// {
//     //string str("");
//     //freopen("input.txt", "rt", stdin);
//     //getline(std::cin, str);
//     int n;
//     cin >> n;

//     int *arr = new int[n]; 

//     for (int i = 0; i < n; ++i)
//         cin >> arr[i];

//     int cnt = 0; 
//     for (int i = 0; i < n; ++i)
//     {
//         int height = arr[i];
//         for (int j = i + 1; j < n; ++j)
//         {
//             if (height <= arr[j])
//                 break;
//             if (j == n - 1)
//                 cnt++;
//         }
//     }

//     cout << cnt << endl;

//     delete []arr;

//     return 0;
// }


// 뒤에서 부터 분노 유발자를 찾는 것이 더 빠름!
int main(void)
{
    int n;
    cin >> n;

    // 이렇게 구현하면 밑에서 계산할 때, 더 가독성 있게 짤 수 있음.
    int *arr = new int[n + 1]; 
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    int cnt = 0; 
    int max = arr[n];
    for (int i = n - 1; i >= 1; --i)
    {
        if (max < arr[i])
        {
            max = arr[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    delete []arr;

    return 0;

}


