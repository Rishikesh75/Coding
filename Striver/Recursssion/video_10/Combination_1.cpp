#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> arr;
set<vector<int>> finalans;

void Createarr(int n) {
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// backtracking function
void f(int idx, int sum, vector<int>& Ans) {
    if (sum < 0) return;
    if (sum == 0) {
        vector<int> sortedAns = Ans;
        sort(sortedAns.begin(), sortedAns.end());
        finalans.insert(sortedAns);  // automatically avoids duplicates
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        Ans.push_back(arr[i]);
        f(i, sum - arr[i], Ans);
        Ans.pop_back();
    }
}

void Display() {
    for (auto vec : finalans) {
        cout << "Arr:\t";
        for (int val : vec) cout << val << "\t";
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    Createarr(n);
    int sum;
    cin >> sum;
    vector<int> subans;
    f(0, sum, subans);
    Display();
    return 0;
}
