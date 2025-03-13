// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector d(n, vector<int>(n));
    rep(i, 0, n) rep(j, i + 1, n) cin >> d[i][j];

    // 2^n個のDPテーブルを作成する
    vector<ll> dp((1 << n), -1);
    dp[0] = 0;
    rep(b, 0, (1 << n) - 1) {
        if(dp[b] == -1) continue;

        rep(i, 0, n) {
            if(!(b & (1 << i))) {
                rep(j, i + 1, n) {
                    if(!(b & (1 << j))) {
                        // 論理和で次の要素に遷移する
                        int nxt = b | (1 << i) | (1 << j);
                        dp[nxt] = max(dp[nxt], dp[b] + d[i][j]);
                    }
                }
            }
        }
    }

    // すべての頂点を選択するわけではないので全部探索
    ll ans = 0;
    rep(i, 0, (1 << n)) ans = max(ans, dp[i]);

    cout << ans << endl;
}