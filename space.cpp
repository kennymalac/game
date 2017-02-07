#include <algorithm>
#include <bitset>
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>
//#include "alias"

//using;

class SpatialPartition {
  Texture textureMap;
  SugarDependencyGraph sugars;
  }

class Grid {
  vector<vector<Cell *>> cells;
  // TODO n-dimensional spatial partitioning (3x3, 4x4 being the main choices)
  Cell *getCell(int x, int y) { return cells[x][y]; }

  glm::vec2 Grid::getIndex(glm::vec2 i) {
    return glm::vec2{p.x / cellWidth, p.y / cellHeight};
  }
  serialize
}

struct Observer {
  void contemplate() {
    //Array<SubSpace *>{matrix4x4};
    for (Space &u : updatedSpaces) {
      Observer->queryUpdates();
      u->processUpdate();
    }
    //MessageFactory *dispatcherClause;
    // assert each update passes
    // assert each renderable renders
  }
}

  auto Space::runCompileChecks() {
    // interpret tests that need to pass for this space to render
  }

  auto Space::findRenderableUpdates() {
    //{ Array<Observer *>; }
  }

auto Space::observeUpdates() {
  //{ Array<Observer *>; }
}

class Body {
  //vector<Cell *> currentCells;
  matrix3x3 localCoords;
  vector<Body *> getNearbyBodies() {
    vector<Body *> result;
    for (auto &c : currentCells)
      for (auto &b : c->getBodies())
        result.push_back(b);
    return result;
  }
}

// polymorphic template for renderables
// template class Renderable<> {
//   Vector<Renderable*>
//     Vector<CoefficentMatrix>
// }

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

class EntityQuery
{
  // Returns a result set with data on entities
  private:
    querySet = vector<Entity*>;
    
  public:
    Entity* findEntitiesWithinRadius(Space& space, Vector3 curPos, Vector3 range) {
      this->querySet = space->
    }
  }

// // aggregate of entities
//   class Manager {
//   public:
//
// private:
// iterator
// std::vector<std::unique_ptr<Entity>> entities;
//   }

// Initializes Observers and query runners
struct Scene {

  auto render() {
    
  }

  TransitionMap tm;
};

// TODO abstract Scene management… use SceneManager to manage Transition states
// Notifies the Server on behalf of Scenes
// All TODOs for frustrum rendering are optimization suggestions
struct SceneManager {
  /*
    VFC algorithm: Improved frustum-object cull [Villi Miettinen]
    The below TODOs are optimization suggestions.
    TODO: Implement axis-aligned bounding boxes
    Implement Efficient View Frustum Culling [Daniel Skora, Josef Jelinek]
    Optimized View Frustum Culling Algorithms for Bounding Boxes [Ulf Assarsson, Tomas Moller]
  */
  glm::mtx4x4 getViewFrustrum(auto &camera, auto &plane) {
    EntityQuery q;
    // Perpendicular to the view frustrum
    glm::vec3 unitVector; // == 1,1,1

    glm::distance;

    auto projectedVector = glm::project<glm::vec3>();

    // basic intersection test
    // curPos in this case is the location of the camera
    EntityQuery->findEntitiesWithinRadius(
      &space
      camera->position,
      glm::distance<vec3>(&plane->origin, x));

    // TODO: Implement OBB hierarchies
    // plane coherency test
    // octant test
    // masking

    return glm::gtc::matrix_transform::frustum(
                                               left,
                                               right
                                               bottom,
                                               top,
                                               nearVal,
                                               farVal);}
  }
