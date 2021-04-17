#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+10;



//그래프
vector<int> adj[32005];

//1 indexed
int indegree[32005];

//queue
queue<int> q;

//vertex, edges
int N, M;


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  //N명의 학생
  cin>>N>>M;

  for(int i =0; i< M; i++){

      int a, b;

      cin>>a>>b;
      adj[a].push_back(b);

      //indegree값 설정
      indegree[b]++;
  }

  for(int i =1; i<=N; i++)
    if(indegree[i] == 0) q.push(i);
  
  while(!q.empty()){

      int cur = q.front(); q.pop();

      //위상 정렬 처리
      cout<<cur<<" ";

      //indegree값 수정
      for(auto to : adj[cur]){
          indegree[to]--;
          if(indegree[to] == 0) q.push(to);
      }


  }


}

