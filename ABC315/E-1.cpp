// 提出コード（トポロジカルソート＋BFS）

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

    vector graph(n, vector<int>(0)), igraph(n, vector<int>(0));
    vector<int> in(n);
    rep(i, 0, n) {
        int c;
        cin >> c;

        rep(j, 0, c) {
            int p;
            cin >> p;
            p--;

            graph[p].push_back(i);
            igraph[i].push_back(p);
        }
        in[i] = c;
    }

    vector<int> dist(n, 1e9);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nxt : igraph[v]) {
            if (dist[nxt] > dist[v] + 1) {
                que.push(nxt);
                dist[nxt] = dist[v] + 1;
            }
        }
    }

    stack<int> sta;
    vector<int> ans(0);
    rep(i, 0, n) if (in[i] == 0 && dist[i] != 1e9) sta.push(i);

    while (!sta.empty()) {
        int v = sta.top();
        sta.pop();
        ans.push_back(v);

        for (int nxt : graph[v]) {
            if (dist[nxt] == 1e9) continue;
            in[nxt]--;
            if (in[nxt] == 0) sta.push(nxt);
        }
    }

    rep(i, 0, ans.size() - 1) cout << ans[i] + 1 << " ";
    cout << endl;
}
