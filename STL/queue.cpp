#include<iostream>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element: " << q.front() << endl; // Access the front element
    cout << "Back element: " << q.back() << endl;   // Access the
    q.pop(); // Remove the front element
    cout << "After pop, front element: " << q.front() << endl; //
    cout << "Queue size: " << q.size() << endl; // Get the size of the queue
    cout << "Is queue empty? " << q.empty() ? "Yes" : "No" << endl; // Check if the queue is empty
    return 0;
}