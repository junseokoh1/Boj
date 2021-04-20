#include <bits/stdc++.h>

using namespace std;

int N;

//1 index
int w[1005];


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>N;

  w[1] = 1; w[2] = 2;

  for(int i= 3; i<= N; i++)
    w[i] = (w[i-1] + w[i-2])%10007;

 
  cout<<w[N];

}

