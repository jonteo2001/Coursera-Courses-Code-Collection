#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//GUIDED !!
/*In the stringstream class,
Operator >> Extracts data from stream
Operator << Insertts data into the stream
 So stream1 <<100; inserts the 100 into the stream
 and
 stream1 >> i extracts data out of the stream and stores in the variable i.
 */
bool comp(string a,string b){return  (a + b) > (b + a);};
string largest_number(vector<string> a) {
  //write your code here
    //Concatenate the vector of elements by via conactenation - if ab > ba.
     sort(a.begin(),a.end(),comp);
     string largest_num="";
    for(vector<string>::iterator i = a.begin(); i !=a.end(); i++) {largest_num+=*i;}//Concatenation
    return largest_num;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
    std::cout << largest_number(a) <<endl;
}
