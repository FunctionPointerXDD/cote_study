#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int biggest = 0;
    int idx = 0;
    int size = number.length();

    for (int i = 0; i < size; ++i)
    {
        if (biggest < number[i])
        {
            biggest = number[i];
            idx = i;
        }

        if (i == k)
        {
            i = idx;
            // i 는 다음 for문에서 +1 된다!
            ++k;
            answer.push_back(biggest);
            biggest = 0;
        }
    }

    return answer;
}

int main(void)
{
    string number("4177252841");
    size_t k = 4;
    string res = solution(number, k);
    cout << res << endl;
    return 0;
}