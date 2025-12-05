/*
-----STL Meathods-----
l.push_back(val)
l.pop_back()
l.push_front(val)
l.pop_front()
l.empty()
l.begin()
l.end()
l.remove(val)
l.erase(pos)
l.insert(pos,value)
l.size()
l.clear()
*/

#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.pop_front();
    l.pop_back();
    for(auto it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<"\t";
    }
    cout<<"\n";
    return 0;
}