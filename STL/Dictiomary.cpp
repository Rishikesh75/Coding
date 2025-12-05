/*
    ---Dictinoary Methods--
    mp.insert(make_pair(k,v))
    mp.erase(k)
    mp.count(k)
    mp.find(k)
    mp.size()
    mp.empty()
    mp.clear()
    mp.LowerBound()
    mp.upperBound()
*/

#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int>m;
    m.insert(make_pair(1,1));
    cout<<m[1]<<endl;

}