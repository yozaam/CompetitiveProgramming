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
int n, m, k, x, y;
//=======================
vvi dirs={
    {0,0,0},
    {1,1,0},
    {0,1,0},

    {-1,0,0},
    {-1,-1,0},
    
    {0,-1,0},
    {1,0,0}

};

unordered_map<ll , unordered_map<ll, ll > > dist;

unordered_map<ll , unordered_map<ll, bool > > vis;


struct node{
    ll x , y ,c;

    node(ll xx, ll yy, ll cc){
        x =xx,y=yy,c=cc;
    }
};

ll go(ll x, ll y, unsigned ll d){

    cout<<"at "<<x<<' '<<y<<' '<<d<<'\n';

    if(x == 0 and y ==0)return d;

    if(x==0){
        if(y>0){
            d += dirs[5][2] * y;
        }else{
            d+= dirs[2][2] * abs(y);
        }
        return d;
    }else if(y==0){
        if(x>0){
            d += dirs[3][2] * x;
        }else{
            d+= dirs[6][2] * abs(x);
        }
        return d;
    }else if(y > 0 and x > 0){  
        //neither is zero!
        d+= min(x,y) * dirs[4][2];
        return go(x-min(x,y),y-min(x,y),d);
    }else if(y < 0 and x < 0){
        ll nnn = min(abs(x),abs(y));
        d+= nnn * dirs[1][2];
        return go(x+nnn,y+nnn,d);
    }else if(y<0 and x>0){
        d+= dirs[2][2] * abs(y) + dirs[3][2] * x;
        return d;        
    }else if(y>0 and x < 0){
        d+= dirs[5][2] * y + dirs[6][2] * abs(x);
        return d;
    } 
    return d;
}

void solve() {
    cin>>x>>y;
    vis.clear();
    int i ;
    fo(i,6)
        cin>>dirs[i+1][2];

    //now a BFS ( each edge has different wieght! 
    // djikstras? )?

    // dist[0][0] = 0;//source node dijkstras
    
    // find the true cost of going to each direction.. 
    // you can go to right side by going up and down?
    dirs[1][2] = min(dirs[1][2] , dirs[2][2]+dirs[6][2]);

    dirs[2][2] = min(dirs[2][2] , dirs[1][2]+dirs[3][2]);

    dirs[3][2] = min(dirs[3][2] , dirs[2][2]+dirs[4][2]);


    dirs[4][2] = min(dirs[4][2] , dirs[3][2]+dirs[5][2]);

    dirs[5][2] = min(dirs[5][2] , dirs[6][2]+dirs[4][2]);

    dirs[6][2] = min(dirs[6][2] , dirs[1][2]+dirs[5][2]);


    swap(dirs[1],dirs[4]);swap(dirs[2],dirs[5]);swap(dirs[3],dirs[6]);

    //now this is true cost..
    //just do BFS!? // or DP ?! // OR MATH!!!!
    //bfs like a flower.
    
    unsigned ll diste = go(x,y,0);
    cout<<'\n';
    cout<<diste<<'\n';
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