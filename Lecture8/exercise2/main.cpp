#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void func(){
    for(int i=0;i<10;i++){
        std::cout<<"Hello world "<<i<<"\n";
        std::this_thread::sleep_for(1ms);
    }
}

int main()
{
    std::thread t1(func);
    //std::this_thread::sleep_for(1s);
    std::thread t2(func);
    t1.join();
    t2.join();
    return 0;
}
