// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(m), b(m);
    rep(i, 0, m) cin >> a[i] >> b[i];

    vector<ll> vec(n);
    rep(i, 0, m) vec[(a[i] + b[i]) % n]++;

    ll ans = 0;
    rep(i, 0, n) ans += vec[i] * (m - vec[i]);

    cout << ans / 2 << endl;
}