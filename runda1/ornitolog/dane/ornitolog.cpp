#include <iostream>
#include <math.h>
using namespace std;

int count_fixes(bool t[], int n)
{
    int fixes = 0;
    int n_p = 0;
    for (int i = 1; i < n; i++)
    {
        if (!t[i])
            n_p++;
        else if (n_p != 0)
        {
            fixes += floor(n_p / 2) + n_p % 2;
            n_p = 0;
        }
    }
    return n_p == 0 ? fixes : fixes + floor(n_p / 2) + n_p % 2; // if n_p is not 0 we have to add laking moves
}
int main()
{
    int n, temp, inf;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        t[i] = temp;
        inf = max(inf, abs(temp));
    }
    inf++;

    bool is_lower = true;
    int prev = t[0];
    bool corr1[n]{};
    bool corr2[n]{};
    corr1[0] = corr2[0] = true;
    for (int i = 1; i < n; i++)
    {
        corr1[i] = (t[i] < prev && is_lower || t[i] > prev && !is_lower);
        corr2[i] = (t[i] < prev && !is_lower || t[i] > prev && is_lower);
        is_lower = !is_lower;
        prev = t[i];
    }
    cout << min(count_fixes(corr1, n), count_fixes(corr2, n)) << "\n";
    return 0;
}
