// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdint>
unsigned int collatzLen(uint64_t num) {
    unsigned int len = 1;
    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        } else {
            num >>= 1;
        }
        len++;
    }
    return len;
}
uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;
    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        } else {
            num >>= 1;
        }
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}
unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound,
                        uint64_t *maxValue) {
    unsigned int bestNum = lbound;
    unsigned int bestLen = collatzLen(lbound);
    uint64_t bestMaxVal = collatzMaxValue(lbound);
    for (uint64_t n = lbound + 1; n <= rbound; n++) {
        unsigned int len = collatzLen(n);
        if (len > bestLen) {
            bestLen = len;
            bestNum = n;
            bestMaxVal = collatzMaxValue(n);
        }
    }
    if (maxlen) {
        *maxlen = bestLen;
    }
    if (maxValue) {
        *maxValue = bestMaxVal;
    }
    return bestNum;
}
int main() {
    uint64_t lbound = 2;
    uint64_t rbound = 1000000;
    unsigned int maxlen;
    uint64_t maxValue;
    unsigned int bestNum = seqCollatz(&maxlen, lbound, rbound, &maxValue);
    std::cout << "Число с самой длинной последовательностью: "
        << bestNum << std::endl;
    std::cout << "Длина последовательности: "
        << maxlen << std::endl;
    std::cout << "Максимальное число в последовательности: "
        << maxValue << std::endl;
    return 0;
}
