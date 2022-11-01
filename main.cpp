#include "logging.h"
#include <thread>
#include <atomic>
using namespace handy;

std::atomic<int> flag{0};

void count() {
    for(int i = 0; i < 10000; i++) {
        info("test line number: %d\n", flag++);
    }
}


int main() {
    Logger::getLogger().setFileName("/home/ejie/test/plog.log");
    for(int i = 0; i < 100; i++) {
        std::thread t(count);
        t.join();
    }
    return 0;


}
