// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c, bool f) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  if(f)
  mtx.lock();
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  if(f)
  mtx.unlock();
}

int main ()
{
  bool lockFlag=true;
  std::thread th1 (print_block,50,'*',lockFlag);
  std::thread th2 (print_block,50,'$',lockFlag);

  th1.join();
  th2.join();

  return 0;
}
