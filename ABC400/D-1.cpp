// 提出コード（0-1 BFS）

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

    deque<pair<int, int>> dq;
    vector dist(h, vector<int>(w, 1e9));
    dq.push_front(make_pair(a, b));
    dist[a][b] = 0;
    while(!dq.empty()) {
        int x, y;
        tie(x, y) = dq.front();
        dq.pop_front();

        rep(i, 0, 4) {
            int nx = x + dx[i], ny = y + dy[i];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            if(s[nx][ny] == '.' && dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                dq.push_front(make_pair(nx, ny));
                continue;
            }

            if(s[nx][ny] == '#') {
                if(dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back(make_pair(nx, ny));
                }

                nx += dx[i], ny += dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back(make_pair(nx, ny));
                }
            }
        }
    }

    cout << dist[c][d] << endl;
}
