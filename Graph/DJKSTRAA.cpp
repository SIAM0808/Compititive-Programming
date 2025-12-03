#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
void dijkstra()
{
    
}
void Solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i=0; i<e; i++){
        int x, y;
        cin >> x >> y;
        int w;
        cin >> w;
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }
    int src;
    cin >> src;
    vector<int> dis(n+1, INT_MAX);
    dijkstra(graph, dis, src);
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