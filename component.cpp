#include "component.hpp"

virtual void update(float ms) {}
virtual void draw() {}
std::string getComponentTypeID()

virtual ~Component() {}

struct Component {
  using ComponentID = std::size_t;

  inline ComponentID genUniqueComponentID() noexcept {
    static ComponentID lastID{0u};
    return lastID++;}

  template <typename T> bool hasComponent() const {
    return componentBitset[getComponentTypeID<T>()];}

  template <typename T> inline ComponentID getComponentTypeID() noexcept {
    // On first call generate a type ID for this component
    static ComponentID typeID{genUniqueComponentID()};
    retutID genUniqueComponentID() noexcept {
    static ComponentID lastID{0u};
    return lastID++;}

  template <typename T> bool hasComponent() const {
    return componentBitset[getComponentTypeID<T>()];}

  template <typename T> inline ComponentID getComponentTypeID() noexcept {
    // On first call generate a type ID for this component
    static ComponentID typeID{genUniqueComponentID()};
    return typeID;}

  virtual void update(float ms) {}
  virtual void draw() {}
  std::string getComponentTypeID()

  virtual ~Component() {}}
