#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "containers.hpp"
// #include "LRU.hpp"

#define LRU2Q_MIN_CACHE_SIZE 3

template<typename T>
struct Q2Lists {

    cacheList<T> lstAm = {};
    cacheList<T> lstA1In = {};
    cacheList<T> lstA1Out = {};

    inline void set_lists_size (size_t cacheSize) {

        if (cacheSize > LRU2Q_MIN_CACHE_SIZE) {
            
            lstAm.listSize = cacheSize / 2;        
            lstA1In.listSize = (cacheSize - lstAm.listSize) / 2;
            lstA1Out.listSize = cacheSize - lstAm.listSize - lstA1In.listSize;

            return;
        }
        lstAm.listSize = cacheSize;
    }
};

template<typename T>
struct Q2HashTables {

    Hashtable<T> mapAm = {};
    Hashtable<T> mapIn = {};
    Hashtable<T> mapOut = {};
};

template<typename T>
class Lru2qCache {

private:
    enum class cacheType {
        LRU,
        LRU2Q
    };

public:

    int run () {

        T page;

        int cacheSize = 0;
        std::cin >> cacheSize;

        int pageCount = 0;
        std::cin >> pageCount;

        lists.set_lists_size(cacheSize);
        
        set_type(cacheSize);

        for (int i = 0; i < pageCount; i++) {

            std::cin >> page;
            lookup_update(page);
        }

        return hits;
    }

    int run (std::stringstream &input) {

        T page;

        int cacheSize = 0;
        input >> cacheSize;

        int pageCount = 0;
        input >> pageCount;

        lists.set_lists_size(cacheSize);

        set_type(cacheSize);

        for (int i = 0; i < pageCount; i++) {

            input >> page;
            lookup_update(page);
        }

        return hits;
    }

private:

    cacheType type;
    Q2Lists<T> lists = {};
    Q2HashTables<T> hashTables = {}; 
    int hits = 0;
    
    void lookup_update (T elem) {

        if (type == cacheType::LRU2Q)
            lookup_update_2Q(elem);
        else if (type == cacheType::LRU)
            lookup_update_LRU(elem);
        else 
            std::cerr << "unknown cache type" << std::endl;
    }

private:

    // LRU2Q methods    
    void lookup_update_2Q(T elem) {

        if (in_map_am(elem)) return;
        if (in_map_in(elem)) return;
        if (in_map_out(elem)) return;
        add_new_page(elem);
    }

    bool in_map_am (T elem) {

        bool isInMapAm = hashTables.mapAm.count(elem) > 0;

        if (!isInMapAm) { 
            return false;
        }

        hits += 1;
        delete_from_cache(lists.lstAm, hashTables.mapAm, elem);
        add_to_cache(lists.lstAm, hashTables.mapAm, elem);
        return true;
    }

    bool in_map_in (T elem) {

        bool isInMapIn = hashTables.mapIn.count(elem) > 0;

        if (!isInMapIn) {
            
            return false;
        }

        hits += 1;
        delete_from_cache(lists.lstA1In, hashTables.mapIn, elem);
        add_to_cache(lists.lstA1In, hashTables.mapIn, elem);
        return true;
    }

    bool in_map_out (T elem) {

        bool isInMapOut = hashTables.mapOut.count(elem) > 0;

        if (!isInMapOut) {
            
            return false;
        }

        delete_from_cache(lists.lstA1Out, hashTables.mapOut, elem);
        if (lists.lstAm.lst.size() == lists.lstAm.listSize) {
            delete_from_cache(lists.lstAm, hashTables.mapAm);
        }
        
        add_to_cache(lists.lstAm, hashTables.mapAm, elem);
        return true;
            
    }

    void add_new_page (T elem) {

        if (lists.lstA1In.listSize == lists.lstA1In.lst.size()) {

            if (lists.lstA1Out.lst.size() == lists.lstA1Out.listSize) {
                delete_from_cache(lists.lstA1Out, hashTables.mapOut);
            }

            add_to_cache(lists.lstA1Out, hashTables.mapOut, lists.lstA1In.lst.back());
            delete_from_cache(lists.lstA1In, hashTables.mapIn);
        }
        add_to_cache(lists.lstA1In, hashTables.mapIn, elem);
    }


    void add_to_cache (cacheList<T> &list, Hashtable<T> &map, T elem) {

        list.lst.push_front(elem);
        map.insert({elem, list.lst.begin()});
    }

    // delete by search in map
    void delete_from_cache (cacheList<T> &list, Hashtable<T> &map, T elem) {

        list.lst.erase(map.find(elem)->second);
        map.erase(elem);
    }

    // delete from list's tail
    void delete_from_cache (cacheList<T> &list, Hashtable<T> &map) {

        map.erase(list.lst.back());
        list.lst.pop_back();
    }

    void set_type (size_t cacheSize) {

        if (cacheSize > LRU2Q_MIN_CACHE_SIZE) 
            type = cacheType::LRU2Q;
        else
            type = cacheType::LRU;
    }
    
private:
    // classic LRU cache methods
    void lookup_update_LRU (T elem) {
    
        if (in_cache_LRU(elem)) return;
        push_to_head_LRU(elem);
    }

    bool in_cache_LRU (T elem) {

        auto &map = hashTables.mapAm;
        auto &lst = lists.lstAm;

        if (map.count(elem) == 0)  {
            return false;
        }
        
        hits += 1;

        lst.lst.erase(map.find(elem)->second);
        map.erase(elem);

        lst.lst.push_front(elem);
        map.insert({elem, lst.lst.begin()});
        return true;
    }

    void push_to_head_LRU (T elem) {

        auto &map = hashTables.mapAm;
        auto &lst = lists.lstAm;

        if (lst.lst.size() == lst.listSize) {

            map.erase(lst.lst.back());
            lst.lst.pop_back();
        }
        lst.lst.push_front(elem);
        map.insert({elem, lst.lst.begin()});
    }
};