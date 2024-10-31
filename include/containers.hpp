#pragma once

#include <unordered_map>
#include <list>

using TPage = int;

template<typename T>
using List = std::list<T>;

template<typename T>
struct cacheList {
    List<T> lst;
    size_t listSize = 0;
};

template<typename T>
using Hashtable = std::unordered_map<T, typename List<T>::iterator>;