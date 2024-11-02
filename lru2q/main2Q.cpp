#include <iostream>
#include <gtest/gtest.h>
#include <fstream>

#include "LRU-2Q.hpp"
#include "containers.hpp"
// #define TESTING

int main() {
    
#ifdef TESTING
    testing::InitGoogleTest();
    auto r = RUN_ALL_TESTS();
#else
    int hits = 0;
    Lru2qCache<TPage> cache1;
    hits = cache1.run();
    std::cout << hits << std::endl;
#endif
}

#ifdef TESTING

#define GTEST(number, fname)                                                \
TEST(count_hits, number) {                                                  \
    int hits, answer;                                                       \
    std::stringstream fTest(fname);                                         \
    Lru2qCache<TPage> cache;                                                       \
    hits = cache.run(fTest);                                      \
                                                                            \
    fTest >> answer;                                                        \
                                                                            \
    EXPECT_EQ(hits, answer);                                                \
}

GTEST(test1, "8 6 1 2 3 4 3 4 2")
GTEST(test2, "8 8 1 2 3 4 1 2 1 2 2")
GTEST(test3, "8 14 1 2 3 4 1 2 5 6 3 4 1 2 3 4 4")
GTEST(test4, "8 22 1 2 3 4 1 2 5 6 3 4 1 2 3 4 7 8 5 6 3 4 5 6 8")
GTEST(test5, "20 500 37 26 19 25 35 29 31 44 46 21 16 31 15 40 9 49 22 13 44 22 7 30 32 9 7 48 13 14 7 6 42 1 5 47 33 46 30 32 23 13 17 40 42 5 13 17 0 47 2 18 8 39 29 11 49 47 0 44 16 30 5 33 17 30 9 41 5 5 44 21 40 44 8 24 41 43 0 0 46 40 14 38 25 29 44 41 16 6 31 37 23 8 24 19 31 1 8 29 45 7 37 44 7 33 21 4 28 49 42 19 5 11 38 41 32 30 19 36 9 42 43 22 20 22 24 15 10 26 39 22 40 14 26 50 12 21 18 43 40 4 32 4 19 49 32 49 12 11 27 2 47 43 6 38 43 50 0 30 28 14 36 13 13 40 2 34 47 26 31 39 23 34 46 22 25 29 50 1 8 49 18 10 22 11 2 41 8 21 8 26 27 44 20 0 35 25 5 15 49 19 32 5 48 26 11 0 30 1 21 9 41 20 26 9 45 10 2 7 27 18 39 20 24 16 44 36 22 24 41 47 0 3 40 3 5 6 46 37 42 47 20 44 39 14 23 44 26 41 9 31 50 18 19 28 21 12 22 47 4 6 24 24 37 42 19 36 50 38 44 46 34 32 43 1 18 4 32 50 6 40 14 45 2 49 8 46 25 11 18 8 45 27 23 45 4 26 42 43 25 42 33 7 1 26 18 1 39 35 43 10 50 37 32 36 19 7 26 7 44 15 26 26 21 5 48 48 35 3 0 45 45 36 15 7 36 1 14 20 2 35 30 17 1 14 46 29 3 3 40 3 6 48 20 25 7 45 42 39 21 16 7 37 34 44 4 26 20 7 44 48 44 40 40 12 21 43 42 5 39 46 48 46 13 9 30 38 26 44 50 38 10 25 10 31 43 10 29 16 34 16 4 50 22 39 18 2 22 17 16 49 2 47 5 26 27 25 8 19 23 37 12 35 29 22 27 28 36 19 5 26 3 44 13 1 12 49 36 13 44 11 13 35 28 7 40 17 8 30 9 21 40 30 6 41 32 26 31 22 21 46 26 28 37 25 10 18 34 30 48 16 19 24 12 38 31 43 31 32 9 1 36 22 27 50 9 27 20 33 2 26 43 48 6 4 18 12 17 49 15 11 122")
GTEST(test7, "2 6 1 2 1 2 1 2 4")
GTEST(test8, "2 5 1 2 3 4 1 0")
GTEST(test9, "4 12 1 2 3 4 1 2 5 1 2 4 3 4 0")
GTEST(test11, "4 10 1 2 3 4 5 5 1 2 3 4 1")
GTEST(test12, "5 100 8 4 1 7 1 2 3 8 7 9 0 1 0 6 10 3 0 8 3 6 2 2 7 6 7 4 10 3 8 3 6 7 4 9 8 8 5 0 3 7 3 1 9 9 7 5 9 9 9 2 4 8 1 4 10 8 5 0 9 5 0 5 6 2 4 1 9 10 7 2 7 10 10 4 0 8 9 7 3 6 4 1 5 8 8 2 7 3 3 3 2 7 4 2 9 7 7 1 0 5 24")

#undef GTEST

#endif