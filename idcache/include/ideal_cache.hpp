#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template<typename T>
class idealCache {
public:
    idealCache(size_t setSz) : sz(setSz) {}

    int check_hits_ideal_cache(const std::vector<T>& pages) {
        int pagesCount = pages.size();
        int hits = 0;

        for (int currentPageNumber = 0; currentPageNumber < pagesCount; currentPageNumber++) {
            hits += lookup_update(pages, currentPageNumber);
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

    int lookup_update (const std::vector<T>& pages, int currentPageNumber) {

        T page = pages[currentPageNumber];
        if (hashtable.count(page) != 0) {
            return 1;
        }

        if (cache.size() < sz) {
            add_to_cache(page);
        } 
        else if (delete_extra_page(pages, currentPageNumber))
            add_to_cache(page);
        
        return 0; 
    }

    bool delete_extra_page (const std::vector<T>& pages, int currentPageNumber) {

        T page = pages[currentPageNumber];
        T pageToDelete = cache[0]; 
        int furthestIndex = -1;

        cache.push_back(page);
        for (const auto& cachedPage : cache) {

            auto it = std::find(pages.begin() + currentPageNumber + 1, pages.end(), cachedPage);
            if (it != pages.end()) {
                int index = std::distance(pages.begin(), it);
                if (index > furthestIndex) {
                    furthestIndex = index;
                    pageToDelete = cachedPage; 
                }
            } 
            else {
                pageToDelete = cachedPage;
                break;
            }
        }
        cache.pop_back();

        if (pageToDelete == page) return false;

        hashtable.erase(pageToDelete);
        cache.erase(std::remove(cache.begin(), cache.end(), pageToDelete), cache.end());

        return true;
    }

    void add_to_cache (T page) {
        cache.push_back(page);
        hashtable[page] = cache.end() - 1;
    }
};


int run (std::istream &input = std::cin);