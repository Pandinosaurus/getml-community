// Copyright 2022 The SQLNet Company GmbH
//
// This file is licensed under the Elastic License 2.0 (ELv2).
// Refer to the LICENSE.txt file in the root of the repository
// for details.
//

#ifndef RFL_EXTRACTDISTRIMINATORS_HPP_
#define RFL_EXTRACTDISTRIMINATORS_HPP_

#include <type_traits>

#include "rfl/TaggedUnion.hpp"
#include "rfl/define_literal.hpp"
#include "rfl/field_type.hpp"
#include "rfl/internal/extract_discriminators.hpp"

namespace rfl {

/// Extracts a Literal containing all of the discriminators from a TaggedUnion.
template <class TaggedUnionType>
using extract_discriminators_t =
    typename internal::extract_discriminators<TaggedUnionType>::type;

}  // namespace rfl

#endif  // RFL_EXTRACTDISTRIMINATORS_HPP_
