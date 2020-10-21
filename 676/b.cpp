


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






void solve() {

   int n ;
   cin>>n;
   vvi grid(n,vi(n,5));
   int i , j;char temp;


    fo(i,n)fo(j,n)
    {
        cin>>temp;
        if(temp == '0' or temp == '1')
        (grid[i][j]) = temp-'0';
    }
    // cout<<"\n\n";
    // fo(i,n){fo(j,n)cout<<grid[i][j]<<' ';cout<<'\n';}
    // //now what? start right start down finsih up finsih left
    int sr = grid[0][1]
    ,sd = grid[1][0]
    ,fu = grid[n-2][n-1]
    ,fl = grid[n-1][n-2];

    if(sr == sd and fu == fl){
        //okay 
        if (sr == fu){
            cout<<2<<'\n';
            cout<<"1 2\n2 1\n";
        }else{
            cout<<0<<'\n';
        }
    }else if(sr!=sd and fu !=fl){
        if(sr != fu){
            cout<<2<<'\n';
            cout<<"1 2\n"<<n-1<<' '<<n<<'\n';
        }else if(sr != fl){
            cout<<2<<'\n';
            cout<<"1 2\n"<<n<<' '<<n-1<<'\n';
        }
    }else if(sr==sd and fu !=fl){
        if(fu == sr){
            cout<<"1\n"<<n-1<<' '<<n<<"\n";
        }else if(fl == sr){
            cout<<"1\n"<<n<<' '<<n-1<<"\n";
        }
    }else if(sr!=sd and fu ==fl){
        if(fu == sr){
            cout<<"1\n1 2\n";
        }else {
            cout<<"1\n2 1\n";
        }
    }
    return ;
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