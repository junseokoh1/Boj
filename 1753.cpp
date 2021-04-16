#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+10;

//힙 - priority_queue
//STL pair를 힙에 삽입.  first는 거리를 의미 second는 정점의 번호를 의미
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;     //greater!!! 조심하기!!!

//그래프 - vector<pair<int, int>>
//cost, 정점
vector<pair<int, int>> edges[20005];

//distance table
//1 index???
int dis[20005];

//vertex, edges
int V, E;

void djs(int FV){

  //1. 힙에 (0, 시작점)을 넣기
  PQ.push({0, FV});

  //table 초기값 설정
  dis[FV] = 0;

  //힙이 빌때까지 반복
  while(!PQ.empty()){

      //2. 꺼낸 후 비교
      pair<int, int> tmp = PQ.top(); PQ.pop();
      int idx = tmp.second; int dist = tmp.first;
      if(dis[idx] != dist)  continue;


      //3.
      for(auto v : edges[idx]){
          int cost = v.first, nidx = v.second;
          //table의 값보다 작은 경우
          if(dist + cost < dis[nidx]){
              dis[nidx] = dist + cost;
              PQ.push(make_pair(dis[nidx], nidx));
          }

      }

  }

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int FV;
  cin>>V>>E>>FV;
  fill(dis, dis + V + 1, INF);
  int u, v, w;
  for(int i = 0; i< E; i++){
      cin>>u>>v>>w;

      edges[u].push_back({w, v});
  }

  djs(FV);

  for(int i = 1; i<=V; i++){
      if(dis[i] == INF) cout<<"INF"<<'\n';
      else  cout<<dis[i]<<'\n';
  }
 

}

