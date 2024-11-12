#include "ideal_cache.hpp"
#include <iostream>
#include "containers.hpp"
#include <sstream>

static int check_hits_ideal_cache(idealCache<TPage> cache, const std::vector<TPage>& pages);

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

    int hits = check_hits_ideal_cache(cache, data);
    return hits;
}

int check_hits_ideal_cache(idealCache<TPage> cache, const std::vector<TPage>& pages) {
    int pagesCount = pages.size();
    int hits = 0;

    for (int currentPageNumber = 0; currentPageNumber < pagesCount; currentPageNumber++) {
        hits += cache.lookup_update(pages, currentPageNumber);
    }
    return hits;
}