#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// to speed up work in tests.
//  Not my idea, I found this on the web.
int start_up() {
    ios_base::sync_with_stdio(false); // decouple C and C++ streams
    cin.tie(NULL); // doesn't flushing the cout before cin
    return 0;
}

int static r = start_up(); // for a one-time call.

#define endl '\n'; // stop unnecessary flushing of stdout



// int and float:
template <typename T>
class AddElements {
  public:
    AddElements(T arg): element(arg){};

    T add(const T& second) {
      return element + second;
    }
  private:
    T element;
};


// string:
template <>
class AddElements <string> {
  public:
    AddElements(string arg): element(arg){};

    string concatenate(const string& second) {
      return element + second;
  }
  private:
    string element;
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}

