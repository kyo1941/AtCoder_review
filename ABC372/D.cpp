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

    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];

    vector<int> ans(n);
    stack<int> sta;
    for (int i = n - 2; i >= 0; i--) {
        while (!sta.empty() && h[i + 1] > sta.top()) sta.pop();
        sta.push(h[i + 1]);
        ans[i] = sta.size();
    }

    rep(i, 0, n) cout << ans[i] << " ";
    cout << endl;
}
