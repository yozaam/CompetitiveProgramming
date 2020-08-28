//
// Created by yozaam on 31/05/20.
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


using namespace std;

int main() {
    // your code goes here
    long long tc,n,x; string ans;
    cin>>tc;
    while(tc--){

        vector<int>a;

        cin>>n>>x;

        long long oddcount = 0;
        long long evencount = 0;

        long long temp;
        while(n--){
            cin>>temp;
            if(temp%2==0)evencount++;
            else oddcount++;
        }



        ans = "No";

        //i need one odd no at least so that gives me odd
        if(oddcount){
            x-=evencount; // select all even numbers

            if(x<2)//one odd no will fill it up
                ans = "Yes";
            else{
                if (x%2 && oddcount>=x)// if x is odd i have an odd no of spaces empty i need to put odd numbers no problem
                    ans = "Yes";
                else if ( x%2 ==  0 && oddcount>x)// i can replace one of the even numbers (thus >x)
                    ans = "Yes";
            }

        }

        cout<<ans<<"\n";

    }
    return 0;
}
