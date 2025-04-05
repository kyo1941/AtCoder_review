// 提出コード（ダイクストラ）

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

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector dist(h, vector<int>(w, 1e9));
    pq.push(make_tuple(0, a, b));
    dist[a][b] = 0;
    while (!pq.empty()) {
        int d, x, y;
        tie(d, x, y) = pq.top();
        pq.pop();

        if(d > dist[x][y]) continue;
        rep(i, 0, 4) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            if (s[nx][ny] == '.' && dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                pq.push(make_tuple(dist[nx][ny], nx, ny));
                continue;
            }

            if (s[nx][ny] == '#') {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    pq.push(make_tuple(dist[nx][ny], nx, ny));
                }

                nx += dx[i], ny += dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    pq.push(make_tuple(dist[nx][ny], nx, ny));
                }
            }
        }
    }

    cout << dist[c][d] << endl;
}
