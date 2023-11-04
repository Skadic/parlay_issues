
#include "copy_counter.hpp"
#include <hash_grow/unordered_map.h>
#include <iostream>

// This example does not compile even though it should
int main() {
    parlay::unordered_map<int, CopyCounter<int>> map(100);
    std::cout << "copies after init: " << copy_count << std::endl;

    map.insert(1, CopyCounter<int>(10));
    std::cout << "copies after insert: " << copy_count << std::endl;

    map.find(1);
    std::cout << "copies after find: " << copy_count << std::endl;

    // Problem: This will not compile even though it should.
    // This should take an update function as the second parameter (as hash_nogrow does),
    // but instead it takes a const V&, which is a const CopyCounter<int>& in this case.
    // This is wrong.
    map.upsert(1, [](std::optional<CopyCounter<int>> v) {
        if (v) {
            return CopyCounter(2 * v->value);
        } else {
            return CopyCounter<int>(0);
        }
    });
    std::cout << "copies after upsert: " << copy_count << std::endl;
}
