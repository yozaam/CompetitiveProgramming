//
// Created by yozaam on 12/06/20.
//

//
// Created by yozaam on 04/06/20.
//



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
vi g[N];
int a[N];
int n, m, k , i , j;
//=======================

void solve() {
  
  cin>>n;

  vi r1(n);

  fo(i,n){
    fo(j, n){
      if(i==0){
        cin>>r1[j];
      }else{
        cin>>k;
      }
    }
  }


  vector<bool> f(n,0);
  int ans = 0 ;
  bool fu = 0;
  fo(i,n)
  {
    if(i+1 == r1[i]){
      f[i]=1;
      
    }else{
      fu =1;
    }
  }

  // for(auto b : f)cout<<b<<" ";


  reverse(f.begin(),f.end());

  f.pop_back();
  int c= 0;
  

  i = 0;

  while(i<f.size() && f[i]==1)i++;

  //now i am at first 0 position..


  for(  ; i < f.size() ; i++){
    if(i!=f.size()-1 && f[i]!=f[i+1]){
      c++;//its a flip!
    }
  }

  //now i know how many flips are there !!!

  if(!fu)cout<<"0\n";
  else
  cout<<c+1<<"\n";
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