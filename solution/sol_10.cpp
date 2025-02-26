#include <iostream>
#include <string>
#include <stack>

using namespace std;

/** 올바른 괄효인지 체크하는 문제
 *  나는 stack을 사용했지만, stack을 사용하지 않고, cnt 값을 더하고 빼서 체크할 수도 있다. 
 */

// bool isValidParen(const string& str)
// {
//     stack<char> st;

//     for (size_t i = 0; i < str.length(); ++i)
//     {
//         if (str[i] == '(')
//             st.push(str[i]);
//         else if (str[i] == ')') 
//         {
//             if (st.empty() || st.top() != '(')
//                 return false;
//             st.pop();
//         }
//     }
//     return true;
// }

// int main(void)
// {
//     string str("");
//     //freopen("input.txt", "rt", stdin);
//     getline(std::cin, str);

//     if (isValidParen(str) == true) cout << "YES" << endl;
//     else cout << "NO" << endl;


//     return 0;
// }


int main(void)
{
    string str("");
    freopen("input.txt", "rt", stdin);
    getline(std::cin, str);

    int cnt = 0;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') cnt--;

        if (cnt < 0) //cnt가 음수가 된다는 것은, )가 먼저 시작하는 괄호가 존재한다는 의미이므로 올바른 괄호가 아님!
            break;
    }

    if (cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}