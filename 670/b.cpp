
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
size_t   k , i , j , l ,t;
//=======================



void solve() {

     ios_base::sync_with_stdio(false);

    size_t n;
    cin>>n;

    vector<ll> aa(n);

    fo(i,n)cin>>aa[i];

    // cout<<"sorting";

    sortall(aa);
    // cout<<" sorted";
    //five biggest positive ;)
    //OR
    //take 4 negative 1 positive
    //take 2 negative 3 positive
    //take ?

    vector<ll> a(aa.begin(),aa.end());

    size_t nn = n;
    
    if(aa.size() > 10){

        a.clear();

        fo(i,5){
            a.push_back(aa[i]);
            a.push_back(aa[n-i-1]);
        }

        n = a.size();
    }


    ll ans = a[0]* a[1]*a[2]*a[3]*a[4];

    fo(i,n)

    Fo(j,i+1,n)

    Fo(k,j+1,n)

    Fo(l,k+1,n)

    Fo(t,l+1,n)

    ans = max(ans,
        a[i]* a[j]*a[k]*a[l]*a[t]
        );

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