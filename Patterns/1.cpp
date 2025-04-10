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

    for (int i = 1; i < n; i++)
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
    pair<int, int> limit;
    limit.first = 1;
    limit.second = 2 * n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (limit.first <= j && j <= limit.second)
            {
                cout << "*" << "\t";
            }
            else
            {
                cout << " " << "\t";
            }
        }
        limit.first = limit.first + 1;
        limit.second = limit.second - 1;
        cout << "\n";
    }
}
void patter_9(int n)
{
    pattern_7(n);
    pattern_8(n);
}
void pattern_10(int n)
{
    pattern_2(n / 2 + 1);
    pattern_5(n / 2);
}
void pattern_11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1" << "\t";
            }
            else
            {
                cout << "0" << "\t";
            }
        }
        cout << "\n";
    }
}
void pattern_12(int n)
{

    for (int i = 1; i <= n; i++)
    {
        int c = 0;
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j <= i)
            {
                cout << j << "\t";
            }
            else if (j + i > 2 * n)
            {
                if (c == 0)
                {
                    c = i;
                }
                cout << c << "\t";
                c = c - 1;
            }
            else
            {
                cout << "\t";
            }
        }
        cout << "\n";
    }
}
void pattern_13(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << "\t";
            count = count + 1;
        }
        cout << "\n";
    }
}
void pattern_14(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char value = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << value << "\t";
            value = value + 1;
        }
        cout << "\n";
    }
}
void pattern_15(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char value = 'A';
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << value << "\t";
            value = value + 1;
        }
        cout << "\n";
    }
}
void pattern_16(int n)
{
    char c = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c << "\t";
        }
        c = c + 1;
        cout << "\n";
    }
}
void pattern_17(int n)
{
    pair<int, int> range;
    range.first = n;
    range.second = n;

    for (int i = 1; i <= n; i++)
    {
        char c = 'A';
        bool count_decrease = 0;
        bool count_increase = 1;
        for (int j = 1; j <= (2 * n) - 1; j++)
        {

            if (range.first <= j && j <= range.second)
            {

                cout << c << "\t";
                if (j == n)
                {
                    count_decrease = 1;
                    count_increase = 0;
                }
                if (count_decrease == 0 && count_increase == 1)
                {
                    c = c + 1;
                }
                else if (count_decrease == 1 && count_increase == 0)
                {
                    c = c - 1;
                }
            }
            else
            {
                cout << "" << "\t";
            }
        }
        cout << "\n";
        range.first = range.first - 1;
        range.second = range.second + 1;
    }
}
void pattern_18(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char c = 'A' + n - i;
        for (int j = 1; j <= i; j++)
        {
            cout << c << "\t";
            c = c + 1;
        }
        cout << "\n";
    }
}
void pattern_19(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j <= i)
            {
                cout << "*" << "\t";
            }
            else if (i + j > 2 * n)
            {
                cout << "*" << "\t";
            }
            else
            {
                cout << " " << "\t";
            }
        }
        cout << "\n";
    }
}
void pattern_20(int n)
{
    pair<int, int> se;
    se.first = -1;
    se.second = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (se.first == -1 && se.second == -1)
            {
                cout << "*" << "\t";
            }
            else
            {
                if (j < se.first || j > se.second)
                {
                    cout << "*" << "\t";
                }
                else
                {
                    cout << " " << "\t";
                }
            }
        }
        cout << "\n";
        if (se.first == -1 && se.second == -1)
        {
            se.first = n;
            se.second = n + 1;
        }
        else
        {
            se.first = se.first - 1;
            se.second = se.second + 1;
        }
    }
}
void pattern_21(int n)
{
    pattern_20(n);
    pattern_19(n);
}
void pattern_22(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
            {
                cout << "*" << "\t";
            }
            else
            {
                cout << " " << "\t";
            }
        }
        cout << "\n";
    }
}
int min(int i, int j)
{
    if (i <= j)
    {
        return i;
    }
    else
    {
        return j;
    }
}
void pattern_23(int n)
{
    int value;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (i > n && j > n)
            {
                value = min(n - (i - n), n - (j - n));
            }
            else if (i > n)
            {
                value = min(n - (i - n), j);
            }
            else if (j > n)
            {
                value = min(i, n - (j - n));
            }
            else
            {
                value = min(i, j);
            }
            cout << n - value + 1 << "\t";
        }
        cout << "\n";
    }
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
    // pattern_7(n);
    // pattern_8(n);
    // pattern_10(n);
    // pattern_11(n);
    // pattern_12(n);
    // pattern_13(n);
    // pattern_14(n);
    // pattern_15(n);
    // pattern_16(n);
    // pattern_17(n);
    // pattern_18(n);
    // pattern_19(n);
    // pattern_20(n);
    // pattern_21(n);
    // pattern_22(n);
    pattern_23(n);
    return (0);
}