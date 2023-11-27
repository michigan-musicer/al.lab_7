#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;
    std::cout << "Capacity is " << v.capacity() << ", size is " << v.size() << std::endl;
    v.push_back(0);
    std::cout << "Capacity is " << v.capacity() << ", size is " << v.size() << std::endl;
    v.push_back(1);
    std::cout << "Capacity is " << v.capacity() << ", size is " << v.size() << std::endl;
    v.push_back(2);
    std::cout << "Capacity is " << v.capacity() << ", size is " << v.size() << std::endl;
    v.push_back(3);
    v.push_back(4);
    std::cout << "Capacity is " << v.capacity() << ", size is " << v.size() << std::endl;

}