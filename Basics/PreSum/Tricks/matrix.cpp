#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
inline bool check(int i, int j, int n, int m) {return (0<=i && i<n && 0<=j && j<m);}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void Solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) cin >> a[i][j];
    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int mx = 0;
            for(int k=0; k<4; k++){
                int ni = i + dx[k], nj = j + dy[k];
                if(check(ni, nj, n, m)){
                    mx = max(mx, a[ni][nj]);
                } 
            }
            a[i][j] = min(mx, a[i][j]);
        }
    }
    

    for(auto &row : a){
        for(auto &x : row) cout << x << " ";
        cout << "\n";
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