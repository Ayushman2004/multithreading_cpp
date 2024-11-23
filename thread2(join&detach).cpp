#include <iostream>
#include <thread>
using namespace std;

void run(int count){
    while(count!=0){
        cout<<"running..."<<endl;
        count--;
    }
}

int main(){

    thread t1(run,50);

    // you either use join() or detach() [can't use both or none]
    t1.join(); // double join leads to program termination
    if(t1.joinable()) t1.join(); // thats why we use joinable()

    // t1.detach(); -> detaches your thread from the main thread,
    // which may leads to the program ending before the brached thread
    // double detach also leads to program termination, so joinable is also used there

    return 0;
}