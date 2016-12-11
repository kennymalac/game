#include "component.hpp"

template <typename T> bool Component::hasComponent() const {
  return componentBitset[getComponentTypeID<T>()];}
