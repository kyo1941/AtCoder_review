// 提出コード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector graph(n, vector<int>(0)), rev_graph(n, vector<int>(0));
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    priority_queue<tuple<ll, ll, bool>, vector<tuple<ll, ll, bool>>,
                   greater<tuple<ll, ll, bool>>>
        pq;
    vector dist(n, vector<ll>(2, LLONG_MAX));
    dist[0][0] = 0;
    pq.push({0, 0, false});
    while (!pq.empty()) {
        ll d, u, b;
        tie(d, u, b) = pq.top();
        pq.pop();

        if (d > dist[u][b]) continue;

        for (int nxt : graph[u]) {
            int cos = 1;
            if (b) {
                cos += x;
                if (d + cos < dist[nxt][1]) {
                    dist[nxt][1] = d + cos;
                    pq.push({dist[nxt][1], nxt, false});
                }
            } else {
                if (d + cos < dist[nxt][0]) {
                    dist[nxt][0] = d + cos;
                    pq.push({dist[nxt][0], nxt, false});
                }
            }
        }

        for (int nxt : rev_graph[u]) {
            int cos = 1;
            if (!b) {
                cos += x;
                if (d + cos < dist[nxt][0]) {
                    dist[nxt][0] = d + cos;
                    pq.push({dist[nxt][0], nxt, true});
                }
            } else {
                if(d + cos < dist[nxt][1]) {
                    dist[nxt][1] = d + cos;
                    pq.push({dist[nxt][1], nxt, true});
                }
            }
        }
    }

    cout << min(dist.back()[0], dist.back()[1]) << endl;
}
