#include <vector>
#include <map>

// aggregate of components
class Entity {
private:
  std::vector<std::unique_ptr<Component>> components;
  std::ordered_map<ComponentID, Component> components;

public:
  virtual void update(auto time) {
    for (auto &c : components)
      c->update(time);}

  template <typename T> inline bool hasComponent() const {
    return components[getComponentTypeID<T>()];}

  virtual ~Entity() {}};

class DrawableEntity : Entity {
  inline virtual void draw() {
    for (auto &c : components)
      c->draw(time);}};
