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
const int MOD = 1000000007;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
// int a[N];
int n, m, k;
//=======================

void solve() {
    cin>>n;
    vi a(n);

    fo(i,n)cin>>a[i];

    insert(a.end(),a.begin(),a.end());

    //now slide a window for each different K!!!??

    //what is the largest window where gcd is 1!
    vi ins(2*n,0);

    fo(i,2*n-1)
        if(std::gcd(a[i],a[i+1])!=1)
            ins[i]=1;

    //now if there are consecutive 1's it means no need to insert for those!
    // int l = 0 , r= 0;
        bool pre = 0;
    //longest subarray of 1's!
    // fo(i,2*n-1){

    //     if(ins[i]){
            
    //     }
    // }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // int t = 1;
    // cin >> t;
    // while(t--) {
    //   solve();
    // }
    int i  ; 

    int M = (int)1e9;
    cout<<"100000 "
    fo(i , 100000){
        cout<<M<<" ";
    }

    return 0;
}