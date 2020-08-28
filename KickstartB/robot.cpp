//
// Created by Yohaan Vakil on 19/04/20.
//

#include <iostream>
#include <vector>

#include <stdlib.h>     /* atoi */

using namespace std;
int main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;

    cin>>T;



    int N;

    vector<int> h;

    int ans;

    string comm,rx,raw;

    for( int i = 1 ; i <= T ; i++){


//        cout<<"case1"<<i;
//         comm = "";

         rx="23456789";
         raw = "";

        cin>>comm;
//        getline(cin,comm);

        bool found =true;

        while(found){

            found=false;
             raw = "";

//            cout<<"ghgh";
            for(int j = 0 ; j<comm.size() ; j++){
//            cout<<comm[j];

                if(rx.find(comm[j]) != std::string::npos){
                    int times = atoi(&comm[j]);
                    j++;//bracket
                    j++;//string tem

                    string tem="";
                    int extras = 1; //extra brakcets of inner stuff
                    while(extras !=0){
//                        cout<<"\t while "<<comm[j]<<"ex "<<extras;
                        if(comm[j] == '('){
                            extras++;
                        }if(comm[j]==')'){
                            extras--;

                        }
                        tem+=comm[j++];
                    }
                    tem.pop_back();
                    j--;



//                    cout<<"\n"<<times<<"times"<<"\n tem is "<<tem<<"\n";

                    for(int k=0; k<times ; k++){

                        raw+=tem;
                    }
                    found =true;
                }else{
                    raw+=comm[j];

                }


            }

            comm = raw;
        }


//        cout<<"\n raw is "<<raw;


        long long w=1,h=1,max=1000000000;

        int e = 0,s = 0;



        for(char c: raw){
            if(c=='N'){
                s--;
            }else if(c=='S')s++;else if(c=='E')e++;else if(c=='W'){e--;}
        }

        if(e<0){
            w = max+e+1;

        }else{
            w = e+1;
        }

        if(s<0){
            h = max+s+1;
        }else{
            h = s+1;
        }

        cout<<"Case #"<<i<<": "<<w<<" "<<h<<"\n";



    }
    return 0;
}