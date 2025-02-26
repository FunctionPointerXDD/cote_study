#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string id("");

    //freopen("input.txt", "rt", stdin);
    cin >> id;

    int birth = stoi(id.substr(0, 2));
    int hype = id.find('-');   
    char diff = id[hype + 1];

    int old;
    char sex;

    if (diff == '1' || diff == '3')
        sex = 'M';
    else
        sex = 'W';
    
    if (diff == '1' || diff == '2')
        old = 2019 - (1900 + birth) + 1;
    else
        old = 2019 - (2000 + birth) + 1;

    cout << old << ' ' << sex << endl;
    return 0;
}