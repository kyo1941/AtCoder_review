// 提出コード（二分探索）

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll a = 1, ans = 0;
    while (a * 2 <= n) {
        a *= 2;

        ll b_limit = n / a;
        ll lo = -1, hi = n;
        while (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (mid == 0 || mid <= b_limit / mid)
                lo = mid;
            else
                hi = mid;
        }
        ll b = lo + 1;

        ans += b / 2;
    }

    cout << ans << endl;
}
