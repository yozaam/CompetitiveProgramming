
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
#define ll unsigned long long
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
ll   k , i , j;
//=======================



void solve() {

    ll n ,m;
    cin>>n;

    unordered_set<ll> vis;

    ll ans= 0;
    vector<ll> a;

    a.reserve(2000);

    fo(i,n){
        cin>>m;

        
            a.push_back(m);
        
    };
    sort(all(a) , greater<ll>());

     n = a.size();
    ll gcdd = a[0];
    vis.clear();

    Fo(i,1,n){

        //he is biggest? 
        //great..
        //swap him with biggest gcd till now!
        Fo(j,i+1,n){
            //
            if(__gcd(a[j],gcdd) > __gcd(a[i],gcdd)){
                ll t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
        //founf who is in i position
        gcdd= __gcd(gcdd,a[i]);
    }


    // while(!pq.empty()){
    //     m = pq.top();
    //     pq.pop();
    //     //now transfer ()him to other pq ;)
    //     while(!pq.empty()){
    //         ppq.push_back(__gcd(pq.top(), m));
    //         pq.pop();
    //     }

    //     while(!ppq.empty())
    //     {
    //         pq.push(ppq.back());
    //         ppq.pop_back();
    //     }

    //     cout<<m<<" ";
    // }

    // m = a.back();
    // a.pop_back();
    // ll gcdd = m;
    // cout<<m<<" ";

    // // fo(i,a.size())cout<<a[i]<<" ";cout<<"\n";

    // while(!a.empty()){
    //     //now ? 

    //     //sort it? based on? 

    //     sort(a.begin(),a.end(),
    //         [&gcdd](ll& a , ll& b){
    //             return __gcd(a,gcdd) < __gcd(b,gcdd);
    //     });

    //     m = a.back();
    //     a.pop_back();
    //     gcdd = __gcd(m,gcdd);
    //     cout<<m<<" ";
    //     //take last element again?
    //     // fo(i,a.size())cout<<a[i]<<" ";cout<<"\n";

    // }


    fo(i,n){
        cout<<a[i] <<" ";
    }

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