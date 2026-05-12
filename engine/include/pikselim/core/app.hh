//===----------------------------------------------------------------------===//
// Copyright (C) 2026
//
// Author: v4m3rrr
//
// Licensed under the MIT License.
// See LICENSE file in the project root for details.
//===----------------------------------------------------------------------===//
#ifndef PIKSELIM_CORE_APP_H
#define PIKSELIM_CORE_APP_H

/// \file
/// This file contains application implementation, which is responsible for
/// making connection with engine.
namespace pikselim::core{
class App {
public:
  App() = default;

  /// \brief Tests if everything works fine
  ///
  /// \return Returns pope number.
  int test();
};
} // namespace pikselim::core
#endif
