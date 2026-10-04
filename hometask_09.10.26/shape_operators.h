#pragma once

#include <iostream>
#include "shape.h"

bool operator==(const Shape& lhs, const Shape& rhs);

bool operator^(const Shape& lhs, const Shape& rhs);

std::ostream operator<<(std::ostream& stream, Shape& rhs);