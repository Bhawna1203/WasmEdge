// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#include "loader/loader.h"

#include <utility>

namespace WasmEdge {
namespace Loader {

// Load to construct Expression node. See "include/loader/loader.h".
Expect<void> Loader::loadExpression(AST::Expression &Expr) {
  if (auto Res = loadInstrSeq()) {
    Expr.getInstrs() = std::move(*Res);
  } else {
    spdlog::error(ErrInfo::InfoAST(ASTNodeAttr::Expression));
    return Unexpect(Res);
  }
  return {};
}

} // namespace Loader
} // namespace WasmEdge
