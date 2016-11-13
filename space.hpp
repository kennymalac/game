#pragma once
#include <glm/gtx/transform.hpp>
//#include 

//struct Scene;
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
  }
};
