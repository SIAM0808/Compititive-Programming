/*
Given an array and some querries. In each querry you will given range[l,r]
you have to add x from l to r
print the final array.
*/

#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    vector<int> prefSum(n + 1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        a[l] += x;
        a[r + 1] += -1 * x;
    }

    for(int i=1; i<=n; i++){
        prefSum[i] = a[i] + prefSum[i-1];
    }

    for(int i=1; i<=n; i++){
        cout << prefSum[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
