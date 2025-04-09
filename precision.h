#ifndef PRECISION_H
#define PRECISION_H

namespace wengine {
  // Defines a real number precision - default single precision
  // Reason: Change precision of the whole engine by changing typedef
  typedef float real;

  // Defines the precision of the square root operator
  # define real_sqrt sqrtf

  // Defines the precision of the pow operator
  # define real_pow powf
}

#endif // PRECISION_H
