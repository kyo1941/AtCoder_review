// 提出コード（答え見ながら）

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector graph(n, vector<pair<int, int>>(0));
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;

        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, -w});
    }

    stack<pair<int, ll>> sta;
    vector<ll> dist(n);
    vector<bool> checked(n, false);
    rep(i, 0, n) {
        if (checked[i]) continue;
        sta.push({i, 0});
        checked[i] = true;
        while (!sta.empty()) {
            ll now, d;
            tie(now, d) = sta.top();
            sta.pop();

            for (auto [nxt, w] : graph[now]) {
                if (checked[nxt]) continue;

                checked[nxt] = true;
                dist[nxt] = d + (ll)w;
                sta.push({nxt, dist[nxt]});
            }
        }
    }

    rep(i, 0, n) cout << dist[i] << " ";
    cout << endl;
}