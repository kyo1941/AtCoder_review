#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int n, m, ans = 1e9;
vector graph(1e3, vector<pair<int, int>>(0));

// ある地点において，そこまでの重みを保持
vector checked(1e3, vector<bool>((1 << 10) + 1));

void dfs(int v, int d) {
    if (v == n - 1) ans = min(ans, d);

    for (auto [nxt, cst] : graph[v]) {
        // 同じ重みをもってその頂点を探索済みであればスキップ
        if (checked[nxt][d ^ cst]) continue;

        checked[nxt][d ^ cst] = true;
        dfs(nxt, (d ^ cst));
    }
}

int main() {
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;

        graph[a].push_back(make_pair(b, w));
    }
    checked[0][0] = true;
    dfs(0, 0);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
