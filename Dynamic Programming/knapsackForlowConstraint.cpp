

/*
BOUNDED 0/1 knapsack with short constraints
complexity   ->  O(nW)
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
using ll = long long;

ll N = 100002;
ll dp[105][100002];
ll knapsack(ll weight, vector<ll> &v, vector<ll>w, ll i){
    if(i < 0) return 0;
    if(weight <= 0) return 0;        
    if(dp[i][weight] != -1) return dp[i][weight];
    ll value = knapsack(weight, v, w, i - 1);
    if(weight - w[i] >= 0)
    value = max(value, knapsack(weight - w[i], v, w, i - 1) + v[i]);
    return dp[i][weight] = value;

} 
void Solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    for(ll i=0; i<n; i++) cin >> w[i] >> v[i];
    cout << knapsack(W, v, w, n-1);

}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // dp.assign(N, -1);
    memset(dp, -1, sizeof(dp));
    ll t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}