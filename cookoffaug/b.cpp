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

void solve() {
  
  int a0,a1,a2, b0,b1,b2;

  cin>>a0>>a1>>a2>>b0>>b1>>b2;

  //now maximise how many 2s can be in the answer!
  int ans = 0;

  //lets match all these 2s with 1s from b
  if(a2>b1){
    a2-=b1;
    ans+= 2*b1;
    b1= 0;
  }else if(b1>=a2){
    ans += 2*a2;//yayy all twos in ans!
    b1 -= a2;//paired these 
    a2= 0;
  }

  //now minimize the negative nos.
  //try to make them all zero!
  //cleverly... all 1s in a should be matched with 1 or 0 from the other batch...
  //if there are WAIT NO NEED
  //10 = 0 01 = 0 11 = 0 00 = 0 20 = 0 02 = 0 hahah
    
  //just the pai 1 2 is -2 ! 
  //so try to match all the twos in the 
  // b with a 0 !!!(or 2 coz 2 is matched already?)

  //all 1s should go to the remaining 1s and zeroes
  int safe = b1+b0;
  if(safe<a1){
      a1-=safe;//pair those safely into 0s
      //remaing ka kya karna hain??
      //pair them with the twos what else
      int pairs = min(a1,b2);
      ans-=2*pairs;
  }

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