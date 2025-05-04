#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

/*
8 5
1 2
2 3 
2 4
3 5
6 7
*/
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(int i : adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis);
        }
    }
}
void Solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n + 1);
    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        cnt++;
        dfs(i, adj, vis);
    }
    cout << "Number of connected components: " << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}