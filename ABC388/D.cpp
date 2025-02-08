// 提出コード（解説を参考にして）

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

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> imos(n + 1);
    rep(i, 0, n) {
        if(i > 0) imos[i] += imos[i - 1];
        imos[i + 1]++;
        a[i] += imos[i];
        imos[min(n, i + a[i]) + 1]--;
        a[i] = max(0, a[i] - (n - i - 1));
    }
    
    rep(i, 0, n) cout << a[i] << " ";
    cout << endl;
}