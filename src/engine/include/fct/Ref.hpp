// Copyright 2022 The SQLNet Company GmbH
// 
// This file is licensed under the Elastic License 2.0 (ELv2). 
// Refer to the LICENSE.txt file in the root of the repository 
// for details.
// 

#ifndef FCT_REF_HPP_
#define FCT_REF_HPP_

#include <memory>
#include <stdexcept>

namespace fct {

/// The Ref class behaves very similarly to the shared_ptr, but unlike the
/// shared_ptr, it is 100% guaranteed to be filled at all times.
template <class T>
class Ref {
 public:
  /// The default way of creating new references is
  /// Ref<T>::make(...).
  template <class... Args>
  static Ref<T> make(Args... _args) {
    const auto ptr = new T(_args...);
    return Ref<T>(ptr);
  }

  /// Wrapper around a shared_ptr, leads to a runtime error,
  /// if the shared_ptr is not allocated.
  explicit Ref(const std::shared_ptr<T>& _ptr) {
    assert_true(_ptr);
    if (!_ptr) {
      throw std::runtime_error(
          "Could not create Ref from shared_ptr, because shared_ptr was not "
          "set.");
    }
    ptr_ = _ptr;
  }

  template <class Y>
  Ref(const Ref<Y>& _other) : ptr_(_other.ptr()) {}

  ~Ref() = default;

  /// Returns a pointer to the underlying object
  inline T* get() const { return ptr_.get(); }

  /// Returns the underlying object.
  inline T& operator*() const { return *ptr_; }

  /// Returns the underlying object.
  inline T* operator->() const { return ptr_.get(); }

  /// Returns the underlying shared_ptr
  inline const std::shared_ptr<T>& ptr() const { return ptr_; }

  /// Copy assignment operator.
  template <class Y>
  Ref<T>& operator=(const Ref<Y>& _other) {
    ptr_ = _other.ptr();
    return *this;
  }

 private:
  /// Only make is allowed to use this constructor.
  explicit Ref(T* _ptr) : ptr_(std::shared_ptr<T>(_ptr)) {}

 private:
  /// The underlying shared_ptr_
  std::shared_ptr<T> ptr_;
};

}  // namespace fct

#endif  // FCT_REF_HPP_

