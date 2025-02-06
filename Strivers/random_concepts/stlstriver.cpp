#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5,6};
    vector<int>::iterator it = v.begin();
    cout << *(it) << " " << endl ;
    it++;
    cout << *(it) << " " << endl ;
    it = it + 2;
    cout << *(it) << " " << endl ;
   // cout << v.begin() << " ";

    vector<int>::iterator it2 = v.end();
    cout << *(it2) << " v.end() " ;
   //  cout << v.end() << " ";
   // vector<int>::iterator it3 = v.rend();
    // vector<int>::iterator it31 = v.rbegin();
    cout << v[0] << "v[0] " << v.at(0) <<"v.at[0] \n " ;
    cout << v.back() << " at end \n";
    for (vector<int> :: iterator it4 = v.begin(); it4 != v.end(); it4++)
    {
        cout << *(it4) << " ";
    }
    cout << " \n "; 
    for(auto it5 = v.begin(); it5 != v.end(); it5++)
    {
        cout << *(it5) << " : ";
    }

    return 0;
}
