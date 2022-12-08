#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool czyPalindrom(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}
int ustaw_srodek(string &s, char x, bool &left)
{
    int mid = s.size() / 2;
    int i = 0;
    while (s[mid] != x)
    {
        i++;
        if (s[mid + i] == x)
        {
            left = false;
            s[mid + i] = s[mid];
            s[mid] = x;
        }
        if (s[mid - i] == x)
        {
            left = true;
            s[mid - i] = s[mid];
            s[mid] = x;
        }
    }
    return i;
}
int znajdz(string &s, char x, int kier, int start)
{
    // int start = (prev == -1 ? ((n % 2 == 0) ? n / 2 - 1 : n / 2) : prev) + kier;
    for (int i = start; i >= 0 && i < s.size(); i = i + kier)
    {
        if (s[i] == x)
            return i;
    }
    return -1;
}
int wyrownaj(string &s, int ile, int kier, char za_malo)
{
    char za_duzo = za_malo == 'a' ? 'b' : 'a';
    int sum = 0;
    int i, wsk1, wsk2;
    wsk1 = wsk2 = -1;
    for (i = 0; i < ile; i++)
    {
        wsk1 = znajdz(s, za_malo, kier, wsk1 != -1 ? wsk1 : (s.size() % 2 ? s.size() / 2 + kier : s.size() + (1 - kier) / 2));
        wsk2 = znajdz(s, za_duzo, kier * (-1), wsk2 != -1 ? wsk2 : (s.size() % 2 ? s.size() / 2 + kier * (-1) : s.size() + (1 - kier * (-1)) / 2));

        s[wsk1] = za_duzo;
        s[wsk2] = za_malo;
        sum = sum + abs(wsk1 - wsk2);
    }
    return sum;
}
int ustaw_poprawnie(string &s)
{
    int sum = 0;
    int i, j, wsk_l, wsk_p;
    i = 0;
    j = s.size() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            wsk_l = znajdz(s, s[j], 1, i + 1);
            wsk_p = znajdz(s, s[i], -1, j - 1);
            if (wsk_l - i < j - wsk_p)
            {
                s[wsk_l] = s[i];
                s[i] = s[j];
                sum += wsk_l - i;
            }
            else
            {
                s[wsk_p] = s[j];
                s[j] = s[i];
                sum += j - wsk_p;
            }
        }
        i++;
        j--;
    }
    return sum;
}
int main()
{

    string s;
    cin >> s;
    if (czyPalindrom(s))
        cout << 0 << endl;

    // int *licznosci = new int[2]{0};
    int licznosci[2]{};
    int polowa;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            licznosci[i < s.size() / 2 ? 0 : 1]++;
    }
    // przypadek kiedy sie nie da
    int sum_l = licznosci[0] + licznosci[1];
    if (sum_l % 2 == 1 && s.size() % 2 == 0)
    {
        cout << -1;
        return 0;
    }

    int suma_operacji = 0;
    if (s.size() % 2)
    {
        bool left = false;
        if (sum_l % 2)
            suma_operacji += ustaw_srodek(s, 'a', left);
        else
        {
            suma_operacji += ustaw_srodek(s, 'b', left);
            if (left)
            {
                licznosci[0]++;
                licznosci[1]--;
            }

            else
                licznosci[1]--;
        }
    }

    if (licznosci[0] != licznosci[1])
        suma_operacji += wyrownaj(s, max(abs(licznosci[0] - licznosci[1]) / 2, 1), licznosci[0] > licznosci[1] ? -1 : 1, 'a');
    suma_operacji += ustaw_poprawnie(s);
    // for (auto el : s)
    // {
    //     cout << el;
    // }
    // cout << endl;
    cout << suma_operacji << endl;
    return 0;
}
