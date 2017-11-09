#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void myFunc() {
    std::cout << "Hello from another thread!" << std::endl;
    for (int i=1;i<6;i++){
        std::cout << "Thread entering sleeping mode for i=" << i << std::endl;
        std::this_thread::sleep_for(1s);
        std::cout << "Thread just woke up for i=" << i << std::endl;
    }
}

int main()
{
    std::thread t1(myFunc);
    std::cout << "Hello from main!"<<std::endl;
    std::this_thread::sleep_for(2s);
    std::cout<<"Main waited for 2 seconds" << std::endl;

    //t1.join();    The program terminates with an error if we do not
    //              include this line. Explain why!
    return 0;
}
