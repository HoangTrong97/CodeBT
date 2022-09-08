#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

long global_count = 0;
void add(int count, int interval_ms)
{   
    for (int i = 0; i < count; i++)
    {   
        global_count++;
        cout << "Global Count = " << global_count<<"\n";
        usleep(interval_ms * 1000);        
    }
    
}
int main()
{
    int count=1000;
    int interval_ms=1;
    thread t1(add,count,interval_ms);
    thread t2(add,count,interval_ms);
    t1.join();
    t2.join();
    return 0;
}
