#ifndef CENIGMA_DSG115_PAIR_H
#define CENIGMA_DSG115_PAIR_H

template<typename T>
class Pair {
public:
    Pair(T x, T y) : x(x), y(y) { }
private:
    T x;
    T y;
};


#endif //CENIGMA_DSG115_PAIR_H
