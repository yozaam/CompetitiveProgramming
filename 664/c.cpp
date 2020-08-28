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
int n, m, k;
//=======================
vvi dp(201,vi(201));

bool isdp[201][201] = {0};

// int rr(vvi & memo, int row, int cur){
//     if(row == memo.size())return cur;

//     int ans = INT_MAX;

//     int i ;
//     fo(i,memo[0].size()){
//         if(isdp[row][i])ans = min(ans,dp[row][i]);
//         ans = min(ans,rr(memo,row+1,cur|memo[row][i]));
//     }

//     return ans;
// }

void solve() {
  cin >> n >> m;

  int i = 0 , j = 0 ;

  vector<int> a(n),b(m);

  fo(i,n){
    cin>>a[i];
  }
  fo(i,m){
    cin>>b[i];
  }
  int ans = INT_MAX;

  //store all and in a table!!
  vvi memo(n,vi(m));

  fo(i,n){
    fo(j,m){
        memo[i][j] = a[i]&b[j];
    }
  }

  //for each picked up from the table
  //brute force the next one to be picked up ;)
  // ans = rr(memo,0,0);
  //all permuatations of picking from each row!

  //string of size rows each position can be anything from all permuatations of columns

  cout<<ans<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;ß
    while(t--) {
      solve();
    }

    return 0;
}