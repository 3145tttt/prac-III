#include "1.cpp"
#include <cstring>

namespace numbers {
    class complex_stack {
    private:
        complex *stack = nullptr;
        size_t cur_len = 0, capacity = 128;
    public:

        complex_stack() {
            stack = new complex[capacity];
        }

        complex_stack(const complex_stack &other) {
            cur_len = other.cur_len;
            capacity = other.capacity;
            if(stack != nullptr) {
                delete[] stack;
            }
            stack = new complex[capacity];
            std::memcpy(stack, other.stack, cur_len*sizeof(complex));
        }

        void operator=(const complex_stack &other) {
            cur_len = other.cur_len;
            capacity = other.capacity;
            if(stack != nullptr) {
                delete[] stack;
            }
            stack = new complex[capacity];
            std::memcpy(stack, other.stack, cur_len*sizeof(complex));
        }

        ~complex_stack() {
            delete[] stack;
        }

        size_t size() const {
            return cur_len;
        }

        complex& operator[](size_t ind) const {
            return stack[ind];
        }

        friend complex_stack operator<<(const complex_stack &my_stack, const complex &new_num);

        friend complex_stack operator~(const complex_stack &my_stack);
    };

    complex_stack operator<<(const complex_stack &my_stack, const complex &new_num) {
        complex_stack tmp = my_stack;
        if (tmp.cur_len == tmp.capacity) {
            tmp.capacity *= 2;
            complex *new_stack = new complex[tmp.capacity];
            std::memcpy(new_stack, tmp.stack, tmp.cur_len*sizeof(complex));
            delete[] tmp.stack;

            tmp.stack = new_stack;

        }
        tmp.stack[tmp.cur_len++] = new_num;
        return tmp;
    }

    complex operator+(const complex_stack &my_stack) {
        return my_stack[my_stack.size() - 1];
    }

    complex_stack operator~(const complex_stack &my_stack) {
        complex_stack tmp = my_stack;
        --tmp.cur_len;

        return tmp;
    }

}