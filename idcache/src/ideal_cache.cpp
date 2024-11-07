#include "ideal_cache.hpp"
#include <iostream>
#include "containers.hpp"
#include <sstream>


int run (std::istream &input) {

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