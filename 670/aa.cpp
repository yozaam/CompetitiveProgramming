
 
 
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
#define ull unsigned long long
 
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<ll>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const int MOD = 1e7;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
int a[N];
int n, m;
int i , j , k;
//=======================
 
// unsigned ll dp[1e9][1e9] = {0};
 
ull dif(const vi & v, ll c){
 
 
  ll poww = 1 ;ull diff = 0;
 
  fo(i , n){
 
    diff += abs(v[i] - poww);
 
    poww *= c; //next position...
 
  }
 
  return diff;
 
}
 
 
void solve() {
  
  //get count of consecutive 0s
  cin>>n;
 
  vi v(n) , gp(n) ; 
  
 
 
  fo(i,n){
    cin>>v[i];
  }
 
  sortall(v);
 
 
 
  ll l = 1 , r = v[n-1] , guess;
 
 
  while(l<r){
 
    guess = l+ (r-l )/ 2;
 
    // cout<<"\n l , r , guess"<<l<<" , " << r << ", " << guess; 
 
    if(pow(guess, n-1) < v[n-1]){
      //this is not good.
      ///try again
      l = guess+1;
    }else{
      r = guess;
    }
 
  }
 
 
 
 
 
 
  //now i will check all values of this until it reaches lowest point
  ll c = 1 ;
 
  // ll cur  = min(dif(v,l) , dif(v,l-1));
 
  ull cur = dif(v,c);
 
  for( ; c  <  l +3; c++){
    //check the cost at each guess of c ?
 
 
 
    //as soon as it stops decreasing then you stop!!!!
    ull next = dif(v,c);
 
    // cout<< next<<"\n"; // ? like this?
 
 
    if(next<cur){
      cur = next;
    }//else{
    //   cout<<"\nedgy!!!!";
    // }
  }
 
 
  cout<< cur<<"\n"; // ? like this?
 
  // //thinking greedy lets see biggest two numbers?
  // gp[0] = 1;
  // fo(i,1,n){
  //   gp[i] = v[i]/v[i-1];
  // }
 
  // //take the most frequently occuring value? or the last value?
 
  // int biggest  = n-1; 
 
  // ans ^ biggest = v.back
 
  // log 
 
  // NOW which GP has sum closest to this?
  // Let me precompute GP sums ?
 
  
  //should I binarysearch to 
  //first sum > the value?
 
  // then compare that and previous sum?
 
  // GP SUM  = (1 - R ^ n ) / 1 - R
 
 
  //now guess the 
  //value of a so a^n > BIG
 
  // start at?
  // ll  l  =  1 , r = BIG  , guess; 
 
  // // cout<<"\nnow to guess power to "<<BIG;
 
 
 
  // while(l<r){
 
  //   guess = l+ (r-l )/ 2;
 
  //   // cout<<"\n l , r , guess"<<l<<" , " << r << ", " << guess; 
 
  //   if(pow(guess, n-1) < BIG){
  //     //this is not good.
  //     ///try again
  //     l = guess+1;
  //   }else{
  //     r = guess;
  //   }
 
  // }
 
  // // cout<<"\n found at l , r , guess"<<l<<" , " << r << ", " << guess; 
 
 
  // //now i just store my difference
  // ll dif = pow(l,n-1) - BIG;
 
  // // cout<<"\ndif of "<<dif<<" or ";
 
  // ll dif1 = (  BIG - pow(l-1,  n-1));
 
  // // cout<<dif1;
 
  // if(dif1<dif)l--; // better answer is lower !!!
 
  // // cout<<" reached? ";
  // // cout<<"\nbest choice for biggest element is ";
 
  // ll ans = 0;
 
  // // cout<<" \n l is "<<l << " m is "<<n-1;
 
  // ll ppow = pow(l,n-1);
 
  // // cout<<" ppow is "<<ppow;
 
  //  m =  n-1 ;
 
  // while(m >= 0){
  //   // cout<<" index ";
  //   ans += abs(ppow  -  v[m]);
  //   ppow/=l;//next position....
  //   m--;
  // }
 
 
  // //whichever is better for biggest  choose that~!
  // // ll biggy = v[n-1];
 
 
 
  // cout<<ans<<"\n";
 
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}