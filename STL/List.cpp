#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> ls;
    ls.push_back(3);
    ls.push_front(4);
    ls.pop_back();
    ls.pop_front();
    return(0);
}