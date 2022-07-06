#include <iostream>

struct Item
{
    Item *next;
    long long value;
};

class Arena{
    bool *used;
    int count, free;
    Item *item_arr;
    
    inline bool is_full(){
        return free == 0;
    }
public:
    explicit Arena(size_t size){
        count = size / sizeof(Item);
        used = new bool[count];
        item_arr = new Item[count];
        free = count;

        for(int i = 0; i < count; ++i){
            used[i] = false;
        }
    }

    ~Arena(){
        delete[] used;
        delete[] item_arr;
    }

    Item *get(){
        if(is_full()) {
            return nullptr;
        }
        for(int i = 0; i < count; ++i){
            if(!used[i]){
                used[i] = true;
                --free;
                return item_arr + i;
            }
        }
        return nullptr;
    }

    void put(Item *el){
        const int POS = el - item_arr;
        used[POS] = false;
        ++free;
    }

    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;

};

int main(){
    Arena my_arena(sizeof(Item)*5);
    for(int i = 0; i < 10; ++i){
        std::cout <<  my_arena.get() << std::endl;
    }
}