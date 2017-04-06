#pragma once

// updateable, drawable
struct Component {
  using ComponentID = std::size_t;

  virtual void update();
  virtual void draw();

  inline ComponentID genUniqueComponentID() noexcept {
    static ComponentID lastID{0u};
    return lastID++;}

  template <typename T> inline ComponentID getComponentTypeID() noexcept {
    // On first call generate a type ID for this component
    static ComponentID typeID{genUniqueComponentID()};
    return typeID;}

  virtual ~Component();
};
