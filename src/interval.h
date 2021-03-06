#pragma once

#include <iostream>
#include <limits>
#include <tuple>

namespace mtidd
{

  ///////////////
  // boudaries //
  ///////////////

  typedef enum { Open, Closed } interval_boundary;

  interval_boundary complement(interval_boundary b);

  std::ostream & operator<<(std::ostream & out, const interval_boundary& b);

  ///////////////////
  // half interval //
  ///////////////////

  typedef std::tuple<double,interval_boundary> half_interval;

  // lhs is the right/end of an interval
  // rhs is the left/start of an interval
  bool ends_before(const half_interval& lhs, const half_interval& rhs);

  // lhs and rhs are the right/end of an interval
  bool operator<=(const half_interval& lhs, const half_interval& rhs);

  bool contains(const half_interval& end, double value);

  // lhs is the right/end of an interval
  // rhs is the left/start of an interval
  const half_interval& min(const half_interval& lhs, const half_interval& rhs);

  std::ostream & operator<<(std::ostream & out, const half_interval& i);

  // sentinel nodes
  const half_interval lower_sentinel = std::make_tuple<double, interval_boundary>(-std::numeric_limits<double>::infinity(), Open);
  const half_interval upper_sentinel = std::make_tuple<double, interval_boundary>( std::numeric_limits<double>::infinity(), Open);

  //////////////
  // interval //
  //////////////

  typedef std::tuple<double,interval_boundary,double,interval_boundary> interval;

  bool is_empty(const interval& i);

  bool is_singleton(const interval& i);

  bool contains(const interval& i, double value);

  half_interval starts_after(const interval& i);

  half_interval ends(const interval& i);

  std::ostream & operator<<(std::ostream & out, const interval& i);

}
