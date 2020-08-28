#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>



using namespace std;

vector<long> posToScore;






bool cmpSignTime( vector<long> a , vector <long> b   ){
    return a[2] > b[2];
}

bool cmpScoresLibBooks( long &a , long &b   ){
    return posToScore[a] < posToScore[b];
}



int main() {

    std::ios_base::sync_with_stdio(false); //for fast cin cout


    long score = 0;
    vector<long> currScore;
    vector<long> signedLibraries;






    long long B, L, D;

    cin >> B >> L >> D;

    posToScore.resize(B);

    vector<vector<long > > libBooks(L);  /// this one stores library index to set of his book ids

    vector<long> scanned(L,0);

    vector< vector<long> > scannedBk;

    scannedBk.resize(L);

    long temp;


    vector<vector<long> > libData(L, vector<long>(3, 0));

    //0 - no of books 1 - days 2 - rate 3 - stores lib id

    long b, d, r;


    for (long i = 0; i < B; i++) {
        cin >> temp;

//        books.insert(temp);
        posToScore[i] = (long)temp;
    }


    for (long i = 0; i < L; i++) {


        cin >> b >> d >> r;

//        cout << "bdr" << b << d << r << endl;

        libData[i][0] = b;
        libData[i][1] = d;
        libData[i][2] = r;
        libData[i][3] =  i;


        for (long j = 0; j < b; j++) {
            cin >> temp;

            libBooks[i].push_back((long)temp);

//            cout<<temp;
        }

        sort(libBooks[i].begin() , libBooks[i].end() , cmpScoresLibBooks);

    }


//    for()




    sort(libData.begin(), libData.end(), cmpSignTime);


    for (long i = 0; i < L; i++) {
//        cout << "signup order"<<libData[i][1];
    }

    long signing = 0;

//    vector<long> scanned(L);

    set<long> visited;


    for (auto i : libBooks[1]) {
//        cout << "\n sorted ? " << i;
    }


    for (long i = 0; i < D; i++) {

        if(signing < L -1 ){
            signing++;
        }

        libData[signing][1]--;
//        long ass = libData[signing][1];
//        cout<<"ddddddd"<<ass;




        for(long xx: signedLibraries){



            long rate = libData[xx][2];
            long libId = libData[xx][3];



            while (rate) {
                //                cout<<"here?";
                long currBook = libBooks[libId].back();


                //                auto a=visited.find(3);
                //                string jj = typeof(a);
                //                cout<<jj;

                if(visited.find(currBook) == visited.end()) {

                    visited.insert(currBook);

//                    cout<<"not in vis "<<currBook<<endl;

                    libBooks[libId].pop_back();

                    rate--;
                    score += (long)posToScore[currBook];
//                    cout<<libId<<"lll\n";
                    scanned[libId]++;

                    scannedBk[libId].push_back(currBook);

                }else{
                    libBooks[libId].pop_back();

                }

            }


            if (libData[signing][1] == 0) {
                signedLibraries.push_back(signing);

            }

        }



    }


//    cout<<"score is ? "<<score;


cout<<signing+1<<endl;


    for(int i = 0 ; i <= signing ; i++){
        long hisId = libData[i][3];

        if(scanned[hisId] == 0 ){
            continue;
        }
        cout<<hisId<<" "<<scanned[hisId]<<endl;

        for(long xxxxx : scannedBk[hisId]){
            cout<<xxxxx<<" ";
        }
        if(i<signing)
        cout<<endl;

    }

    return 0;
}