#include "project11/utils.h"

std::ostream& operator<< (std::ostream &out, const project11::LatLongDegrees &p)
{
  out << std::setprecision (10) << "lat (deg): " << p.latitude() << ", lon (deg): " << p.longitude() << ", alt (m): " << p.altitude();
  return out;
}

std::ostream& operator<< (std::ostream &out, const project11::ECEF &p)
{
  out << "ECEF xyz(m): " << p.x() << ", " << p.y() << ", " << p.z();
  return out;
}

std::ostream& operator<< (std::ostream &out, const project11::AngleDegrees &a)
{
  out << a.value() << " degrees (" << project11::AngleRadians(a).value() << " radians)";
  return out;
}

std::ostream& operator<< (std::ostream &out, const project11::AngleRadians &a)
{
  out << a.value() << " radians (" << project11::AngleDegrees(a).value() << " degrees)";
  return out;
}
