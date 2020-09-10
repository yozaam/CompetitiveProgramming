
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



void solve() {

    int n ;
    cin>>n;

    int ans= 0;
    vector<ll> a(n);
    fo(i,n)cin>>a[i];



    //j is a incrementer 
    //i is a decrementer

    int inc = n-1 ; 

    int dec = 0;

    //go backwards 
    //the value that is going to erase it
    //that value will be put in stack?

    reverse(a.begin(),a.end());

    ll killer = 0;

    fo(i,n){

      if(a[i]<0){
        killer += abs(a[i]);
        a[i] = 0;
      }else{
        ll killed = min(killer , a[i]);

        //those many going to get killed 
        //ok 
        a[i] -= killed;
        // cout<<" \n "<<a[i]+killed<<" ";
        killer-=killed;//great they did the work :thumbsup
      }


    }
    ll posi = 0;

    reverse(a.begin(),a.end());

    // cout<<"remainder = " <<
    // killer<<",after killing a=";
    fo(i,n){
      //these couldnt be killedso they will take a charge from us to kill them.
      if(a[i]>0)posi+=a[i];
      // cout<<" "<<a[i];
    }

    // cout<<"\n";

    //as much free work possible do it.

    cout<<posi<<"\n";



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