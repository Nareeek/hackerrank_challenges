#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <string>
#include <stack>

using namespace std;


int main() {
    string S;
    stack<string, vector<string>> undo_list;
    
    string count;
    cin >> count;

    int Q = stoi(count);
    for(int i = 0; i < Q; ++i){
        string operation;
        getline(cin >> ws, operation);
        
        switch(operation[0]){
            case '1':{
              undo_list.push(S);
              S += operation.substr(2);
              break;
            }

            case '2':{
              undo_list.push(S);
              int k = stoi(operation.substr(2));
              S.erase(S.size() - k, k);
              break;
            }

            case '3':{
              int k = stoi(operation.substr(2));
              cout << S[k - 1] << '\n';
              break;
            }

            case '4':{
              S = undo_list.top();
              undo_list.pop();
              break;
            }
        }
    }
    return 0;
}

