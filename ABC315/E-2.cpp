// 提出コード（メモ化再帰DP）

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int dfs(vector<vector<int>> &graph, vector<pair<int, int>> &dp,
        vector<bool> &checked, int v) {
    if (dp[v].first != -1) return dp[v].first;

    dp[v].first = 0;
    for (int nxt : graph[v]) {
        if (checked[nxt]) {
            dp[v].first = max(dp[v].first, dfs(graph, dp, checked, nxt) + 1);
        }
    }
    return dp[v].first;
}

int main() {
    int n;
    cin >> n;

    vector graph(n, vector<int>(0)), igraph(n, vector<int>(0));
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
    }

    vector<bool> checked(n);
    stack<int> sta;
    sta.push(0);
    checked[0] = true;
    while (!sta.empty()) {
        int v = sta.top();
        sta.pop();

        for (int nxt : igraph[v]) {
            if (!checked[nxt]) {
                sta.push(nxt);
                checked[nxt] = true;
            }
        }
    }

    vector<pair<int, int>> dp(n);
    rep(i, 0, n) dp[i] = make_pair(-1, i);
    rep(i, 0, n) dfs(graph, dp, checked, i);
    sort(ALL(dp));
    reverse(ALL(dp));
    rep(i, 0, n) if (dp[i].first > 0) cout << dp[i].second + 1 << " ";
    cout << endl;
}
