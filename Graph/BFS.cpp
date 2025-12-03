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
void bfs(vector<vector<int>>& graph, vector<bool>& vis, int par)
{
    queue<int> q;
    q.push(par);
    vis[par] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child : graph[node]){
            if(!vis[child]){
                vis[child] = true;
                q.push(child);
            }
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
    bfs(graph, vis, 1);
    for(int i=1; i<=n; i++){
        if(vis[i])
            cout << i << " ";
    }
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