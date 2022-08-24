#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <vector>
std::mutex coutmutex;
using namespace std;

long global_count = 0;
void add(int count, int interval_ms)
{   
    for (int i = 0; i < count; i++)
    {   
	    coutmutex.lock();
        global_count++;
   //     cout << "Global Count = " << global_count<<"\n";
        coutmutex.unlock();
        usleep(interval_ms * 10000);  
    }
    
}
int main()
{   
    vector <thread> th; 
    int count=1000000;
    int interval_ms=1;
    for(int i=0;i<100;i++){
        th.push_back(thread(add,count,interval_ms)); 
    }
    for (thread &t: th) {
        t.join();  
    }
    cout << "Global Count = " << global_count<<"\n";
    return 0;

}