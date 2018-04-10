#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{
    stack<int> nr1,nr2;
    string nr1s ,nr2s,nrfinals;

    cout<<"Enter first number: ";
    cin>>nr1s;
    cout<<"Enter second number: ";
    cin>>nr2s;

    for ( string::iterator it=nr1s.begin(); it!=nr1s.end(); ++it)
        nr1.push(*it - '0');
    for ( string::iterator it=nr2s.begin(); it!=nr2s.end(); ++it)
        nr2.push(*it - '0');

    int carry = 0;
    int s;
    while(!nr1.empty() || !nr2.empty()){

        s = (!nr1.empty() ? nr1.top() : 0) +
            (!nr2.empty() ? nr2.top() : 0 )+
            carry ;

        if( s >= 10){
            nrfinals.push_back( (s % 10) +'0' );
            carry = 1;
        }else{
            nrfinals.push_back( s + '0' );
        }
        if(!nr1.empty())
        nr1.pop();
        if(!nr2.empty())
        nr2.pop();

    }
    if(carry > 0)
        nrfinals.push_back(1+'0');
    reverse(nrfinals.begin(),nrfinals.end());
    cout<<nrfinals<<endl;

  return 0;
}
