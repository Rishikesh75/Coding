#include<iostream>
using namespace std;
int main()
{
    map<string,int>studetScore;
    studentScores.insert(make_pair("John", 85));
    studentScores.insert(make_pair("Alice", 90));   
    for(auto it = studentScores.begin(); it != studentScores.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}