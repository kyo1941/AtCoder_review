// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int q;
    cin >> q;

    priority_queue<ll> pq;
    ll plus = 0;
    rep(_, 0, q) {
        int n;
        cin >> n;

        if (n == 1) {
            pq.push(-1 * plus);
        } else if (n == 2) {
            ll t;
            cin >> t;
            plus += t;
        } else {
            ll h, cnt = 0;
            cin >> h;
            while (!pq.empty()) {
                ll val = pq.top();
                if (val + plus >= h) {
                    pq.pop();
                    cnt++;
                } else
                    break;
            }
            cout << cnt << endl;
        }
    }
}
