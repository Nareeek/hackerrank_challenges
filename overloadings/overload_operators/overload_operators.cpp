//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex

// overload method -> inside class (declaration must be inside class).
// Complex Complex::operator+(const Complex& second_complex){
//     this->a += second_complex.a;
//     this->b += second_complex.b;
//     return *this;
// }


//overload method -> outside class (no need declaration inside class).
Complex operator+(Complex& c1, const Complex& c2){
    Complex ans;
    ans.a = c1.a + c2.a;
    ans.b = c1.b + c2.b;
    return ans;
}


// Not a friend function (there are no private members).
std::ostream& operator<<(std::ostream& os, const Complex& cls) {
    os << cls.a << "+i" << cls.b;
    return os;
}



int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

