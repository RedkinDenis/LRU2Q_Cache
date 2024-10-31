#pragma once

#include <unordered_map>
#include <list>

#include "containers.hpp"

void lookup_update_LRU (Hashtable<TPage> & map, cacheList<TPage> & lst, int elem, int & hits);