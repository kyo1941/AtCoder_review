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

    vector<int> a(n), b(n), c(n), d(n);
    vector grid(101, vector<int>(101));
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

    rep(i, 0, n) {
        grid[a[i]][c[i]]++;
        grid[a[i]][d[i]]--;
        grid[b[i]][c[i]]--;
        grid[b[i]][d[i]]++;
    }

    rep(i, 0, 101) rep(j, 1, 101) grid[i][j] += grid[i][j - 1];
    rep(i, 1, 101) rep(j, 0, 101) grid[i][j] += grid[i - 1][j];
    
    int ans = 0;
    rep(i, 0, 100) {
        rep(j, 0, 100) {
            if (grid[i][j] > 0) ans++;
        }
    }

    cout << ans << endl;
}