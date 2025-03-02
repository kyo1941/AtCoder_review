// 提出コード

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

    vector<int> PigToGro(n), GroToNes(n), NesToGro(n);
    rep(i, 0, n) {
        PigToGro[i] = i;
        GroToNes[i] = i;
        NesToGro[i] = i;
    }

    vector<int> ans(0);
    rep(_, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            PigToGro[a] = NesToGro[b];
        } else if (t == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            swap(GroToNes[NesToGro[a]], GroToNes[NesToGro[b]]);
            swap(NesToGro[a], NesToGro[b]);
        } else {
            int a;
            cin >> a;
            a--;

            ans.push_back(GroToNes[PigToGro[a]] + 1);
        }
    }

    rep(i, 0, ans.size()) cout << ans[i] << endl;
}
