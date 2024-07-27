// 提出コード（解説ガン見）

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(ALL(a));

    rep(_, 0, q) {
        int b, k;
        cin >> b >> k;

        int lo = -1, hi = 1e9;
        while (lo + 1 < hi) {
            int mi = (lo + hi) / 2;
            
            // 範囲内にいくつ点が含まれるか
            int c = upper_bound(ALL(a), b + mi) - lower_bound(ALL(a), b - mi);

            // 二分探索によって適切な距離を特定
            if (c >= k)
                hi = mi;
            else
                lo = mi;
        }
        cout << hi << endl;
    }
}
