// 提出コード（解説の理屈の部分だけ参照した）

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    n--;

    ll keta = 1;
    ll p = 1;
    while (1) {
        ll tmp = 9 * p;
        if (n <= tmp) break;
        n -= tmp, keta++;
        if (n <= tmp) break;
        n -= tmp, keta++;
        p *= 10;
    }
    n += powl(10, (keta + 1) / 2 - 1) - 1;

    string s = to_string(n);

    cout << s;
    if (keta % 2 == 1) s.pop_back();
    reverse(ALL(s));
    cout << s << endl;
}