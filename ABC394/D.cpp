// 解きなおしして提出したコード

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
    string s;
    cin >> s;

    stack<char> sta;
    int idx = 0;
    while (idx < s.size()) {
        if (sta.empty()) {
            sta.push(s[idx++]);
            continue;
        }
        char c = sta.top();
        if (c == '[' && s[idx] == ']')
            sta.pop();
        else if (c == '(' && s[idx] == ')')
            sta.pop();
        else if (c == '<' && s[idx] == '>')
            sta.pop();
        else
            sta.push(s[idx]);
        idx++;
    }

    if (sta.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}