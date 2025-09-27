#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
using ll = long long;


ll dp[105][100002];
ll knapsack(ll i, ll val, vector<ll> &v, vector<ll> &w){
    // if val == 0 the no weight will reduced
    if(val == 0) return 0;
    if(i < 0) return 1e15;   /// 1e15 is the sentinel or impossible weight 
    if(dp[i][val] != -1) return dp[i][val];

    ll ans = knapsack(i - 1, val, v, w);

    if(val-v[i] >= 0)
    ans = min(ans, knapsack(i - 1, val - v[i], v, w) + w[i]);

    return dp[i][val] = ans;
}
void Solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> v(n), w(n);
    for(ll i=0; i<n; i++) cin >> w[i] >> v[i];
    int mx = 1e5;
    for(ll i=mx; i>=0; i--){
        if(knapsack(n-1, i, v, w) <= W){  // for each value i we have calculated the minimum weight 
            cout << i << endl;          // to findout the maximum value. then find the value of weight 
            break;                      // that is immidiate junior or equal to this
        }
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    memset(dp, -1, sizeof(dp));
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}