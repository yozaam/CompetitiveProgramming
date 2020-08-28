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
#include <unordered_set>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    ll tc,ans;
    cin>>tc;
    while(tc--){

        //for all test cases


        ll m,n,temp;

        cin>>n>>m;

        unordered_set<int> rows,cols;

        vector< vector<int> > mat(n,vector<int>(m,0));

        for(int i = 0 ; i< n ; i++)
            rows.insert(i);

        for(int j = 0 ; j< m ; j++)
            cols.insert(j);



        for(int i = 0 ; i< n ; i++){

            for(int j = 0 ; j< m ; j++){

                cin>>temp;

                if(temp == 1){
                    mat[i][j]  = 1;
                    rows.erase(i);
                    cols.erase(j);
// those are unsafe now.
                }
            }
        }

        int moves = min(rows.size(),cols.size());

        if(moves%2)
            cout<<"Ashish\n";
        else
            cout<<"Vivek\n";



    }
    return 0;
}
//
// Created by yozaam on 07/06/20.
//

