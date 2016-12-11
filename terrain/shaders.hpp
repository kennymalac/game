
// Terrain specification should be required
// TODO find definable "sugars"
/*
Types of sugar:
- mineral ores
- crops
- plants and herbs
- wheat, corn, etc.
- cotton, hemp, etc.
- barley and hops
- tobacco
- animal migrations
 */
struct Sugar {
  //cluster
  //spread
  //reduce
  //distribute
  int amount;
  //size;
  std::size_t type;
  }

union SugarTypeClass {
  /*
  Ore
  Harvestable (follows seasons)
  Population (animals and humans)
  */
}

// The underlying semantic difference between a Sugar and a Resource is that
// a resource is more feature-complete and features dynamic behavior
// A resource identifier has a reference to a sugar to modify those values as resource depletion occurs
//  struct Resource {}

// Usage:
// 
// 
// 


// TODO: Union of valid terrains (std::variant)

/*
desert - dry, arid, flat, low height
tundra -
hills - rolling, low to medium height
plains hills
grassland hills
extreme hills
grassland - low to medium-high height
plains - low to high height
sandy shore - very low
rocky shore - very low to low
cliff - high
 */

//HUMIDITY_SPEC
/* ARID (.11-.22+-4)
  + more likely to be mineral dense
  - very little to no rain and no fresh water besides OASIS */
/* DRY (.33+-5) + more likely to be mineral dense
   - */
/* WETTISH (~.55-.65)
   + very good for farming, rain */
/* DAMP (~.60)
   + extra rain */
/* IRRIGUOUS (~.59-.75)
   + flooding bonus
   + very good for farming
   - not easily defendable until masonry and later on iron age (Fortress) */
/* WET (.75+-.9)
   + shoreline trade bonus if OCEAN
   + rain may or may not occur. likely to occur with DAMP surrounding
   + guarantees river within a certain amount of partitions of distance
   - not suitable for farming except livestock
   - less likely mineral dense
*/

// WATER SPEC
/* RIVER
   + river trade bonus
   + rain may or may not occur. likely to occur with DAMP surrounding
   + requires bridge construction to cross by most units
   + chalk resource and fish resources with fishing wharves
*/
/* OASIS
   + large trade bonus with desert tiles (high foot traffic)
   + population
   + health
   + nearby incense or ivory chance
 */
/* COAST
   + trade bonus
   + fish chance
   - flood chance
   , likely to border OCEAN
*/
/* OCEAN
   + fish, crabs, whale resource chance
   - difficult to navigate
   - no improvement or construction occurs except Ship Missions
*/

// ELEVATION_SPEC
// In order from high (100000 or rational integer ceiling) to low (-10000 or negative space)
// LOW
// HIGH
// SKY ()
// MOUNTAIN ()
// HIGHLAND ()
// PLATEAU ()
// MESA ()
// LOWLAND ()
// OCEAN ()
// UNDERGROUND ()
// TerrainTypeClass_ELEVATION_SPEC
// GRASS_LOWLAND

/*
  this needs to be based off of some sort of cyllandrical grid
  minimumWidth (x-coordinate)
  minimumDepth (y-coordinate)
  minimumHeight (z-coordinate)
  maximumWidth (x-coordinate)
  maximumDepth (y-coordinate)
  maximumHeight (z-coordinate)
*/

/*
  TODO have preview images that show low resolution maps
  roughness (default .4)
  erosion (default .35)
  flatness (default: .7)
  water (default: ~.65)
  displacement
*/

// Usage:
// h = Heightmap()
// h.seed()
// h.generateInitialValues(biases)


class TerrainShader : ShaderProgram {
  // mixin behavior to include projection matrices
  // projection
  // heightmap
  // bump mapping
  // spectral imaging of terrain layers

  ~TerrainShader (Grid& g);

  RenderableMesh mesh;};


