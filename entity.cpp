#include <vector>

// aggregate of components
class Entity {
private:
  std::vector<std::unique_ptr<Component>> components;

public:
  virtual void update(float ms) {
    for (auto &c : components)
      c->update(ms);
  }
  virtual void draw() {
    for (auto &c : components)
      c->update(ms);
  }
  virtual ~Entity() {}
}
