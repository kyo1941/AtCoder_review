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

    vector<int> k(n);
    vector a(n, vector<int>(0));
    rep(i, 0, n) {
        cin >> k[i];
        rep(j, 0, k[i]) {
            int tmp;
            cin >> tmp;

            a[i].push_back(tmp);
        }
    }

    vector<map<int, int>> mp(n);
    vector vec(n, vector<pair<int, int>>(0));
    vector vec2(n, vector<int>(1e6)); // mapを無理やり置き換えるためのvector
    rep(i, 0, n) rep(j, 0, k[i]) mp[i][a[i][j]]++;
    rep(i, 0, n) for (auto [ke, va] : mp[i]) {
        vec[i].push_back({ke, va});
        vec2[i][ke] = va;
    }

    double ans = 0;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if (i == j) continue;

            double tmp = 0;
            set<int> st;
            for (auto [ke, va] : vec[i]) {
                st.insert(ke);
                double p1 = (double)va / (double)k[i],
                       p2 = (double)vec2[j][ke] / (double)k[j];

                tmp += p1 * p2;
            }

            for (auto [ke, va] : vec[j]) {
                if (st.count(ke)) continue;
                double p1 = (double)va / (double)k[j],
                       p2 = (double)vec2[i][ke] / (double)k[i];
                tmp += p1 * p2;
            }
            ans = max(ans, tmp);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}