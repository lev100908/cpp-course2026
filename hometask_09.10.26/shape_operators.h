#pragma once

#include <iostream>
#include "shape.h"

const double ERROR_RATE = 1e-6;

bool operator==(const Shape& lhs, const Shape& rhs);

bool operator^(const Shape& lhs, const Shape& rhs);

std::ostream& operator<<(std::ostream& stream, const Shape& rhs);