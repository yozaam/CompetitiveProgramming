

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




void solve() {

  int i,j,x,y;

  cin>>n>>m;

  vector<int > bestrate(n,0),bestrank(n,n+1);

  map<int,unordered_set<int> > ratingto;

  fo(i,n){
    cin>>x;
    ratingto[x].insert(i);
    //rating of ith guy
  }

  fo(i , m ){
    //each month!
    fo(j,n){
      cin>>x;

      //rating of ith guy
    } 

    sort(ratingto.begin(),ratingto.end());
    //now check! what is everyones ratin and what is their rank1
    fo(y,n){
      //check if it is the best rank & rating
      if()
    }
  }

  int ans = 0;

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