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
#include <unordered_map>

typedef long long ll;

using namespace std;

int main() {
    // your code goes here
    ll tc,ans;
    cin>>tc;
    while(tc--){

        //for all test cases


        ll m,n; char temp;

        cin>>n>>m;


        vector< vector<char> > matrix(n,vector<int>(m,'e'));


        unordered_set< pair<int,int> > bads;



        unordered_map<int,unordered_set<int> > wallsrow;


        unordered_map<int,unordered_set<int> > wallscol;

        for(int i = 0 ; i< n ; i++){

            for(int j = 0 ; j< m ; j++){

                cin>>temp;

                switch (temp){
                    case '.':
                        break;
                    case 'B':
                        bads.insert(make_pair(i,j));
                        matrix[i][j] = 'B';
                        break;
                    default:
                        matrix[i][j] = temp;
                }
            }
        }

        matrix[n-1][m-1] = 'D';

        vector<int> ne{-1,0,1};


        for(auto bad : bads){
            for(int x : ne){
                for(int y : ne)
                {
                    if(bad.first+x>=n || bad.first+x<0 ||bad.second+y>=m || bad.second+y<0 )
                        continue;
                    else if(matrix[bad.first+x][bad.second+y] == 'e'||matrix[bad.first+x][bad.second+y] == 'B')
                    {
                        matrix[bad.first+x][bad.second+y]='#';
                        wallscol[bad.second+y].insert(bad.first+x);
                        wallsrow[bad.first+x].insert(bad.second+y);
                    }
                    else
                        goto No;

                }
            }
        }




        Yes:
            cout<<"Ashish\n";
        No:
            cout<<"No\n";



    }
    return 0;
}
//
// Created by yozaam on 07/06/20.
//

