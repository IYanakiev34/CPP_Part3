#include "parser.ih"

double Parser::toCurrentAngleUnit(double radAngle) const
{
  switch (d_angleMode)
  {
    case RAD:
      return radAngle;
    case DEG:
      return radAngle / numbers::pi * 180;
    case GRAD:
      return radAngle / numbers::pi * 200;
  }

  throw std::runtime_error("Invalid angle mode");
}
