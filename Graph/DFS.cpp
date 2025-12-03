/*
Test Case:

Input:
5 4
1 2
2 3 
3 4
4 5 

Output:
1 2 3 4 5
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
void dfs(vector<vector<int>>& graph, vector<bool>& vis, int par)
{
    vis[par] = true;
    // before entering children
    for(auto child : graph[par]){
        // every child
        if(!vis[child]){
            // child that is not visited
            dfs(graph, vis, child);
            // after returning from child
        }
    }
}
void Solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1);
    for(int i=0; i<e; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> vis(n+1, false);
    dfs(graph, vis, 1);
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