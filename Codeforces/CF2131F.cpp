#include <bits/stdc++.h>

#define mkp make_pair
#define mkt make_tuple 
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define sinf 0x3f3f
#define iinf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define lowbit(x) x & -x

using namespace std;

void smiling() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    vector<int> prea(n + 5), preb(n + 5);
    vector<ll> sb(n + 5);
    for (int i = 1; i <= n; i++) {
        prea[i] = prea[i - 1] + (a[i] == '0' ? 1 : -1);
        preb[i] = preb[i - 1] + (b[i] == '1' ? 1 : -1);
    }
    sort(prea.begin() + 1, prea.begin() + n + 1);
    sort(preb.begin() + 1, preb.begin() + n + 1);
    for (int i = 1; i <= n; i++) {
        sb[i] = sb[i - 1] + preb[i];
    }
    ll ans = 1ll * (1 + n) * n * n;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        while (idx <= n && preb[idx] <= prea[i]) {
            idx++;
        }
        ans -= (1ll * (idx - 1) * prea[i] - 1ll * sb[idx - 1]);
        ans += (1ll * (n - idx + 1) * prea[i] - 1ll * (sb[n] - sb[idx - 1]));
    }
    cout << ans / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<< fixed << setprecision(6);

    int _ = 1;
    cin >> _;
    while (_--) {
        smiling();
    }
    return 0;
}
