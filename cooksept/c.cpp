
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
size_t   k , i , j  ,t , n;
//=======================
vi a , l;
int bestk;

vi b;

struct cnsc{
    int fre ;
    bool one;
    bool edge;
    cnsc(int f , bool c){
        fre = f,one=c,edge=0;
    }
    // bool operator<(cnsc& that) const{
    //     float a = fre ;
    //     float b = that.fre;
    //     if(!edge)a/=2;
    //     if(!that.edge)b/=2;
    //     return a<b;
    // }
};

 struct compare  
 {  
   bool operator()(const cnsc& dis, const cnsc& that)  
   {  
    float a = dis.fre ;
        // float b = that.fre;
        // if(!dis.edge)a/=2;
        // if(!that.edge)b/=2;
        return dis.fre<that.fre;
       
   }  
 }; 


 ll greed(priority_queue<cnsc , vector<cnsc>,compare> big , int k, ll leftover= 0){
    
// cout<<"\ninside greedy (k="<<k<<" left"<<leftover<<"\n"; 
    // ll leftover= 0;

    // while(k>1 and !big.empty()){

    //     //remove the biggest group of 0's
    //     auto top = big.top();big.pop();

    //     // cout<<top.fre<<" deleted \n";

    //     // if(top.edge)k--;
    //     k-=2;
    // }

   

    while(!big.empty() or k>0){
        auto top = big.top();big.pop();
        // cout<<top.fre<<" added \n";

        leftover+=top.fre;
        k--;
    }

    return leftover;
 } 

void solve() {

    //backtrack?
    int n , k ; vector<ll> s;

    cin>>n;

    fo(i,n)cin>>s[i];
    
    // cout<<" got "<<n<<k<<s<<endl;
    //find longest group of zeros and cut!
    vector<cnsc> v;
    bool noOne = 1;

    fo(i,n){

        if(s[i]>0)noOne = false;

        if(v.empty()){
          if(s[i]>0)
            v.push_back(cnsc(s[i],1));
          else 
            v.push_back(cnsc(1,1));

            v[0].edge = 1;
        }else {
            auto b = v.back();
            if(s[i] >0){
                if(b.one){
                    v.back().fre+=s[i];
                }else {
                    v.push_back(cnsc(s[i],1));
                }
            }else {
                if(!b.one){
                    v.back().fre++;
                }else {
                    v.push_back(cnsc(1,0));
                }
            }
        }
    }

    v.back().edge = 1;
    //now , who is the biggest group of zeroes!

    if(noOne){cout<<"0\n";return ;}

    priority_queue<cnsc , vector<cnsc>,compare> big;

    // []
    // (const cnsc& aa, const cnsc&that){


    //         float a = aa.fre ;
    //     float b = that.fre;
    //     if(!aa.edge)a/=2;
    //     if(!that.edge)b/=2;
    //     return a<b;

    // } > big; 


    for(cnsc cc:v){
        if(cc.one)big.push(cc);
    }

    //any time you have a choice of removal, 


    //calculate 3 answers ...

     
    ll leftover = greed(big,2);//can take only 2;)


    // cout<<"ok? \n";

   

 

    cout<<leftover<<"\n";

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