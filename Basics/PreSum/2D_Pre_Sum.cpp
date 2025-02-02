#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int PreSum[N][N];
int a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    // Initialize arrays for each test case
    memset(PreSum, 0, sizeof(PreSum));
    memset(a, 0, sizeof(a));

    // Input array and calculate 2D prefix sum
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            PreSum[i][j] = a[i][j] + PreSum[i - 1][j] + PreSum[i][j - 1] - PreSum[i - 1][j - 1];
        }
    }

    // Query processing
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << PreSum[c][d] - PreSum[a - 1][d] - PreSum[c][b - 1] + PreSum[a - 1][b - 1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
