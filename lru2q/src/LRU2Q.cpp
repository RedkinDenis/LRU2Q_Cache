#include <iostream>
#include "LRU-2Q.hpp"

int run (std::istream &input) {

    size_t cacheSize = 0;
    input >> cacheSize;
    Lru2qCache<TPage> cache(cacheSize);

    TPage page;
    int pageCount = 0;
    input >> pageCount;
    
    for (int i = 0; i < pageCount; i++) {

        input >> page;
        cache.lookup_update(page);
    }

    return cache.get_hits();
}