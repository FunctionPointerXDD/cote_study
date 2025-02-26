#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    char str[102];

    string ans("");

    //freopen("input.txt", "rt", stdin);
    fgets(str, 100, stdin);

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] != ' ')
            ans += tolower(str[i]);
    }
    cout << ans << endl;

    return 0;
}