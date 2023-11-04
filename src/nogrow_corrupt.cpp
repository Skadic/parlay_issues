#include "copy_counter.hpp"

#include <hash_nogrow/unordered_map.h>

#define NUM_ITERS 1000000

// This simple example leads to a corrupted data structure
int main() {
    parlay::unordered_map<int, int> map(NUM_ITERS);
    for (int i = 0; i < NUM_ITERS; i++) {
        map.insert(i, i);
    }

    // Upsert all values once
    for (int i = 0; i < NUM_ITERS; i++) {
        map.upsert(i, [i](std::optional<int> v) -> int {
            if (v) {
                return 2 * i;
            } else {
                return -i;
            }
        });
    }

    // Build in Debug, or RelwithDebInfo mode
    // and this will terminate with a "corrupted head"/"corrupted tail" error
}
