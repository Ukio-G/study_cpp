#include <vector>
#include <iostream>


template <class T>
class SuperVector : public std::vector<T> {
    public:
    void ultimate_size() {
        std::cout << std::vector<T>::size() << std::endl;
    }   
    int sum = 0;
    void push_back(T t) {
        std::cout << "super push \n";
        std::vector<T>::push_back(t);
        sum += t;
    }

    void push_back(T & t) {
        std::cout << "super push \n";
        std::vector<T>::push_back(t);
    }

    void getSum() {
        std::cout << "sum = " << sum << "\n";
    }
};

int main()
{

    SuperVector<int> sv;

    sv.push_back(1);
    sv.push_back(2);
    sv.push_back(3);
    sv.push_back(4);

    sv.ultimate_size();
    
    sv.getSum();

    return 0;
}
