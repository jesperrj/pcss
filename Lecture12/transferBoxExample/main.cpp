#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

struct Box{
    explicit Box(int num):
        num_things{num} {}
    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num){
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

    std::lock(lock1, lock2);

    from.num_things -= num;
    to.num_things += num;
}

int main()
{
    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 100);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 95);

    t1.join();
    t2.join();

    cout<<"Box1 count: "<<acc1.num_things<<endl;
    cout<<"Box2 count: "<<acc2.num_things<<endl;

    return 0;
}
