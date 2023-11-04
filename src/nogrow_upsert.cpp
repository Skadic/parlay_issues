
#include "copy_counter.hpp"
#include <hash_nogrow/unordered_map.h>
#include <iostream>

// This example works as it should
int main() {
    parlay::unordered_map<int, CopyCounter<int>> map(100);
    std::cout << "copies after init: " << copy_count << std::endl;

    map.insert(1, CopyCounter<int>(10));
    std::cout << "copies after insert: " << copy_count << std::endl;

    map.find(1);
    std::cout << "copies after find: " << copy_count << std::endl;

    map.upsert(1, [](std::optional<CopyCounter<int>> v) {
        if (v) {
            return CopyCounter(2 * v->value);
        } else {
            return CopyCounter<int>(0);
        }
    });
    std::cout << "copies after upsert: " << copy_count << std::endl;
}
