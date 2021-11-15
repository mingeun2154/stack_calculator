#include <string>
#include <iostream>

using namespace std;

int main(){
  string str = "mingeun9";
  cout<<str[0]<<endl;
  cout<<str[7]<<endl;
  if(isdigit(str[3]))
    cout<<"true"<<endl;
  else  
    cout<<"false"<<endl;
  return 0;
}