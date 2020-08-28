//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 04/06/20.
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
#include <unordered_set>

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    ll tc;
    cin>>tc;
    while(tc--){
        //for all test cases
        unsigned long long tom;
        cin>>tom;

        unsigned long long temptom = tom;

        unsigned long long jerry = 2;
        //now how many times 2 is in this number min jerry will have to be that
        while(temptom%2==0){
            temptom/=2;
//            cout<<"\t making halves "<<temptom;
            jerry*=2;
        }

//        cout<<" \n odd now at "<<temptom<<" it is odd\n";

        unsigned long long  minjerry = jerry;
//        unordered_set<ll> j;

//        while(jerry < tom){
//            j.insert(jerry);
//            jerry+=minjerry;
//        }
        //or is it diff between minjerry and tom

//        unsigned long long dif = tom - minjerry;

//        ll counter = 0;

        ll division  = tom/jerry;

//        if(tom>minjerry){
//             counter = dif/minjerry  ;
//             if(dif%minjerry!=0)counter++;
//        }
//
//        int ans = counter;


//        cout<<"\ncounter is "<<counter<<" division is "<<division;


        cout<<division<<"\n";


    // end of test case :);
    }
    return 0;
}
