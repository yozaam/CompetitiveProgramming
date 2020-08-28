//
// Created by Yohaan Vakil on 19/04/20.
//

#include <iostream>
#include <vector>


using namespace std;


double numberOfPaths(int m, int n)
{
    //!
    int path = 1;
    for (int i = n; i < (m + n - 1); i++) {
        path *= i;
        path /= (i - n + 1);
    }
    return (double)path;
}


int main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;

    cin>>T;



    int N;

    vector<double> h;

    double ans;

    for( int i = 1 ; i <= T ; i++){

//        cout<<"\ni is"<<i;
        cin>>N;

//        cout<<"\n N is "<<N;

        h.resize(0);

        while(N>0){
//            cout<<"y";

            double temp;
            cin>>temp;
//            cout<<"ok ok ";
            h.push_back(temp);

            N--;
        }

        //now3
        // in h

        //when it goes down
        //if it goes up next it is a peak
        ans =0;

//        cout<<"h.size()-1"<<h.size()-1;
//        ans = h[4]-h[2]*h[5]-h[3]/h[0]*h[1];

        vector<vector<long long> > paths(h[0],vector<long long>(h[1],0));

        vector<vector<long long> > a = paths;
        a[0][0] = 1;
        for(int i = 1 ; i< h[1] ; i++){
            if(a[i][0]==0)
            a[i][0] = a[i-1][0];
        }

        for(int i = 1 ; i< h[0] ; i++){
            if(a[0][i]==0)
                a[0][i] = a[0][i-1];
        }


        for(int i = h[3] ; i<h[5] ;i++){
            for(int j = h[2] ; j<h[5] ;j++){
                paths[i][j] = 1;
            }
        }

        for(int i = 1 ; i< h[1] ; i++){
            for(int j = 1 ; j<h[0]; j++){
                if(paths[i][j] == 0){
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }

        cout<<"Case #"<<i<<": "<< a[a.size()-1][a[0].size()-1] <<"\n";



    }
    return 0;
}