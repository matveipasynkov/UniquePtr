#pragma once
template <class T>
class UniquePtr {
 private:
  T* ptr_ = nullptr;
 public:
  UniquePtr() = default;
  explicit UniquePtr(T* other_ptr) {
    ptr_ = other_ptr;
  }
  UniquePtr(const UniquePtr&) = delete;
  UniquePtr& operator=(const UniquePtr&) = delete;
  UniquePtr(UniquePtr&& other_ptr) noexcept {
    ptr_ = other_ptr.ptr_;
    other_ptr.ptr_ = nullptr;
  }
  UniquePtr& operator=(UniquePtr&& other_ptr) noexcept {
    if (this != &other_ptr) {
      Reset(other_ptr.ptr_);
      other_ptr.ptr_ = nullptr;
    }
    return *this;
  }
  T* Release() {
    T* new_ptr = ptr_;
    ptr_ = nullptr;
    return new_ptr;
  }
  void Reset(T* ptr = nullptr) {
    delete ptr_;
    ptr_ = ptr;
  }
  void Swap(UniquePtr& other_ptr) {
    UniquePtr tmp = UniquePtr();
    tmp.ptr_ = Release();
    ptr_ = other_ptr.Release();
    other_ptr.ptr_ = tmp.Release();
  }
  T* Get() const {
    return ptr_;
  }
  T& operator*() const {
    return *ptr_;
  }
  T* operator->() const {
    return ptr_;
  }
  explicit operator bool() const {
    return ptr_ != nullptr;
  }
  ~UniquePtr() {
    delete ptr_;
  }
};