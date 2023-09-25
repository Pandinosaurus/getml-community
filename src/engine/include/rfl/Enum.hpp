// Copyright 2022 The SQLNet Company GmbH
//
// This file is licensed under the Elastic License 2.0 (ELv2).
// Refer to the LICENSE.txt file in the root of the repository
// for details.
//

#ifndef RFL_ENUM_HPP_
#define RFL_ENUM_HPP_

#include <tuple>
#include <variant>

#include "rfl/NamedTuple.hpp"
#include "rfl/internal/StringLiteral.hpp"
#include "rfl/internal/no_duplicate_field_names.hpp"

namespace rfl {

template <class... FieldTypes>
struct Enum {
  using Fields = std::tuple<FieldTypes...>;

  /// The type of the underlying variant.
  using VariantType = std::variant<FieldTypes...>;

  Enum(const VariantType& _variant) : variant_(_variant) {
    static_assert(internal::no_duplicate_field_names<Fields>(),
                  "Duplicate field names are not allowed");
  }

  Enum(VariantType&& _variant) : variant_(std::forward<VariantType>(_variant)) {
    static_assert(internal::no_duplicate_field_names<Fields>(),
                  "Duplicate field names are not allowed");
  }

  ~Enum() = default;

  /// Assigns the underlying variant.
  inline void operator=(const VariantType& _variant) {
    static_assert(internal::no_duplicate_field_names<Fields>(),
                  "Duplicate field names are not allowed");
    variant_ = _variant;
  }

  /// Assigns the underlying variant.
  inline void operator=(VariantType&& _variant) {
    static_assert(internal::no_duplicate_field_names<Fields>(),
                  "Duplicate field names are not allowed");
    variant_ = std::forward<VariantType>(_variant);
  }

  /// The underlying variant - an Enum is a thin wrapper
  /// around a variant that is mainly used for parsing.
  VariantType variant_;
};

}  // namespace rfl

#endif  // RFL_TAGGEDUNION_HPP_
