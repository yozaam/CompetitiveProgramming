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
int a[N];
int  m, k , i;
//=======================

void solve() {

    int n ;
    cin>>n;

    m = n;
    unordered_map<char, int> fre;
    string s;
    while(m--){
        cin>>s;

        for(char c : s){
            fre[c]++;
        }
    }

    bool ok = 1;


    for(auto x : fre){   {'a' : 4}
        // cout<<x.second<<" ";
        if(((x.second)%n) > 0){
            // cout<<-1;
            ok = false;
            break;
        }
    }


    if(ok){
        cout<<"YES\n";
    }else 
        cout<<"NO\n";
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