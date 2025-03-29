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

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    vector<ll> last(n + 1, -1);
    rep(i, 0, n) {
        ans += (ll)(i - last[a[i]]) * (n - i);
        last[a[i]] = i;
    }

    cout << ans << endl;
}
