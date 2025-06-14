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

    vector<int> vec(n);
    rep(i, 0, n) vec[i] = i + 1;

    int offset = 0;
    rep(_, 0, q) {
        int t;
        cin >> t;

        if (t == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            vec[(p + offset) % n] = x;
        } else if (t == 2) {
            int p;
            cin >> p;
            p--;
            cout << vec[(p + offset) % n] << endl;
        } else {
            int k;
            cin >> k;

            // 配列よりも大きい回数の操作は無意味
            k %= n;

            // 先頭の位置を変更する
            offset = (offset + k) % n;
        }
    }
}