/**
 * 31. 탄화수소 질량
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //freopen("input.txt", "rt", stdin);

    string str("");
    cin >> str;

    //C == 12g, H == 1g

    int c = 1, h = 1;    
    int h_idx = str.find('H');

    if (h_idx > 1)
        c = stoi(str.substr(1, h_idx - 1));
    if (str[h_idx + 1] != '\0')
        h = stoi(str.substr(h_idx + 1));

    cout << (c * 12) + (h * 1) << endl;

    return 0;
}
