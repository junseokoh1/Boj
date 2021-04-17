#include <bits/stdc++.h>

using namespace std;

//1 indexed
int indegree[1005];

//time
int weight[1005];

//queue
queue<int> q;

//vertex, edges
int T, N, K;


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  //N명의 학생
  cin>>T;

  //전체 T 횟수만큼 !
  while(T--){

      cin>>N>>K;

      //그래프
      vector<int> adj[1005];

      //weight, indegree 배열 초기화
      fill(indegree, indegree + 1005, 0);
      fill(weight, weight + 1005, 0);

      //건물당 걸리는 시간
      //1 index?
      for(int i=1; i<=N; i++){
        int w;
        cin>>w;
        weight[i] = w; 
      }

      //건설 규칙
      for(int i =0; i< K; i++){

          int a, b;

          cin>>a>>b;
          adj[a].push_back(b);

          //indegree값 설정
          indegree[b]++;
      }

      int W;
      cin>>W;

      vector<int> TS;

      for(int i =1; i<=N; i++)
        if(indegree[i] == 0){ q.push(i); TS.push_back(i); }
      
      while(!q.empty()){

          int cur = q.front(); q.pop();

          //위상 정렬 처리
          //cout<<cur<<" ";
          TS.push_back(cur);

          //indegree값 수정
          for(auto to : adj[cur]){
              indegree[to]--;
              if(indegree[to] == 0) q.push(to);
          }
      }

      int answer[1005];
      fill(answer, answer+1005, 0);
      for(auto v : TS){
          for(auto e : adj[v]){
              answer[e] = max(answer[e], answer[v] + weight[v]);
          }
      }

      cout<<answer[W] + weight[W]<<'\n';

      

  }


}

