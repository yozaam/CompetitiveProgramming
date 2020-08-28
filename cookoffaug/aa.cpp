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
typedef pair<ll, ll>  pii;
typedef vector<ll>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
//=======================

ll n, m, j , i ;
//=======================

vector<vector<char> > a;


vector< vector<ll> > memo;


struct poll{
    ll x, y , cost;

    poll(ll a, ll b, ll c){
        x = a, y = b , cost = c;
    }
};



bool safe(ll x, ll y , ll cost){
    if (x>=0 && x<n 
        && y>=0 && y<m
        && a[x][y] == '.' ){

        // if(x==1 && y == 4){
        //     cout<<"\n\t  cost"<<cost<<"\n";
        // }

        if(cost<memo[x][y]){
            return true;
        }else if(memo[x][y] == -1){
            return true;
        }
    }
    return false;
}

void solve() {
    
    cin>>n>>m;
    ll sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;

    //now can i reach d from s
    //i am using BFS
    //okay..
    //okay..

    a.resize(n,vector<char>(m));
    memo.resize(n,vector<ll>(m,-1));

    fo(i,n)
        fo(j,m)
            cin>>a[i][j];

    //initial at i,j

    queue< poll> q;

    q.push(poll(sx-1,sy-1,0));

    memo[sx][sy] = 0;

    //store the cost as well!
    ll ans = -1;

    while(!q.empty()){
        //try all combos!
        auto from = q.front();
        q.pop();

        //am i destination?


        //now am i a dot!?

        //check my 4 neighbours?

        //then my 8 neighbours?//outer ring?

        ll x = from.x, y = from.y, cost = from.cost;

        // if(x == dx-1 && y ==dy-1)cout<<'f';
        
        cout<<"\nat"<<x<<" "<<y<<" \n";
        memo[x][y] = cost;

        for( i = -1 ; i< 2; i+=2){
            if(safe(x+i,y,cost)){
                q.push(poll(x+i,y,cost));
            }
            if(safe(x,y+i,cost)){
                q.push(poll(x,y+i,cost));
            }
        }

        vector<ll> range = {-2,0,1,-1,2};

        for(ll f: range){
            for(ll k:range){
                if(f!=0 || k!=0){
                    //this is outer ring!
                    if(safe(x+f,y+k,cost+1)){
                        //great now check him out!
                        q.push(poll(x+f,y+k,cost+1));
                    }else{
                        cout<<"    didnt try "<<x+f<<" "<<y+k<<"\n";
                    }
                }
            }
        }

    }



    cout<<memo[dx-1][dy-1];

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}