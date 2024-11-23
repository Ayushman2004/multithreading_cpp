#include <iostream>
#include <thread>
using namespace std;

unsigned long long OddSum =0;
unsigned long long EvenSum =0;

void even(unsigned long long start, unsigned long long end){
    for(unsigned long long i=start; i<=end;i++){
        if(i%2==0) EvenSum+=i;
    }
}

void odd(unsigned long long start, unsigned long long end){
    for(unsigned long long i=start; i<=end;i++){
        if(i%2==1) OddSum+=i;
    }
}

//function pointers
int main(){

    unsigned long long start = 0;
    unsigned long long end = 1900000000;

    thread t1(odd,start,end);
    thread t2(even,start,end);

    t1.join();
    t2.join();

    cout<<"OddSum = "<<OddSum<<endl;
    cout<<"EvenSum = "<<EvenSum<<endl;

    return 0;
}