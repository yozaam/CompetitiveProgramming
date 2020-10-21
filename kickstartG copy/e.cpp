


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
#include <climits>
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
int  m, k ,n, i;
//=======================
struct node{
    ll endhere, best, val;
vector<ll> kids;
    node(ll v , ll e=0 , ll b =0 ){
        endhere = e, best = b , val = v;
        
    }
};
vector<node*> tree;

ll bestie = 0;

void dfs(ll rooti,node*prev){// ll best = 0 , ll prev = INT_MAX , ll endhere = 0){
    node* root = tree[rooti];

    if(root->val >= prev->val ){
        root->endhere = prev->endhere+1;
        
    }else {
        root->endhere = 1;
    }

            bestie = max(bestie, root->best+root->endhere);
    

    if(root->best <= root->endhere){
           
            bestie = max(bestie, root->best+root->endhere);
        
            root->best = root->endhere;
    }


    for(auto v:root->kids){
        dfs(v, root);
    }
}

void solve() {
    
    cin>>n;
    tree.resize(n+1);

    fo(i,n){
        cin>>m;
        tree[i] = new node(m);
    }

    fo(i,n-1){
        ll u , v;
        cin>>u>>v;

        tree[u]->kids.push_back(v);
    }

    // auto root = tree[1];

    //now find the longest increasing sequence at each point!
    dfs(0,new node(INT_MIN,0,0));

    


    cout<<bestie<<"\n";
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