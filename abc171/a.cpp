

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

typedef  long long ll;

typedef unsigned int ui;

using namespace std;

vector<ui> memo(vector::max_size());

int countDivisors(int n)
{
    if(memo[n]){
        return memo[n];
    }

    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                return countDivisors(i) + 1;

            else // Otherwise count both
                return countDivisors(i) + countDivisors(n/i);
        }
    }
    return cnt;
}



int main() {
    memo[0]=  0;memo[1] = 1; memo[2] = 2; memo[3] = 2;

    //letsgo
    ui n;
    cin>>n;

    ll ans;

    while(n--)
     ans += n* countDivisors(n);


    cout<<ans;

    return 0;
}
