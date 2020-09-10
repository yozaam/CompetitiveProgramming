

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

ll n , x , y, i, j , k;
//=======================




void solve() {

  string s;

  cin>>n>>k>>s;

  bool ok = 1;


  int r = k;

  int l  = 0;

  int one = 0  , zero = 0 , q = 0;

  fo(i,r){
    if(s[i] == '1')one++;
    else if(s[i] == '0')zero++;
    else q++
  }

  while(r<n){

    if(one>k/2 || zero > k/2){
      ok = 0;
      break ;
    }else{

      if(s[r] == '1')one++;
      else if(s[r] == '0')zero++;
      else q++;
      //good move.
      r++;


      if(s[l] == '1')one--;
      else if(s[l] == '0')zero--;
      else q--;
      l++;
      //window has moved.
    }

  }
  if(one>k/2 || zero > k/2)
      ok = 0;

    if(ok)cout<<"YES";else cout<<"NO";

  cout<<"\n";

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