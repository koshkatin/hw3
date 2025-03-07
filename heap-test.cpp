#include "heap.h"
#include <iostream>



using namespace std;

int main()
{
    Heap<int, std::less<int>> h; // m defaults to 2, c to less
    h.push(3);
    h.push(4);
    h.push(5);
    h.push(5);
    h.push(10);
    h.push(3);
    h.push(7);
    h.push(8);
    h.push(2);
    h.push(1);
    h.push(0);
    h.push(99);

    h.print();
    
    cout << "initial size : " << h.size() << endl;
    cout << "Top : " << h.top() << endl;
    h.pop();
    cout << "Top after pop : " << h.top() << endl;
    h.pop();
    cout << "Top after pop2 : " << h.top() << endl;
    h.pop();
    cout << "Top after pop3 : " << h.top() << endl;

    while (!h.empty()) {
        h.pop();
    }

    cout << "size after depletion : " << h.size() << endl; 

    try {
        h.pop();
    } catch (std::underflow_error& e) {
        cout << "Empty pop error : " << e.what() << endl;
    }

    try {
        h.top();
    } catch (std::underflow_error& e) {
        cout << "Emtpty top error ; " << e.what() << endl;
    }


    return 0; 
}