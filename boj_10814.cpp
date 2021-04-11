#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//a가 b의 앞에 와야할 때 true
//그렇지 않을 때에는 false
bool cmp(pair<int, string> a, pair<int, string> b){

    //나이가 같은 경우
    //if(a.first == b.first)  

    return a.first < b.first;
};

int main() {

  vector<pair<int, string>> vec;
  int N, age;
  string name;

  cin>>N;

  for(int i=0; i< N; i++){
    cin>>age>>name;
    vec.push_back(make_pair(age, name));
  }
  
  //pair를 sort할 때 cmp함수 설정 없이 그냥 해주면 first를 기준으로 정렬을 해줌!
  //이름은 먼저 가입 기준임으로 stable sort
   stable_sort(vec.begin(), vec.end(), cmp);
  //sort(vec.begin(), vec.end(), cmp);        이걸로하면 틀림!

  //vector iteration
  vector<pair<int, string>>::iterator iter;
  for(iter = vec.begin(); iter != vec.end(); iter++)
      cout<<(*iter).first<<" "<<iter->second<<'\n';

}


//다른 사람이 제출한 정답!

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N;
vector<string> n[201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0, a; i < N; i++) {
		string s;
		cin >> a >> s;
		n[a].push_back(s);
	}
	for (int i = 1; i < 201; i++)
		for(string &s : n[i])
			cout << i << ' ' << s << '\n';

	return 0;
}
