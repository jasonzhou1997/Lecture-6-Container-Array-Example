#include <iostream>
using namespace std;

class Array {
    size_t length = 0;
    double *data = nullptr;

public:
    Array(size_t len):
    length{len},
    data{new double[length]} {}

    ~Array(){
        delete[] data;
        data = nullptr;
    }

    size_t size() const{
        return length;
    }
};

int main()
{
    return 0;
}