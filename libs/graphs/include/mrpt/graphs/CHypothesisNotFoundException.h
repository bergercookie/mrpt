/* +---------------------------------------------------------------------------+
         |                     Mobile Robot Programming Toolkit (MRPT) |
         |                          http://www.mrpt.org/ |
         | |
         | Copyright (c) 2005-2016, Individual contributors, see AUTHORS file |
         | See: http://www.mrpt.org/Authors - All rights reserved. |
         | Released under BSD License. See details in
   http://www.mrpt.org/License    |
         +---------------------------------------------------------------------------+
   */

#ifndef CHYPOTHESISNOTFOUNDEXCEPTION_H
#define CHYPOTHESISNOTFOUNDEXCEPTION_H

#include <mrpt/graphs/link_pragmas.h>
#include <mrpt/utils/mrpt_macros.h>
#include <mrpt/utils/types_simple.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// TODO - include docstring, group etc.
class GRAPHS_IMPEXP HypothesisNotFoundException : public std::runtime_error {
public:
  HypothesisNotFoundException(mrpt::utils::TNodeID from,
                              mrpt::utils::TNodeID to);
  HypothesisNotFoundException(size_t id);
  ~HypothesisNotFoundException() throw();
  void clear();
  std::string getErrorMsg() const throw();
  const char *what() const throw();

private:
  mrpt::utils::TNodeID m_from;
  mrpt::utils::TNodeID m_to;

  /**\brief Hypothesis ID */
  size_t m_id;

  /**\brief Error message */
  std::string m_msg;
  static std::ostringstream m_cnvt;
};

#endif /* end of include guard: CHYPOTHESISNOTFOUNDEXCEPTION_H */
