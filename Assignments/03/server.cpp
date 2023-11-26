#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>

#include "Connection.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"

using namespace std::chrono_literals;

template<typename T, size_t N>
class RingBuffer : public std::vector<T> {
    using size_type = std::vector<T>::size_type;
    using Index = std::atomic<size_type>;

    Index nextStorable = 0;
    Index nextReadable = 0;

    std::counting_semaphore<N> storable{N};
    std::counting_semaphore<N> readable{0};

    std::mutex storeMutex;
    std::mutex readMutex;

    public: 
        RingBuffer() {
            size_type count = N;
            this->resize(count);
        }

        void store(const T& t) {
            storable.acquire();
            {
                std::lock_guard lock{storeMutex};
                this->at(nextStorable) = t;
                nextStorable = ++nextStorable % N;
            }
            readable.release();
        }

        T read() {
            T t;
            readable.acquire();
            {
                std::lock_guard lock{readMutex};
                t = this->at(nextReadable);
                nextReadable = ++nextReadable % N;
            }
            storable.release();
            return t;
        }
};

const uint16_t DefaultPort = 8002; 


int main(int argc, char* argv[]) {
    uint16_t port = argc > 1 ? std::stol(argv[1]) : DefaultPort;

    const int NumSlots = 8;

    std::counting_semaphore<NumSlots> fillable{8};
    std::counting_semaphore<NumSlots> ready{0};
    // std::vector<HTTPRequest> slots(NumSlots);


    RingBuffer<int, 8> buffer;

    Connection connection(port);

    
    const char* root = "/home/faculty/shreiner/public_html/03";

    std::jthread producer{[&](){
        // Data data = 0;
        while (connection) {
            Session session(connection.accept());


            buffer.store(connection.accept());
            std::this_thread::sleep_for(3ms);
        }
        std::cout << "Producer: I'm done\n";
    }};

    std::jthread consumer{[&](){
        int next = 0;
        while (connection) {
            Session session(buffer.read());


            std::string msg;
            session >> msg;

            
            HTTPRequest request(msg);

            HTTPResponse response(request, root);
            session << response;

            // ++next %= NumSlots;
            
            // fillable.release();
    }
        std::cout << "Consumer: I'm done for the day\n";
    }};

}
