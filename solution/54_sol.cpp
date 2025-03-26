/**
 * 54. 올바른 괄호(stack)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;


bool isValidParen(const string& str)
{
    stack<char> st;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')') 
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(void)
{
    // string str("");
    // //freopen("input.txt", "rt", stdin);
    // getline(std::cin, str);
	char str[502];
	scanf("%s", str);

    if (isValidParen(str) == true) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}