// Copyright 2022 The SQLNet Company GmbH
//
// This file is licensed under the Elastic License 2.0 (ELv2).
// Refer to the LICENSE.txt file in the root of the repository
// for details.
//

#ifndef RFL_GET_HPP_
#define RFL_GET_HPP_

#include "rfl/internal/Getter.hpp"
#include "rfl/internal/StringLiteral.hpp"

namespace rfl {

/// Gets a field by index.
template <int _index, class NamedTupleType>
inline auto& get(NamedTupleType& _tup) {
  return internal::Getter<NamedTupleType>::template get<_index>(_tup);
}

/// Gets a field by name.
template <internal::StringLiteral _field_name, class NamedTupleType>
inline auto& get(NamedTupleType& _tup) {
  return internal::Getter<NamedTupleType>::template get<_field_name>(_tup);
}

/// Gets a field by the field type.
template <class Field, class NamedTupleType>
inline auto& get(NamedTupleType& _tup) {
  return internal::Getter<NamedTupleType>::template get<Field>(_tup);
}

/// Gets a field by index.
template <int _index, class NamedTupleType>
inline const auto& get(const NamedTupleType& _tup) {
  return internal::Getter<NamedTupleType>::template get_const<_index>(_tup);
}

/// Gets a field by name.
template <internal::StringLiteral _field_name, class NamedTupleType>
inline const auto& get(const NamedTupleType& _tup) {
  return internal::Getter<NamedTupleType>::template get_const<_field_name>(
      _tup);
}

/// Gets a field by the field type.
template <class Field, class NamedTupleType>
inline const auto& get(const NamedTupleType& _tup) {
  return internal::Getter<NamedTupleType>::template get_const<Field>(_tup);
}

}  // namespace rfl

#endif
