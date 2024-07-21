// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

bool isKaibun(string s, int k) {
    rep(i, 0, k / 2) if (s[i] != s[k - i - 1]) return false;
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    sort(ALL(s));

    ll ans = 0;
    do {
        ans++;
        rep(i, 0, n - k + 1) {
            if (isKaibun(s.substr(i, k), k)) {
                ans--;
                break;
            }
        }
    } while (next_permutation(ALL(s)));

    cout << ans << endl;
}