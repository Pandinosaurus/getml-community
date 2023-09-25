// Copyright 2022 The SQLNet Company GmbH
//
// This file is licensed under the Elastic License 2.0 (ELv2).
// Refer to the LICENSE.txt file in the root of the repository
// for details.
//

#ifndef RFL_INTERNAL_NO_DUPLICATE_FIELD_NAMES_HPP_
#define RFL_INTERNAL_NO_DUPLICATE_FIELD_NAMES_HPP_

#include <tuple>

namespace rfl {
namespace internal {

template <class Fields, int _i = 1, int _j = 0>
constexpr inline bool no_duplicate_field_names() {
  constexpr auto num_fields = std::tuple_size<Fields>{};

  if constexpr (num_fields <= 1) {
    return true;
  } else {
    if constexpr (_i == num_fields) {
      return true;
    } else if constexpr (_j == -1) {
      return no_duplicate_field_names<Fields, _i + 1, _i>();
    } else {
      using FieldType1 =
          std::decay_t<typename std::tuple_element<_i, Fields>::type>;
      using FieldType2 =
          std::decay_t<typename std::tuple_element<_j, Fields>::type>;

      constexpr auto field_name_i = FieldType1::name_;
      constexpr auto field_name_j = FieldType2::name_;

      constexpr bool no_duplicate = (field_name_i != field_name_j);

      static_assert(no_duplicate, "Duplicate field names are not allowed");

      return no_duplicate && no_duplicate_field_names<Fields, _i, _j - 1>();
    }
  }
}

}  // namespace internal
}  // namespace rfl

#endif
