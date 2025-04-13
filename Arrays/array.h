
#include <vector>
using namespace std;
class Array {
public:
    vector<int> createArray(int n);
    void displayArr(int n,vector<int>arr);
    void copyArr(int last_index,vector<int>&arr_from,vector<int>&arr_to,int start_index);
    void arrSwap(vector<int>&arr,int startindex,int lastindex);
};

