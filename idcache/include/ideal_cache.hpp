#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

#include <unordered_map>

template<typename T>
class idealCache {

public:

    idealCache (size_t setSz) : sz(setSz) {}

    int check_hits_ideal_cache(std::vector<T> pages) {

        int pagesCount = pages.size();
        auto pgIt = pages.begin();

        for(int currentPageNumber = 0; currentPageNumber < pagesCount; currentPageNumber++, pgIt++) {

            lookup_update(pgIt, pages.end());
        }
        return hits;
    }

private:

    using ListIterator = typename std::vector<T>::iterator;
    using Hashtable = std::unordered_map<T, ListIterator>;

    Hashtable hashtable;
    std::vector<T> cache;

    size_t sz;
    int hits = 0;

    void lookup_update (ListIterator pgIt, ListIterator pEnd) {

        if (hashtable.count(*pgIt) == 0) {

            if (cache_full(pgIt, pEnd)) return;
            add_to_cache(*pgIt, pEnd);
            return;
        }

        hits++;
    }

    bool cache_full (ListIterator pgIt, ListIterator pEnd) {

        if (cache.size() < sz) {

            return false;
        }

        delete_extra_page(pgIt, pEnd);
    
        return true;
    }

    void delete_extra_page (ListIterator pgIt, ListIterator pEnd) {

        ListIterator inpIt = pgIt + 1;
        auto max = std::find(inpIt, pEnd, cache[0]), del = cache.begin();
        ListIterator pos;

        if (max != pEnd) {

            for (auto cacheIt = std::next(cache.begin()); cacheIt != cache.end(); ++cacheIt) {

                pos = std::find(inpIt, pEnd, *cacheIt);

                if (max < pos) {
                    max = pos;
                    del = cacheIt;
                }

                if (max == pEnd) {
                    break;
                }
            }
        }

        if (std::find(inpIt, pEnd, *pgIt) < max) {

            delete_from_cache(*del, del);
            add_to_cache(*pgIt, pEnd - 1);
        }
    }

    void add_to_cache (T page, ListIterator it) {

        cache.push_back(page);
        hashtable.insert({page, it});
    }
    
    void delete_from_cache (T page, ListIterator it) {

        hashtable.erase(page);
        cache.erase(it);
    }
};

void run ();

int run (std::stringstream &input);