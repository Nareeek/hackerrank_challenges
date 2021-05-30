#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int sum(vector<int>& height){
    int s = 0;
    for(auto x: height){
        s += x;
    }
    return s;
}


int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    vector<int> extra;
    int sum1 = sum(h1);
    int sum2 = sum(h2);
    int sum3 = sum(h3);
    
    if(sum1 == sum2 && sum2 == sum3){
        return sum1;
    }
    
    if(sum1 < sum2){
        extra = h1;    
    }else{
        extra = h2;
    }
    
    if(sum3 < sum(extra)){
        extra = h3;
    }
    
    
    bool eq1 = false, eq2 = false, eq3 = false;
    
    int sum_extra = sum(extra);
    int sum_temp1 = 0, sum_temp2 = 0, sum_temp3 = 0;
    int item1 = 0, item2 = 0, item3 = 0;
        
    while(!extra.empty()){        
        sum_temp1 = sum1; sum_temp2 = sum2; sum_temp3 = sum3;
        item1 = 0; item2 = 0; item3 = 0;
        
        while(sum_temp1 >= sum_extra){
            if(sum_temp1 == sum_extra){
                eq1 = true;
                break;
            }else{
                sum_temp1 -= h1.at(item1);
                item1++;
            }
        }

        while(sum_temp2 >= sum_extra){
            if(sum_temp2 == sum_extra){
                eq2 = true;
                break;
            }else{
                sum_temp2 -= h2.at(item2);
                item2++;
            }
        }
                
        while(sum_temp3 >= sum_extra){
            if(sum_temp3 == sum_extra){
                eq3 = true;
                break;
            }else{
                sum_temp3 -= h3.at(item3);
                item3++;
            }
        }
        
        if(eq1 && eq2){
            if(eq3){
                return sum_extra;
            }
        }
        
        eq1 = false; eq2 = false; eq3 = false;
        
        sum_extra -= extra.front();
        extra.erase(extra.begin());
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

