#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int val =0;
std::mutex m;

void incr(string t){
    cout<<"locked by "<<t<<endl;
    m.lock();
    ++val; //critical section
    cout<<t<<" changed val to "<<val<<endl;
    m.unlock();
    cout<<"unlocked by "<<t<<endl;
}

int main(){

    thread t1(incr,"t1");
    thread t2(incr,"t2");

    t1.join();
    t2.join();
    
    return 0;
}