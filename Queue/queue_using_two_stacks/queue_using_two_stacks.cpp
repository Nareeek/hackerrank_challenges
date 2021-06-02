#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <stack>
#include <string>

using namespace std;


int main() {
    stack<int> stack_input;
    stack<int> stack_output;
    
    string operation_count;
    cin >> operation_count;
    int q = stoi(operation_count);
    
    for(int i = 0; i < q; ++i){
        string operation;
        getline(cin >> ws, operation);
        
        switch(operation[0]){
            
            case '1':{
                int element = stoi(operation.substr(2));
                stack_input.push(element);
                break;
            }
            
            case '2':{
                if(stack_output.empty()){
                    while(!stack_input.empty()){
                        stack_output.push(stack_input.top());
                        stack_input.pop();
                    }                    
                }
                stack_output.pop();
                break;
            }
            
            case '3':{
                if(stack_output.empty()){
                    while(!stack_input.empty()){
                        stack_output.push(stack_input.top());
                        stack_input.pop();
                    }
                }
                cout << stack_output.top() << '\n';
                break;
            }
        }
    }
      
    return 0;
}

