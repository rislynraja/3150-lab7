
#include "lab7.h"

std::pair<bigint, bigint> myproduct(std::pair<bigint, bigint> n1, std::pair<bigint, bigint> n2){ // takes two fractions of bigints and returns fraction
    bigint numerator = n1.first * n2.first;
    bigint denominator = n1.second * n2.second;
    std::pair<bigint, bigint> answer = std::make_pair(bigint(numerator), bigint(denominator));
    return answer;
}

std::pair<bigint,bigint> mysum(std::pair<bigint, bigint> n1, std::pair<bigint, bigint> n2) {
    bigint numerator = n1.first * n2.second + n2.first * n1.second;
    bigint denominator = n1.second * n2.second;
    std::pair<bigint, bigint> answer = std::make_pair(bigint(numerator), bigint(denominator));
    return answer;
}

