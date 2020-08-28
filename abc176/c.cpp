

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


bool bfs(
    unordered_map<int, unordered_set<int> > &paths,int s, int d
    ){
  queue<int> q;
  q.push(s);
  unordered_set<int> vis;
  while(!q.empty()){
    int t = q.front(); q.pop();

    vis.insert(t);

    if(t == d)return 1;

    for(int ne: paths[t]){
      if(!vis.count(ne)){
        q.push(ne);
        // paths[s].insert(ne);
        // paths[ne].insert(s);
      }
    }

    for(int dd:vis){
      paths[s].insert(dd);
    }
  }
  return 0;
}


void solve() {

  int i ;

  cin>>n;
  vi a(n);

  int mini = INT_MAX;
  fo(i,n){
    cin>>a[i];
    if(a[i]<mini)mini= a[i];
  }

  //swap two no. 
  //only if they have gcd=mini

  //prove inverse!
  //find a pair i, j j>i and a[j] > a[i]
  //and the gcd of this pair is ..
  //no wait what if it can be swapped somewhere else?!

  vi b(all(a));

  sortall(b);

  vi wrong;

  fo(i,n)
    if(a[i]!=b[i])
        wrong.push_back(i);

      //every one should be having atleast one 
      //NEIGHBOUR(someone to swap with!!)
     

    unordered_map<int, unordered_set<int> > paths;
  //now i know who all are wrong!
  //let me place those 
  //in a group
  //there i will check for
  // every element if there is any eligible partner
    fo(i,n){

      // if(safe[i])continue;//no need to check him!

      for(int j = i+1 ; j < n ; j++){
        //check if i  and j are swapable!
        //if they are no need to check 
        //them again? o(n) ?
        //haha no we  have to!
        if(gcd(a[i],a[j])==mini){
          paths[i].insert(j);
          paths[j].insert(i);
        }

      }
    }


    // if(paths.size()!= wrong.size()){
    //   cout<<"NO\n";
    //   return ;
    // }



    // //now check is there is path to evveryone's destination!!!!!!1
    //how dfq
    unordered_map<int, unordered_set<int> > pos;

    fo(i,n){
      if(a[i]!=b[i])
        pos[b[i]].insert(i);
    }


    //BFS?
    //every node should have a piont to its destination?
      bool ok  = 1;
     fo(i,n){
        if(a[i]!=b[i]){
          //get og position of a[i]
          //how?
          bool found = 0;
          for(int og : pos[a[i]]){
            if(bfs(paths,i,og)){
              found = 1;
            }
          }
          if(!found){
            ok = false;
            break;
          }
        }
     }

     string ans = "NO";
     if(ok)ans ="YES";

  cout<<ans<<"\n";

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