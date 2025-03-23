#include <iostream>
using namespace std;

void pattern_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*" << "\t";
        }
        cout << "\n";
    }
}

void pattern_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*" << "\t";
        }
        cout << "\n";
    }
}
void pattern_3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }
}
void pattern_4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << "\t";
        }
        cout << "\n";
    }
}
void pattern_5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i + 1; j >= 1; j--)
        {
            cout << "*" << "\t";
        }
        cout << "\n";
    }
}
void pattern_6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }
}
void pattern_7(int n)
{
    pair<int, int> range;

    for (int i = 1; i <= n; i++)
    {
        range.first = ((2 * n - 1) / 2) - i + 1;
        range.second = ((2 * n - 1) / 2) + i - 1;
        for (int j = 0; j <= 2 * n - 1; j++)
        {
            if (range.first <= j && j <= range.second)
            {
                cout << "*" << "\t";
            }
            else
            {
                cout << "" << "\t";
            }
        }
        cout << "\n";
    }
}
void pattern_8(int n)
{
}
int main()
{
    int n;
    cout << "Enter the no of Rows: ";
    cin >> n;
    // pattern_1(n);
    // pattern_2(n);
    // pattern_3(n);
    // pattern_4(n);
    // pattern_5(n);
    // pattern_6(n);
    pattern_7(n);
    return (0);
}