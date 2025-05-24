#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

// U, D, L, R
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int h, w;
vector a(21, vector<ll>(21));
ll ans = 0;

void dfs(vector<vector<bool>> &placed, int x, int y) {
    if (x == h) {
        ll sum = 0;
        rep(i, 0, h) rep(j, 0, w) if (!placed[i][j]) sum ^= a[i][j];

        if (ans < sum) {
            bool ok = true;
            vector checked(h, vector<bool>(w));
            rep(i, 0, h) rep(j, 0, w) {
                if (placed[i][j] && !checked[i][j]) {
                    int cnt_b = 0, cnt_w = 0;   // マス目を白黒で分岐してカウント
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    checked[i][j] = true;
                    while (!que.empty()) {
                        auto [cx, cy] = que.front();
                        que.pop();

                        if ((cx + cy) % 2 == 0)     // 縦横足した値の偶奇で分岐
                            cnt_b++;
                        else
                            cnt_w++;
                        rep(k, 0, 4) {
                            int nx = cx + dx[k], ny = cy + dy[k];
                            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                                continue;
                            if (!placed[nx][ny]) continue;
                            if (checked[nx][ny]) continue;

                            checked[nx][ny] = true;
                            que.push({nx, ny});
                        }
                    }
                    if (cnt_b != cnt_w) ok = false;     // ブロックの配置が可能なのは，白黒の個数が一致した時だけ
                }
            }

            if (ok) ans = sum;
        }

        return;
    }

    int nx = x, ny = y + 1;
    if (ny == w) nx++, ny = 0;
    dfs(placed, nx, ny);

    placed[x][y] = true;
    dfs(placed, nx, ny);
    placed[x][y] = false;
}

int main() {
    cin >> h >> w;
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];

    vector placed(h, vector<bool>(w));
    dfs(placed, 0, 0);

    cout << ans << endl;
}