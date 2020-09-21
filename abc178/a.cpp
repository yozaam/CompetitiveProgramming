


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

    // vector<int> fre(101,0);

    // fo(i,n){
    //     cin>>m;
    //     fre[m]++;
    // }

    // int a = -1 , b = -1;
    // int c = 0;
    // for(i = 0 ; (i<101) && (c<2);i++){

    //     cout<<fre[i]<<" at "<<i<<endl;

    //     if(fre[i]>=2)continue;

    //     else if(fre[i] == 1 && a<0)a = i,c++;
    //     else if ( fre[i] ==1)b  =i , c++;
    //     else {
    //         if(a<0)a = i;
    //         if(b<0)b = i;
    //         c+=2;
    //     }
    // }

    unordered_set<int> a,b;

    fo(i,n){
        cin>>m;

        if(a.count(m)){
            b.insert(m);
        }else {
            a.insert(m);
        }
    }

    fo(i, 101)if(!a.count(i))break;

    int ans = i;

    fo(i,101)if(!b.count(i))break;

    ans +=i;

    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // ll a ,b ,c , d;
    // cin >> a>>b>>c>>d;

    // vector<long long> v{a*c,a*d,b*c,b*d,b*c};

    // cout<<*max_element(v.begin(),v.end());

    ll f ;

    cin>>f;

    if(f<2)cout<<0;
    else{

        ll c = 1e9 + 7;
        //i need 10^n - 8^n :)
        // A^B mod C = ( (A mod C)^B ) mod C
        ll ten = 1 , eight = 1 , nine = 1;

        for(int i = 0 ; i< f ; i++){
            ten = ((ten%c) * (10)) % c;
            //rasied to ?
            eight = ((eight%c) * (8)) % c;

            nine = ((nine%c) * (9)) % c;
        }

        cout<<( (ten + eight - nine -nine + c + c)%c);


    }

    // ll base = 0 , ans = 0;
    // ll mul  = 1;
    // while(mul<f){
    //     ans += f - mul + 1;
    //     mul *=3;
    // }

    return 0;
}