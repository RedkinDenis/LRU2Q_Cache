#include "../include/ideal_cache.hpp"
#include <iostream>
#include "containers.hpp"
#include <sstream>

// #ifndef TESTING

void run () {

    int sz;
    std::cin >> sz;

    std::vector<TPage> data;
    idealCache<TPage> cache(sz);

    int num;
    std::cin >> num;

    int val;
    for(int i = 0; i < num; i++) {
        std::cin >> val;
        data.push_back(val);
    }

    int hits;
    hits = cache.check_hits_ideal_cache(data);
    std::cout << hits << std::endl;
}

// #else

int run (std::stringstream &input) {

    int sz;
    input >> sz;

    std::vector<TPage> data;
    idealCache<TPage> cache(sz);

    int num;
    input >> num;

    int val;
    for(int i = 0; i < num; i++) {
        input >> val;
        data.push_back(val);
    }

    int hits;
    hits = cache.check_hits_ideal_cache(data);
    return hits;
}

// #endif