//
// Created by yozaam on 12/06/20.
//

//
// Created by yozaam on 04/06/20.
//

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

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

int n, m,ans;
//=======================

void solve() {

  string astring;

  cin >> n >> astring;

  int i = 0 , j = 0 ;

  vi a(astring.size()+2);
  a[0] = 0;a[1] = 2;
  fo(i,n){
    a[i+2] = (astring[i] - '0');
  }
  a.push_back(2);
  a.push_back(0);

  // vi prefixsum(n);
  // prefixsum[0] = a[0];
  // Fo(i,1,n){
  //   prefixsum[i] = prefixsum[i-1]+a[i];
  // }

  ans = 0;
  int desired = 1;
  // fo(i,n){
  //   Fo(j,i,n){
  //     if(j-i+1 == prefixsum[j] - prefixsum[i]+ a[i])ans++;
  //   }
  // }
  // unordered_map<int,int> prevsum;
  // int cursum =0;
  // fo(i,n){
  //   cursum += a[i];

  //   desired = 
  // }

  // //TLE
  // unordered_multiset<int> vis;
  // vis.insert(0);
  for(int x : a)cout<<x;cout<<"\n";
  int zerocount = 0;
  fo(i,n){
    if(a[i]==0){
      //here zeros started
      zerocount++;
      // if(vis.find(zerocount-1)){
      //   ans+=vis.count(zerocount-1);
      // }
    }else {
      bool only1 = true;
      //how many zeroes will make hime even?
      while(i<n && zerocount>=a[i]-1){
        //eg 4 needs 3 zeroes etc
        if(a[i]!=1)only1=false;
        //he will consume those many zeroes
        zerocount-=a[i++]-1;
        if(!only1)
          ans++;
          //one subarray formed
        //in the end he will become zer0?
      }
      
      zerocount = 0;//consumed coz not enough to satisfy 
    }
  }
  ans-=1;
  reverse(a.begin(),a.end());
  //now check again! :D
  zerocount = 0 ;
  cout<<"bef "<<ans<<"aft?";
  fo(i,n){
    if(a[i]==0){
      //here zeros started
      zerocount++;
      // if(vis.find(zerocount-1)){
      //   ans+=vis.count(zerocount-1);
      // }
    }else {
      bool only1 = true;
      //how many zeroes will make hime even?
      while(i<n && zerocount>=a[i]-1){
        //eg 4 needs 3 zeroes etc
        if(a[i]!=1)only1=false;
        //he will consume those many zeroes
          zerocount-=a[i++]-1;
          if(!only1){
             ans++;//one subarray formed
             // if(a[i]==1)ans++;
          }
         
        }
        //in the end he will become zer0?
      }
      
      zerocount = 0;//consumed coz not enough to satisfy 
    
  }


  //i have double counted the ones! what to do about that?

  cout<<ans<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      // solve();
      cin>>n;
      string s;
      int sum = 0 ; 
      ll ans = 0;
      cin>>s;

      unordered_map<int,int> prevsum;
      prevsum[0]++;//to handle individual 1's

      for(int i = 0 ; i< s.size() ;i++){
        sum += s[i] - '0'; //1
        ans += prevsum[sum-i-1];  // 0 2   
        prevsum[sum - i  -1 ]++;
      }
      cout<<ans<<"\n";
    }

    return 0;
}