
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
#define clr(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================
const int MOD = 1000000007;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
int a[N];
int  m, k , i;
//=======================


ll x,y ;


vector<vector<ll> > dp;


ll rec(ll a, ll b , ll n){

  if(dp[a][b]>-1)return dp[a][b];

  if(n==0){
    dp[a][b] = a*b;
   return a*b;
  }

  else if(a==x && b==y){
    dp[a][b] = a*b;
    return a*b;
  }

  else if(a==x){
     dp[a][b] = rec(a,b-1,n-1);
     return dp[a][b];
  }

  else if(b==y){
     dp[a][b] = rec(a-1,b,n-1);
     return dp[a][b];
  }

  dp[a][b] =  min(rec(a-1, b , n-1) , rec(a , b-1, n-1));
  return dp[a][b];

}

void solve() {

    // int n ;
    // cin>>n;

    // bool ok = 0;

    // if(ok){
    //     cout<<"YES\n";
    // }else 
    //     cout<<"NO\n";
    ll a, b, N , n, ans;

    cin>>a>>b>>x>>y>>n;

    // dp.resize(a+1,vector<ll>(b+1,-1));
    // //maybe edge case on size of vector<>

    // ans = rec(a,b,n); // x y doesnt change ;)
    
    //too slow!!!!

    //how about greedy ? 

    //whichever results in a smaller 
    //minus that!!!

    bool ok = 1;

    while(n>0 && ok){


      //ok
      ok = 0;

      if( (a-1)*b < a*(b-1) && a>x){
        //better to take from a ;)
        a--;
        n--;
        ok = 1;
      }
      else if((a-1)*b > a*(b-1) && b>y){
        b--;
        n--;
        ok = 1;
      }


    }//not greedy :'(


    while(n&& a>x){
      a--;
      n--;
    }

    while(n&& b>y){
      b--;
      n--;
    }

    cout<<a*b<<"\n";

    //@WARNING DYNAMIC PROGRAMMING?

    //take it to x and y :/


    //take x and y forward until they utilize all the n values;)
//     n = a-x + b-y - N; //working backwards ;)


//     if(n<=0){
//       //great just return !!
//       cout<<x*y<<"\n";//best ans possible ;)
//       return;
//     }

//     bool ok = 1;

//     while(n>0 && ok){


//       //ok
//       ok = 0;

//       if( (x+1)*y < x*(y+1) && a>x){
//         //better to take from a ;)
//         x++;
//         n--;
//         ok = 1;
//       }
//       else if((x+1)*y > x*(y+1) && b>y){
//         y++;
//         n--;
//         ok = 1;
//       }


//     }//not greedy :'(


//     while(n&& a>x){
//       x++;
//       n--;
//     }

//     while(n&& b>y){
//       y++;
//       n--;
//     }


//     cout<<x*y<<"\n";


    // O(n ?)

    // if(a-x + b-y < n){
    //   cout<<x*y<<"\n";
    //   return;
    // }
      

    //  ans = a*b;


    //  ll aa = a , bb = b;

    //  bool ok = 1;

    // for(int i =   0 ; ok && i <=  n ; i++){

    //   //if i take 'i' from myself 
    //   //b will take all the remaining for himself ;)

    //   int j = n-i; // these many can be removed from neighbour

    //   aa = a-i;


    //   ans = min(ans, max(a-i,x) * max( b-j , y));

    // }


    // cout<<ans<<"\n";
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