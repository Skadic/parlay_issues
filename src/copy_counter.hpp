#include <atomic>
#include <concepts>

static std::atomic_int copy_count = 0;

/// Simple struct holding a value, counting how often it is copied in copy_count
template <typename T>
  requires std::copy_constructible<T> && std::move_constructible<T> &&
           std::default_initializable<T>
struct CopyCounter {
  T value;

  CopyCounter() : value() {}
  CopyCounter(T&& v) : value(std::move(v)) {}

  // Copy
  CopyCounter(const CopyCounter& other) : value(other.value) {
    copy_count++;
  }
  CopyCounter& operator=(const CopyCounter& other) {
    copy_count++;
    value = other.value;
    return *this;
  }

  // Move
  CopyCounter(CopyCounter&& other) = default;
  CopyCounter& operator=(CopyCounter&& other) = default;
};

static_assert(std::default_initializable<CopyCounter<int>>);
static_assert(std::copy_constructible<CopyCounter<int>>);
static_assert(std::move_constructible<CopyCounter<int>>);
