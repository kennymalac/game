class Body {
  // vector<Cell *> currentCells;
  matrix3x3 localCoords;
  std::vector<Body *> getNearbyBodies() {
    std::vector<Body *> result;
    for (auto &c : currentCells)
      for (auto &b : c->getBodies())
        result.push_back(b);
    return result;}}

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
      c->update(ms);}
  virtual void draw() {
    for (auto &c : components)
      c->draw(ms);}}

class Query {
  // forward processing iterator composed of interactables
  // includes accessor methods and composable behavior
  // TODO: some sort of 'demand "paging"' feature for multithreading
    virtual void all() {
      //returns dat aggy (aggregate)
      
      }

    virtual void filterBy() {
      filterSet = parseParam(settings);
      
      }

    virtual void find() {
      
      }}

class EntityQuery : Query {
  // This query needs to be able to fuck with observables
  // Returns a result set with data on entities
  private:
    filterSet = vector<Entity *>;

  public:
  // Generic interface for finding entities within range
  // TODO: The Space should have a component that finds relevant AABBs OBBs
    Entity *findEntitiesWithinRadius(Space &space, Vector3 curPos,
                                     Vector3 range) {
      // use of a reduce clause to derive a filterset on instances
      this->filterSet = space->reduceCommonRadius(range);
      //return filterBy()
      }
  std::stack<GLFragment> *findFrags() {
    
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
// Notifies the Server
struct Scene {};
