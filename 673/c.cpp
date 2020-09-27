
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

int  m, k , i;
//=======================

void solve() {
    ll n ,x,y,k,l,sz;
    cin>>n;
    vi v(n),c(n,-1);
    fo(i,n)cin>>v[i];

    unordered_map<int,int> window;

    vi res(n,-1);

    //brute force

    Fo(sz,1,n+1){
        //size of subarray
        //only keep track of first subarray
        window.clear();
        fo(i,sz)window[v[i]]++;
        Fo(i,sz,n){
            l=i-sz;
            if(window.count(v[i]))//only if it was inside the initial
                window[v[i]]++;
            window[v[l]]--;
            if(window[v[l]]==0)window.erase(v[l]);
        }
        if(!window.empty()){
            int mini=window.begin()->first;
            for(auto &cc:window){
                mini=min(cc.first,mini);
            }
            res[sz-1]=mini;
        }
    }
    fo(i,n)cout<<res[i]<<" ";cout<<"\n";

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