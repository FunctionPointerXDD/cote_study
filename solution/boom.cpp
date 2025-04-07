#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/**
 * 백준 문자열 폭발 문제. (스택을 활용해서 문제를 푼다.)
 */

using namespace std;

string solution(const string &str, const string &boom)
{
    int boom_size = boom.size();
    char eof = boom[boom_size - 1];

    vector<char> st;

    for (int i = 0; i < str.size(); ++i)
    {
        st.push_back(str[i]);
        if (st.back() == eof && st.size() >= boom_size)
        {
            int j = 0;
            for (; j < boom_size; ++j)
            {
                if (st[st.size() - boom_size + j] != boom[j])
                    break;
            }
            if (j == boom_size)
            {
                for (int k = 0; k < boom_size; ++k)
                    st.pop_back();
            }
        }
    }

    return string(st.begin(), st.end());
}

int main(void)
{
    // string str = "mirkovC4nizCCC444";
    // string boom("C4");
    string str("");
    string boom("");
    cin >> str >> boom; 

    string answer = solution(str, boom);
    if (answer == "")
        answer = "FRULA";
    cout << answer << endl;
    return 0;
}