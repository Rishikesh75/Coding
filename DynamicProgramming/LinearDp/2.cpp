#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int countWays(int n) {
    if (n <= 2) return n;
    return dp[n] != -1 ? dp[n] : dp[n] = countWays(n-1) + countWays(n-2);
}

int main() {
    int n; 
    cin >> n;
    dp.assign(n+1, -1);
    cout << countWays(n);
}