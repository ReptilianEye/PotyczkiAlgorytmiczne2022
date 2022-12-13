#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, j, n, res, dig, to_add;
    string a, b;
    cin >> a;
    cin >> b;
    if (a.size() < b.size())
    {
        string c = a;
        a = b;
        b = c;
    }
    n = a.size() + 1;
    int sum[n]{0};
    for (i = 0; i < n; i++)
        sum[i + 1] = a[i] - '0';
    i = n - 1;
    j = b.size() - 1;
    res = 0;
    do
    {
        dig = b[j] - '0';
        to_add = sum[i] + dig + res;
        sum[i] = (to_add) % 10;
        res = (to_add) / 10;
        i--;
        j--;
    } while (j >= 0);
    while (sum[i] + res > 9)
    {
        to_add = sum[i] + res;
        sum[i] = (sum[i] + res) % 10;
        res = to_add / 10;
        i--;
    }
    sum[i] = sum[i] + res;
    for (i = 0; i < n; i++)
        if (i == 0 && sum[i] == 0)
            continue;
        else
            cout << sum[i];
    return 0;
}
