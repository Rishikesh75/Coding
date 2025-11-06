#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;

void createarr(int n)
{
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void swapArray(int i_1, int i_2)
{
    int temp = arr[i_1];
    arr[i_1] = arr[i_2];
    arr[i_2] = temp;
}

void MoveArrayLeft(int index, int pivot)
{
    arr[index] = pivot; // just place pivot correctly
}

int swapArr(int pivot, int startindex, int endindex)
{
    int i_1 = startindex;
    int i_2 = endindex;

    while (i_1 <= i_2)
    {
        while (i_1 <= endindex && arr[i_1] < pivot) i_1++;
        while (i_2 >= startindex && arr[i_2] > pivot) i_2--;

        if (i_1 <= i_2)
        {
            swapArray(i_1, i_2);
            i_1++;
            i_2--;
        }
    }

    // return the correct pivot position
    return i_1 - 1;
}

void piviotsort(int startindex, int endindex)
{
    if (startindex >= endindex) return;

    int pivot = arr[startindex];
    int pivotindex = swapArr(pivot, startindex + 1, endindex);

    // place pivot at correct position
    swapArray(startindex, pivotindex);

    // Debug print
    cout << "PivotIndex: " << pivotindex << " for Pivot: " << pivot << endl;

    piviotsort(startindex, pivotindex - 1);
    piviotsort(pivotindex + 1, endindex);
}

void Display()
{
    cout << "Arr:\t";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    createarr(n);
    piviotsort(0, arr.size() - 1);
    Display();
    return 0;
}
