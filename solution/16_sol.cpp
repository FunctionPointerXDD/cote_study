/**
 * Anagram (구글 인터뷰)
 */

#include <iostream>

using namespace std;


int main(void)
{
    string str1("");
    string str2("");
    //freopen("input.txt", "rt", stdin);
    //getline(std::cin, str);
    cin >> str1 >> str2;

    for (size_t i = 0; i < str1.length(); ++i)
    {
        int cnt1 = 0, cnt2 = 0;

        for (size_t j = 0; j < str1.length(); ++j)
        {
            if (str1[j] == str1[i])
                cnt1++;
            if (str2[j] == str1[i])
                cnt2++;
        }
        if (cnt1 != cnt2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}


