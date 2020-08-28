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
int n, m, k, i;
//=======================

void swap(ll& a , ll& b){
  ll c = a;
  a = b ;b = c;
}

class Solution{


public:

    ll p, f ,ans, sn , an , s, a;


    unordered_map<ll,unordered_map<ll,  unordered_map<ll, ll> > > dp;



    vector<ll> items;
                      //pr = p remaining
    ll filler(int curitem, int pr , int fr){

      //either of..
      //take the item.. in p
      //dont take the item
      //take the item in f

      //you have picked all elements!
      if(curitem == (p+f)){
        return 0;
      }

      //it is in memo
      if(dp[curitem][pr][fr] != -1)
      {
        // cout<<"found";
        return dp[curitem][pr][fr];
      }


          ll ans = 0;

      
      ans =   max(
          ans,
            //not considering ...
          filler(curitem+1,pr,fr)
        );
      
   

      if(pr>=items[curitem])
        ans = max(ans,1+filler(curitem+1,pr-items[curitem] , fr)); 
        


      if(fr>=items[curitem])
        ans = max(ans ,1+filler(curitem+1,pr,fr-items[curitem]));
      


      dp[curitem][pr][fr] = ans;



      return ans;
    }

  void solve() {
  



    cin>>p >> f>>sn>>an>>s>>a;


   


    items.resize(sn,s);

    fo(i, an){
      items.emplace_back(a);//axes///
    }

    int  j , k;
        
    fo(i , an+sn+1)
      {
        fo( j , p+1 ){
          fo ( k , f+1){
            dp[i][j][k] = -1;
          }
        }
      }

    ll ans = filler(0, p , f);


    cout<<ans<<"\n";

  }
}
;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      Solution s;
      s.solve();
    }

    return 0;
}