#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

#include <unordered_map>

template<typename T>
class idealCache {

public:

    idealCache (size_t setSz) : sz(setSz) {}

    int check_hits_ideal_cache(std::vector<T> &pages) {

        int pagesCount = pages.size();
        int hits = 0;
        for(int currentPageNumber = 0; currentPageNumber < pagesCount; currentPageNumber++) {

            lookup_update(pages, currentPageNumber, hits);
        }
        return hits;
    }

private:

    std::vector<T> cache;

    using ListIterator = typename std::vector<T>::iterator;
    using Hashtable = std::unordered_map<T, ListIterator>;

    Hashtable hashtable;

    size_t sz;

    void lookup_update (std::vector<T> &pages, int &currentPageNumber, int &hits) {

        if (hashtable.count(pages[currentPageNumber]) == 0) {

            if (cache.size() < sz) {

                cache.push_back(pages[currentPageNumber]);
                hashtable.insert({pages[currentPageNumber], pages.end() - 1});
            }

            else {

                auto inpIt = pages.begin();
                std::advance(inpIt, currentPageNumber + 1);

                auto max = std::find(inpIt, pages.end(), cache[0]), del = cache.begin();
                ListIterator pos;

                if (max != pages.end()) {

                    for (auto cacheIt = std::next(cache.begin()); cacheIt != cache.end(); ++cacheIt) {

                        pos = std::find(inpIt, pages.end(), *cacheIt);

                        if (max < pos) {
                            max = pos;
                            del = cacheIt;
                        }

                        if (max == pages.end()) {

                            break;
                        }
                    }
                }

                if (std::find(inpIt, pages.end(), pages[currentPageNumber]) < max) {

                    hashtable.erase(*del);
                    cache.erase(del);
                    
                    cache.push_back(pages[currentPageNumber]);
                    hashtable.insert({pages[currentPageNumber], pages.end() - 1});
                }
            }
            return;
        }

        hits++;
    }
};

// #ifndef TESTING

void run ();

// #else

int run (std::stringstream &input);

// #endif