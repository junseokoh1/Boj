#include <bits/stdc++.h>

using namespace std;

//1 index
int r[1005], g[1005], b[1005];

int dp[3][1005];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  for(int i = 1; i<=N; i++)
    cin>>r[i]>>g[i]>>b[i];

  for(int i=1; i<=N; i++){
      dp[0][i] = min(dp[1][i-1], dp[2][i-1]) + r[i];
      dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + g[i];
      dp[2][i] = min(dp[0][i-1], dp[1][i-1]) + b[i];
  }

  cout<<min({dp[0][N], dp[1][N], dp[2][N]});
  
}

//혼자 다시 해봐야됨!!!
