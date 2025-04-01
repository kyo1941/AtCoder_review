// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    vector dp(n + 1, vector<int>(m + 1));
    rep(i, 0, n) {
        rep(j, 0, m) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }

    string ans = "";
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (dp[x][y] == dp[x - 1][y]) {
            x--;
        } else if (dp[x][y] == dp[x][y - 1]) {
            y--;
        } else if (dp[x][y] == dp[x - 1][y - 1] + 1) {
            ans = s[x - 1] + ans;
            x--, y--;
        }
    }

    cout << ans << endl;
}
