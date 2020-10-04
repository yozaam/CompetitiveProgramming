


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
int  n, m, k ,i,j;
vvi mat,vis;
//=======================

inline bool safe(int x,int y){
    return x<n and y<m and x>=0 and y>=0 and !vis[x][y];
}

vector<unordered_map<int,int> > groups;

void dfs(int x , int y,unordered_map<int,int>&fre ){


    //your neighbours are your row and column palindromes!
    if(!safe(x,y))return;

    cout<<"|"<<x<<','<<y;

    vis[x][y]=1;

    fre[mat[x][y]]++; // in this group! he is counted

    dfs(n-(x+1),y,fre);dfs(x,m-(y+1),fre);//add them to his group!


    // 0 , 0 => 4 - 0 + 1 -> index 5?!
}

ll maker( int don ,const unordered_map<int,int>&fre){
    ll cost = 0;
    cout<<"\tnormalize to "<<don<<' ';
    for(auto&ff:fre){
        ll his = abs(ff.first - don);
        cost += his*ff.second;
    }
    cout<<cost <<" bucks \n";
    return cost;
}

ll normal(unordered_map<int,int>&fre){
    //first... who is the biggest don.
    vi don ;
    cout<<"\nin this group:\n";
    int maxfre=0;
    // for(auto&ff:fre)if(ff.second>maxfre)maxfre=ff.second;
    //     //if two maximum freq.. any difference in answer???
    //     //YES TRY BOTH and give the better answer????????

    // for(auto&ff:fre)if(ff.second==maxfre)don.push_back(ff.first);
    for(auto&ff:fre)don.push_back(ff.first);


    //now make everyone equal to him!!!! he is majority!!!!!
    ll cost = maker(don.back(),fre);
    don.pop_back();
    for(int& x : don){
        cost = min(maker(x,fre),cost);
    }

    cout<<"best "<<cost<<'\n';
    return cost;

}

void solve() {

    cin>>n>>m;
    mat.clear();vis.clear();groups.clear();
    mat.resize(n,vi(m,-1)); vis.resize(n,vi(m,0));


    fo(i,n)fo(j,m)cin>>mat[i][j];


    unordered_map<int,int> fre;


    fo(i,n){fo(j,m){

        //do a dfs!
        if(!vis[i][j]){
            cout<<"grouping ";//<<i<<','<<j;
            fre.clear();
            dfs(i,j,fre);
            cout<<'\n';
            groups.push_back(fre);
        }

    }}

    ll cost = 0 ;


    for(unordered_map<int,int>&f: groups){
        cost += normal(f);
    }


    cout<<cost<<"\n";
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