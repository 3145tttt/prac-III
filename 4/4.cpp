#include <iostream>

class Holder
{
    int value = 0;

public:
    Holder()
    {
        std::cin >> value;
    }

    ~Holder()
    {
        std::cout << value << std::endl;
    }

    void swap(Holder &other)
    {
        int tmp = value;
        value = other.value;
        other.value = tmp;
    }
};

int main()
{
    int count;
    std::cin >> count;
    if (count <= 0) {
        return 0;
    }

    Holder *arr = new Holder[count];
    for(int i = 0; i < count/2; ++i){
        arr[i].swap(arr[count - i - 1]);
    }
    delete[] arr;

}