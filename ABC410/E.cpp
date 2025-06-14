#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    // 縦：倒したモンスター数，横：使用した魔力の総数
    vector dp(n + 1, vector<int>(m + 1, -1));
    dp[0][0] = h;
    rep(i, 0, n) {
        rep(j, 0, m + 1) {
            // 体力を使用して突破する場合
            if (dp[i][j] >= a[i]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - a[i]);

            // 魔力を使用して突破する場合
            if (j - b[i] >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - b[i]]);
        }
    }

    rep(i, 0, n + 1) {
        bool ok = false;
        rep(j, 0, m + 1) if (dp[n - i][j] != -1) ok = true;
        if (ok) {
            cout << n - i << endl;
            return 0;
        }
    }
}