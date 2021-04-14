#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    set<string, greater<string>> s;

    string name, state;
    int N;
    cin>>N;

    for(int i=0; i< N; i++){
          cin>>name>>state;

          if(state == "leave")
            s.erase(name);
          else
            s.insert(name);
    }

    for(auto str : s)
      cout<<str<<'\n';


}
