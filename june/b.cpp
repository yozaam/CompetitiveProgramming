//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

//
// Created by yozaam on 05/06/20.
//

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

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    int tc,ans;
    cin>>tc;

    while(tc--){

        ans = 0;



        //bool prev = false;
        //stores whether previous was used in a pair( no need just skip over next element i++?

        string s;
        cin>>s;

        for(int i = 1 ; i< s.length() ; i++){
            if(s[i]!=s[i-1])//x != y
                ans++,i++;//and skip checking next guy cause invalid :)
        }


        cout<<ans<<"\n";

    }
    return 0;
}
