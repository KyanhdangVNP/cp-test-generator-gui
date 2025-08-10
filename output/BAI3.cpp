#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI3.INP", "r", stdin); freopen("BAI3.OUT", "w", stdout);

using namespace std;
typedef long long ll;

// |s| <= 200
string s;
int n;
string f[202][202];
// f[i][j]: Xâu ngoặc đúng có độ dài min khi biến đổi xâu [i, j]

int main() {
    boostcode;
    openf;

    cin >> s;
    n = s.size();
    // Với xâu độ dài 1:
    for (int i = 0; i < n; i++) {
        if (s[i]=='(' || s[i]==')') f[i][i] = "()";
        if (s[i]=='[' || s[i]==']') f[i][i] = "[]";
    }
    // Với xâu độ dài len = 2 -> n:
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i+len-1 < n; i++) {
            int j = i+len-1;
            f[i][j] = "";
            // TH nếu 2 ngoặc hợp lệ:
            if ((s[i]=='(' && s[j]==')') ||
                (s[i]=='[' && s[j]==']')) {
                f[i][j] = s[i] + f[i+1][j-1] + s[j];
            }
            // Kiểm tra và update tiếp để tìm thêm min:
            for (int k = i; k < j; k++) {
                string temp = f[i][k] + f[k+1][j];
                if (f[i][j].empty() || temp.size()<f[i][j].size()) {
                    f[i][j] = temp;
                }
            }
        }
    }
    cout << f[0][n-1];

    return 0;
}
/* Test:
([(]
=> ()[()]
([[((())())]()])[]
=> ([[((())())]()])[]
*/