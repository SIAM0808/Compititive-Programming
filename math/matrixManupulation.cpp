#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;
int add(int a, int b) {
  return (a + 1LL + b) % md;
}
int mul(int a, int b) {
  return a * 1LL * b % md;
}
vector<vector<int>> MatMul(vector<vector<int>> A, vector<vector<int>> B) {
  vector<vector<int>> ret(A.size(), vector<int>(B[0].size(), 0));
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B[0].size(); j++) {
      for (int k = 0; k < A[0].size(); k++) {
        ret[i][j] = add(ret[i][j], mul(A[i][k], B[k][j]));
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  vector<vector<int>> Mat = {
    {0, 1},
    {1, 1}
  };
  vector<vector<int>> res = {
    {1, 0},
    {0, 1}
  };
  int n;
  cin >> n;
  n -= 1;
  while(n) {
    if (n & 1) res = MatMul(res, Mat);
    Mat = MatMul(Mat, Mat);
    n >>= 1;
  }
  vector<vector<int>> fibo = {
    {0, 1}
  };
  fibo = MatMul(fibo, res); 
  cout << fibo[0][1] << "\n";
}

// Time Complexity: O(log(n) * 2^3) of O(log(n))
