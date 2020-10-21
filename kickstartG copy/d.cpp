


/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
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

 long double gsum = 0,ways=0;

long double go(list<int> l,long double pre = 0){

    
    // cout<<'\n';

    //merge any two in this !
    if(l.size() == 2){
        gsum += pre + (*l.begin()) + (*(next(l.begin(),1)));
        ways+=1;
        return pre + (*l.begin()) + (*(next(l.begin(),1)));
        //probabililty of sure for this value!
    }
    long double res = 0;

    //now the real stuff
    // fo(i,l.size()){
        list<int> nex;

        for(auto it = l.begin();it!=prev(l.end(),1) ; it = next(it,1)){
            //now do this as a merged part of next!
            nex.clear();

           nex.insert(nex.end(),l.begin(),it);

            nex.push_back(*it + *(next(it,1)));
            nex.insert(nex.end(),next(it,2),l.end());
            res += (go(nex,*it + *(next(it,1)) + pre ))
                ;//add to probability
        }
    // }
    // cout<<"go(";
    // for (int v:l)std::cout << v << ",";
    // cout<<") = "<<res<<'\n';
    return res/(long double)(l.size()-1);
}

void solve(int tc) {
    int n ;cin>>n;
    gsum = 0,ways=0;
    list<int> nums;
    nums.clear();
    ll x;
    fo(i,n){cin>>x;nums.push_back(x);}

    //go forward and try to merge when this is the array !
    long double res = go(nums);
    // res = gsum / ways;
    // while()
      std::cout << std::fixed;
    std::cout << std::setprecision(8);
    cout<<"Case #"<<tc<<": "<<res<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    int tc = 1;
    cin >> t;
    while(t--) {
      solve(tc++);
    }

    return 0;
}