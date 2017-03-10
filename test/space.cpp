#include "include/catch.hpp"

#include <space>

GIVEN("a Space is being constructed") {
  WHEN("") {
    THEN("") {
      
    }
  }
}

GIVEN("an Observer is being constructed") {
  WHEN("") {
    THEN("") {
      
    }
  }
}

GIVEN("an Observer") {
  WHEN("it contemplates") {
    THEN("it finds updates to process") {
      
    }
    THEN("it processes those updates") {
      
    }
  }

  WHEN("a scene is testing it for validity") {
    // space.runCompileChecks();
    THEN("strange behavior leads to runtime error") {
      // TODO
    }
  }
}

GIVEN("a constructed Space is being observed") {
  WHEN("Entities exist within the Space") {
    Space s;
    Component testComp;
    auto testCompType testComp.getComponentTypeID();
    std::multiset<Entity>{Entity{std::vector<Component>{testComp}}, Entity{}, Entity{}};

    THEN("they may be observed by type") {
      //
      auto entityQ = observer.(&s, );
      assert typeof(entityVec) == EntityQuery;
      assert entityQ.all().length == 1;
    }
    THEN("they may be queried") {
      //
    }
    THEN("they may be updated") {
      //
    }
  }

  WHEN("no Entities exist within the Space") {
    THEN("there is nothing to be observed") {
      //
    }
    THEN("there is nothing to be queried") {
      //
    }
    THEN("there is nothing to be updated") {
      //
    }
  }
}

