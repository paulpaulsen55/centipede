#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H
#include <random>


inline int generateRandomNumber(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(min, max);
    return dist(gen);
}


#endif //UTILITYFUNCTIONS_H
