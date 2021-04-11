#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//a가 b의 앞에 와야할 때 true
//그렇지 않을 때에는 false
bool cmp(string a, string b){
  return a.size() < b.size();
}

int main() {
  int N;
  vector<string> vec;
  string tmp;

  cin>>N;

  for(int i=0; i< N; i++){
    cin>>tmp;
    vec.push_back(tmp);
  }
  
  //사전순 정렬
  sort(vec.begin(), vec.end());

  //길이순 정렬 - 이때 stable sort를 사용하여 같은 길이 내에서는 사전순을 유지
  stable_sort(vec.begin(), vec.end(), cmp);

  //중복 제거
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  //vector iteration
  vector<string>::iterator iter;
  for(iter = vec.begin(); iter != vec.end(); iter++)
      cout<<*iter<<'\n';

}
