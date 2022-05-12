#include <iostream>
#include <utility>
using namespace std;

class Array {
    size_t length = 0;
    double *data = nullptr;

public:
    Array(size_t len):
    length{len},
    data{new double[length]} {}

    // copy constructor:
    Array(const Array &a):
    length{a.length},
    data{new double[length]}
    {
        for (size_t i = 0; i < length; i++)
        {
            data[i] = a.data[i];
        }
    }
    //copy swap method:
    Array& operator=(const Array &rhs)
    {
        Array temp(rhs);

        swap(length, temp.length);
        swap(data, temp.data);

        return *this;
    }

    // operator[] overloading
    double &operator[](size_t i)
    {
        if (i < length)
        {
            return data[i];
        }
        throw runtime_error("bad index i");
    }
    // need to also implement a const version of operator[]:

    ~Array(){
        delete[] data;
        data = nullptr;
    }

    size_t size() const{
        return length;
    }
};

// print the array
ostream &operator<<(ostream &os, const Array &Arr)
{
    for (size_t i = 0; i < Arr.size(); i++)
    {
        os << Arr[i] << " ";
    }
    return os;
}

int main()
{
    cout << "Test Array: \n";
    Array a(10);
    Array b(20);
    Array c{b};
    cout << "size of a: " << a.size() << "\n";
    cout << "size of b: " << b.size() << "\n";
    cout << "size of c: " << c.size() << "\n";

    Array d = b;
    cout << "size of c: " << d.size() << "\n";
    // shallow copy, resulting double free error with the destructor
    a = c;
    cout << "size of a now: " << a.size() << "\n";

    cout << "More Test: \n";
    Array A(3);
    A[0] = 25;
    A[2] = 30;
    A[1] = A[0] + A[2];


    return 0;
}