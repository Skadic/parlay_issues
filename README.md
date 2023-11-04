# Parlay Issues

There are three CMake targets in this repo: `nogrow_upsert`, `grow_upsert` and `nogrow_corrupt`.

## Usage

Create the build environment using.

```sh
cmake --preset=default
```

And then build the desired target using:

```sh
cmake --build --preset=<release|relwithdeb|debug> -t <target>
```

## Targets

### `nogrow_upsert`

`nogrow_upsert` is a simple example using the non-growing map with an `insert`, a `find` and an `upsert`, all working as expected.

### `grow_upsert`

`grow_upsert` is using the exact same code as `nogrow_upsert` just using the growing map.
This showcases that the signature of the `upsert` function is different from the `nogrow` map.
In `nogrow`, we have:

```cpp
template <typename F>
bool upsert(const K& k, const F& f) {
  ...
}
```

where as in `grow`, we have:

```cpp
bool upsert(const K& k, const V& v) {
  ...
}
```

even though it should match the signature in `nogrow`.
It also seems that this problem is not just fixed by changing the signature in `grow`, as this leads to further compiler errors.

### `nogrow_corrupt`

`nogrow_corrupt` is a simple example inserting `1_000_000` elements into a map, then `upsert`-ing all of them.
Run this in debug, or relwithdeb mode, and it willl crash with `corrupted head`/`corrupted tail` errors.
