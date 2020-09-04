

/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const int MOD = 1e7;
const int N = 2e6+13, M = N;
//=======================

int n, m;
//=======================

void print(unordered_map<int , unordered_set<int> > & p){

  for(auto & at : p){
    for(auto & x : at.second){
      cout<<" "<<x;
    }
    cout<<" are at "<<at.first<<"\n";
  }

}

void solve() {

 cin>>n;

 vi v(n);
 int i ;

 //on my left all bigger will touch
 //on my right all smaller will touch

 vector<set<int> > touched(n);

 unordered_map<int , unordered_set<int> > position , next;

 fo(i,n){

  cin>>v[i];

  position[i].insert(v[i]);

 }
 int a1 = 5 , a2 = 0;


 //now i will simulate the action>?
 //how? as long as the values jump into the array.

 //okay wait a sec wdym

 //see I will do it like this...


 bool ok = 1;

 int k = 100;
 while(k--){


  //everyone will jump ahead with their value ;)

  //so each position will have a set...


  //the size of the set will track the intersections>?

  //and i will store the neighbours of all elements?


  for(auto & at:position){

    for(int who: at.second){
       next[who+at.first].insert(who);
    //jump from pos 0 to pos 0 + 5
    }

     
  }

  //did everyone jump?
  position  = next ; 


  next.clear();

  print(position);

 }



 //now each element how many bigger 
 //on left and how many smaller right..

 // vi gl(n,0),sr(n,0);




 // fo(i,n){

 //  int j = i ;



 //  while (j>=0){
 //    if(v[j]>v[i]){
 //      gl[i]++;
 //    }
 //    j--;
 //  }

 //  j = i;

 //  while(j<n){
 //    if(v[j]<v[i]){
 //      sr[i]++;
 //    }
 //    j++;
 //  }
 //  // cout<<"at "<<i<<" sr is "<<sr[i]<<" gl is"<<gl[i]<<"\n";
 //   a1 = min(gl[i]+sr[i]+1, a1);
 //   a2 = max(gl[i]+1+sr[i], a2);

 // }

 cout<<a1<<" "<<a2<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
      
    }

    return 0;
}