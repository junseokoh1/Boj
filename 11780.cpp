#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+10;

//시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

//0번 index는 사용X
int table[105][105];
int nxt[105][105];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;

  cin>>n>>m;

  //table 초기 값!
  for(int i=1; i<=n; i++)
    fill(table[i], table[i] + 105, INF);

  int a,b,c;

  //입력받으면서 바로 table에 적어주기
  for(int i=0; i<m; i++){
    cin>>a>>b>>c;
    table[a][b] = min(table[a][b], c);
    nxt[a][b] = b;
  }

  for(int i=1; i<=n; i++)
    table[i][i] = 0;

  //[i][i]를 0으로 채워야 되는 이유!!!
  // [2][1] + [1][2] < [2][2] 가 항상 성립되니깐! 값이 바뀌어버림!


  for(int i=1; i<=n; i++){
    for(int s = 1; s<=n; s++){
      for(int t=1; t<=n; t++){
        if(table[s][i] + table[i][t] < table[s][t]){
          table[s][t] = table[s][i] + table[i][t];
          nxt[s][t] = nxt[s][i];
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
        if(table[i][j] == INF)
          cout<<0<<" ";
        else  cout<<table[i][j]<<" ";
    }
    cout<<'\n';
  }

  //nxt 확인하기
  

  for(int s = 1; s<=n; s++){
    for(int t = 1; t<=n; t++){
      vector<int> path;
      int cur = s;
      while(cur != t){
        path.push_back(cur);
        cur = nxt[cur][t];
      }
      path.push_back(cur);

      if(path.size() == 1){
          cout<<0<<'\n';
          continue;
      }

      cout<<path.size()<<" ";

      for(auto v : path)
          cout<<v<<" ";
      cout<<'\n';
    }
  }

}

