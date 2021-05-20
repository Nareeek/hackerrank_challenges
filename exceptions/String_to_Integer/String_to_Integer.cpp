#include <bits/stdc++.h>

using namespace std;

void getline(istream& is, string& S){
    is >> S;
    long int number = stoi(S);
    cout << number;
}

int main()
{   
    try{
        string S;
        getline(cin, S);   
    }
    catch(const exception& s){
        cout << "Bad String" << "\n";
    }
    return 0;
}
