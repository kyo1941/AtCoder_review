// 提出コード（解説を参考にして）

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

    int lo = 0, hi = n / 2 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        bool ok = true;
        rep(i, 0, mid) if (a[i] * 2 > a[n - mid + i]) ok = false;

        if (ok)
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;
}