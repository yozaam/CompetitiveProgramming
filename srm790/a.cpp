


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
const vector<ll>    fib{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155};
const vector<ll> prefib{0, 1, 2, 4, 7, 12, 20, 33, 54, 88, 143, 232, 376, 609, 986, 1596, 2583, 4180, 6764, 10945, 17710, 28656, 46367, 75024, 121392, 196417, 317810, 514228, 832039, 1346268, 2178308, 3524577, 5702886, 9227464, 14930351, 24157816, 39088168, 63245985, 102334154, 165580140, 267914295, 433494436};

class  AlicesBirthday{
public:

    int N;
    vector<long long> ans;
    void subset(int sum , int i, vector<int> sub){
        if(sum == 0)ans= sub;

        if(sum - fib[i]  >= 0){
            sub.emplace_back(fib[i]);
            subset(sum-fib[i] , i+1 , sub);
            sub.pop_back();
        }
        subset(sum, i+1, sub);
    }

    
    vector<ll> partition(int n){
        //now ? let me try and make a subset sum ? 
        //wait wait, i need the sum of first n fibonacci nos.
        ll sum = prefib[n];
        N = n;
        //find a subset with given sum now, thats it? 
        //if it is even true? else false?
        //i need to return vector of the elements that add up to it as well
        if(sum%2)return {-1};

        //now the DP table of values ?
        //find subset sum = sum/2
        subset(sum/2,1,{});

        if(ans.size())return ans;
        else return {-1};
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    

    return 0;
}