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

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector graph(n, vector<pair<int, int>>(0));
    rep(i, 0, m) {
        int u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;
    vector<ll> dist(n, LLONG_MAX);
    dist[0] = a[0];
    pq.push({0, a[0]});
    while (!pq.empty()) {
        auto [v, d] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;
        for (auto [next, cost] : graph[v]) {
            if (d + cost + a[next] < dist[next]) {
                dist[next] = d + cost + a[next];
                pq.push({next, dist[next]});
            }
        }
    }

    rep(i, 1, n) cout << dist[i] << " ";
    cout << endl;
}
