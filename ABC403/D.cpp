// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(ALL(a));
    vector<int> cnt(1e6 + 1);
    rep(i, 0, n) cnt[a[i]]++;
    
    // d = 0 は全く別の問題
    if (d == 0) {
        int ans = 0;
        rep(i, 0, 1e6 + 1) {
            if (cnt[i] > 1) ans += cnt[i] - 1;
        }
        cout << ans << endl;
        return 0;
    }

    // 0: 残す, 1: 残さない
    vector dp(d, vector<vector<int>>(2, vector<int>(0)));
    rep(i, 0, d) {
        for (int j = i; j < 1e6 + 1; j += d) {
            rep(k, 0, 2) dp[i][k].push_back(0);
        }
    }

    rep(i, 0, d) dp[i][1][0] = cnt[i];
    rep(i, 0, d) {
        int m = dp[i][0].size();
        rep(j, 1, m) {
            // j番目を残す場合，j-1番目は残してはならない
            dp[i][0][j] = dp[i][1][j - 1];

            // j番目を残さない場合は，j-1番目はどちらでもよい
            dp[i][1][j] =
                min(dp[i][0][j - 1], dp[i][1][j - 1]) + cnt[i + j * d];
        }
    }

    int ans = 0;
    rep(i, 0, d) ans += min(dp[i][0].back(), dp[i][1].back());

    cout << ans << endl;
}
