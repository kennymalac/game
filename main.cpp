#include "engine.hpp"

int main(void) {
  // Initiate the engine
  Engine engine;
  // Create a running game instance using the current engine
  //Game game{&engine};
  // Run the game's default scene
  engine.initialize();
  //
  return 0;
}
