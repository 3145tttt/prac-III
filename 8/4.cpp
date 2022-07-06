#include <iostream>

namespace Game {

    template <typename T>
    class Coord {
    public:
        typedef T value_type;

        T row, col;
        Coord(T _row = 0, T _col = 0): row(_row), col(_col) {}
    };

    template <typename T>
    T dist(Coord<T> size, Coord<T> coord1, Coord<T> coord2){
        const T drow = coord2.row - coord1.row, dcol = coord2.col - coord1.col;
        const T drow_abs = abs(drow), dcol_abs = abs(dcol);
        T skip = std::min(drow_abs , (1 + dcol_abs)/2);
        if((!(coord1.col % 2) && drow < 0) || (coord1.col % 2 && drow > 0)){
            skip = std::min(drow_abs , (dcol_abs)/2);
        }
        return drow_abs + dcol_abs - skip;
    }
}