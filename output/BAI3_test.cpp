#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI3.inp", "r", stdin); freopen("BAI3_test.ans", "w", stdout);

// Nguồn: https://oj.vnoi.info/problem/vobrack

using namespace std;
typedef long long ll;

string s;
int n;
stack<int> st; // Lưu các dấu ngoặc mở (chưa được đóng)
string dp[202][202];
int res;

int main() {
    boostcode;
    openf;

    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i]=='(' || s[i]==')') dp[i][i] = "()";
        else dp[i][i] = "[]";
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i+len-1 < n; i++) {
            int j = i+len-1;
            if ((s[i]=='(' && s[j]==')') ||
                (s[i]=='[' && s[j]==']')) {
                dp[i][j] = s[i] + dp[i+1][j-1] + s[j];
                continue;
            }
            dp[i][j] = "";
            for (int k = i; k < j; k++) {
                if (dp[i][j].empty() ||
                    dp[i][k].size()+dp[k+1][j].size()<dp[i][j].size()) {
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                }
            }
        }
    }
    //cout << dp[0][n-1].size()-n << '\n';
    cout << dp[0][n-1];

    return 0;
}
// Test:
/*
[(()))
=> output: 2
Another test:
[([)]
=> output: 1
*/