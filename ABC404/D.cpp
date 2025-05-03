#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];

    vector<int> k(m);
    vector a(n, vector<int>(0));
    rep(i, 0, m) {
        cin >> k[i];
        rep(j, 0, k[i]) {
            int tmp;
            cin >> tmp;
            tmp--;
            a[tmp].push_back(i);
        }
    }

    int pw = powl(3, n); // 最大値
    vector<int> mask(n); // bit列用の配列
    ll ans = LLONG_MAX;
    rep(i, 0, pw) {
        ll sum = 0;
        int bit = i;
        vector<int> cnt(m);

        // ここで3進数のbit列を作成
        rep(j, 0, n) {
            mask[j] = bit % 3;
            bit /= 3;
        }

        // 0-1の2値じゃないので，回数分だけの積を求める
        rep(j, 0, n) {
            sum += c[j] * mask[j];
            for (int v : a[j]) cnt[v] += mask[j];
        }

        bool ok = true;
        for (int v : cnt)
            if (v < 2) ok = false;
        if (ok) ans = min(ans, sum);
    }

    cout << ans << endl;
}
