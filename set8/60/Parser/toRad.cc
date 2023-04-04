#include "parser.ih"

double Parser::toRad(double angle) const
{
  switch (d_angleMode)
  {
    case RAD:
      return angle;
    case DEG:
      return angle / 180 * numbers::pi;
    case GRAD:
      return angle / 200 * numbers::pi;
  }

  throw std::runtime_error("Invalid angle mode");
}