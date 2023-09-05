// Copyright 2022 The SQLNet Company GmbH

//
// This file is licensed under the Elastic License 2.0 (ELv2).
// Refer to the LICENSE.txt file in the root of the repository
// for details.
//

#ifndef RFL_JSON_READ_HPP_
#define RFL_JSON_READ_HPP_

#include <yyjson.h>

#include <string>

#include "rfl/json/Parser.hpp"
#include "rfl/json/Reader.hpp"

namespace rfl {
namespace json {

using InputObjectType = typename Reader::InputObjectType;
using InputVarType = typename Reader::InputVarType;

/// Parses an object from JSON using reflection.
template <class T>
T read(const std::string& _json_str) {
  yyjson_doc* doc = yyjson_read(_json_str.c_str(), _json_str.size(), 0);
  InputVarType root = InputVarType(yyjson_doc_get_root(doc));
  const auto r = Reader();
  const auto result = Parser<T>::read(r, &root);
  yyjson_doc_free(doc);
  return result.value();
}

}  // namespace json
}  // namespace rfl

#endif
