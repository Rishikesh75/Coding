#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx;
class Counter
{
public:
    static int val;
    static void incrementCounter()
    {
        int localValue = 0;
        for(int i=0;i<10000;i++)
        {
            localValue = localValue + 1;
        }
            lock_guard<mutex> lock(mtx);
            val = val + localValue;
        
    }
};
int Counter::val = 0;
int main()
{
    

    thread t1(Counter::incrementCounter);
 
    
    thread t2(Counter::incrementCounter);
    t2.join();
    t1.join();
    cout<<Counter::val<<endl;
    return 0;
}