#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif
using ll = long long;
const ll mod = 1e9 + 7;



ll BinaryExpRecursive(ll a, ll b){
    if(b == 0) return 1;
    ll res = BinaryExpRecursive(a, b/2);
    if(b&1)
        return (((res * res) % mod) * a) % mod;
    else
        return (res*res) % mod;
    
}
int BinaryExpIterative(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
            result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}


int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b;
    debug(BinaryExpRecursive(a, b));
    debug(BinaryExpIterative(a, b));
    return 0;
}