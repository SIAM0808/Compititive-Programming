#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> prefix(n + 1, 0);
    vector<int> suffix(n + 2, 0);
    for(int i=1; i<=n; i++){
        prefix[i] = __gcd(prefix[i - 1], a[i - 1]);
    }
    for(int i=n; i>=1; i--){
        suffix[i] = __gcd(suffix[i + 1], a[i - 1]);
    }

    //queries
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << __gcd(prefix[l - 1], suffix[r + 1]) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}