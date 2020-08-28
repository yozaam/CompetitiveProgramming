

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

typedef int ll;

using namespace std;

int main() {
    // your code goes here
    int tc;
    cin>>tc;
    while(tc--){
        string ans = "DA";

        string s ;

        cin>>s;

        stack<bool> stak;

        ll count  = 0 ;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '0'){
                if(stak.empty() || stak.top() == 0){
                    stak.push(false);
                }
                else if ( stak.top()==1 ){
                    stak.pop();
                    count++; // heree is a blasttt! possible>
                }
            }else if (s[i] == '1'){
                if(stak.empty() || stak.top() == 1){
                    stak.push(1);
                }else if(stak.top() == 0){
                    stak.pop();
                    count++;
                }
            }
        }
        if(count%2==0){
            ans  = "NET";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
