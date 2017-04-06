#pragma once
#include <glm/gtx/transform.hpp>
//#include 

struct Scene;
struct TransitionMap;
class Space {
public:
  void flushVBOs();

private:
  //Array<Manager *> managers;
  //Array<Observer *> observers;

protected:
  auto runCompileChecks();
  auto processShaders();
  auto observeUpdates();

  virtual ~Space() {
    // vector<Observer*> observables;
    // for (auto &obj : observerables)
    //   obj->contemplate();
  }};

struct Scene {
  
};

class SceneManager {
  const glm::vec3 unitVector{1,1,1};

  Scene getScene(int index);
  void reset(tm);
  TransitionMap tm;};
