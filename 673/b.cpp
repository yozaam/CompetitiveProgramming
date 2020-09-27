


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
int  m, k ;
//=======================

void solve() {

    ll n ,x,y,k,l;
    cin>>n>>k;
    vi v(n);int i=0,j=n-1;
    fo(i,n)cin>>v[i];
    unordered_map<int,vi> idx;

    fo(i,n)idx[v[i]].push_back(i);

    sortall(v);
    //when they have a sum of k (2-sum LC)
    //separate them    

    
i=0;
    vi color(n);

    while(i<j){

        // cout<<v[i] <<"&"<<v[j]<<endl;

        if(v[i]+v[j]==k){
            //separate them please
            color[i]=1;
            color[j]=0;
            i++,j--;
        }
        else if(v[i]+v[j]>k){
            //too big move j
            color[j--]=0;
        }else {
            color[i++]=1;
        }
    }
    x= -1;
    if(i==j)x=i,color[i]=-1;
    fo(i,n)cout<<color[i]<<" ";cout<<"\n";

    int op = 0;

    unordered_map<int,int> frea,freb;
    fo(i,n){
        if(color[i]==0 or color[i]==-1)continue;

        op += frea[k-v[i]];

        frea[v[i]]++;

    }

    fo(i,n){
        if(color[i]==1 or color[i]==-1)continue;

        // cout<<v[i]<<"\t";

        op += freb[k-v[i]];

        freb[v[i]]++;

    }

    if(x>=0)
    // op += min(frea[k-v[x]] , freb[k-v[x]]);
    {
        color[x]=0;
        if(freb[k-v[x]]<frea[k-v[x]]){
            //then put him in b
            color[x]=1;
        }
    }
    // cout<<op<<"\n";

    vi col(n,0);


    fo(i,n){
        if(color[i]){
            //he should be colored ;)
            j=idx[v[i]].back();
            col[j]=1;
            idx[v[i]].pop_back();
        }
    }

    fo(i,n)cout<<col[i]<<" ";cout<<"\n";
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