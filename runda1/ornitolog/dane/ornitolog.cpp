#include <iostream>
#include <math.h>
using namespace std;

int znajdz_podciag(bool t[], int n)
{
    int score = 0;
    int n_p = 0;
    for (int i = 1; i < n; i++)
    {
        if (!t[i])
        {
            n_p++;
        }
        else if (n_p != 0)
        {
            int inc = floor(n_p / 2) + n_p % 2;
            score = score + inc;
            n_p = 0;
        }
    }
    if (n_p != 0)
    {
        int inc = floor(n_p / 2) + n_p % 2;
        score = score + inc;
        n_p = 0;
    }
    return score;
}
void print_t(bool t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << (t[i] ? 1 : 0) << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    // int *t = new int[n];
    int t[n];
    int temp;
    int inf;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        t[i] = temp;
        inf = max(inf, abs(temp));
    }

    inf++;
    bool mniejsza = true;
    int good = 1;
    int prev = t[0];
    bool fit[n]{};
    fit[0] = true;
    // for (int i = 0; i < n; i++)
    //     cout << t[i] << " ";
    // cout << "\n";
    for (int i = 1; i < n; i++)
    {
        if (t[i] < prev && mniejsza || t[i] > prev && !mniejsza)
        {
            fit[i] = true;
            good++;
        }
        else
            fit[i] = false;

        mniejsza = !mniejsza;
        prev = t[i];
    }
    // for (int i = 0; i < n; i++)
    //     cout << t[i] << " ";
    // cout << "\n";
    // print_t(fit, n);
    int v1 = znajdz_podciag(fit, n);
    mniejsza = false;
    prev = t[0];
    for (int i = 1; i < n; i++)
    {
        if (t[i] < prev && mniejsza || t[i] > prev && !mniejsza)
        {
            fit[i] = true;
            good++;
        }
        else
            fit[i] = false;
        mniejsza = !mniejsza;
        prev = t[i];
    }
    // print_t(fit, n);
    int v2 = znajdz_podciag(fit, n);
    cout << min(v1, v2) << "\n";
    return 0;

    int score = 1;

    // cout << endl;

    for (int i = 1; i < n; i++)
    {
        if (t[i] < prev && mniejsza || t[i] > prev && !mniejsza)
        {
            score++;
            prev = t[i];
        }
        else
            prev = mniejsza ? -inf : inf;
        mniejsza = !mniejsza;
    }

    // int wyn;
    // if (score < n / 2)
    //     score = n - score;
    // wyn = n - score;
    // if (wyn == score)
    // {
    // int dobrze = znajdz_podciag(fit, n, true);
    // int zle = znajdz_podciag(fit, n, false);
    // cout << dobrze << " " << zle;
    // cout << min(dobrze, zle) << "\n";
    // }
    // else
    //     cout << wyn << "\n";

    return 0;
}
