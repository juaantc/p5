// persons-test.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good Idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "gtest/gtest.h"
#include "catalog.h"
#include "stage.h"

TEST(Stage, Constructor){
  Stage s1(3);
  EXPECT_EQ(3, s1.GetHard());
  Stage s2(0);
  EXPECT_EQ(1, s2.GetHard());
  Stage s3(7);
  EXPECT_EQ(5, s3.GetHard());
}

TEST(Stage, GetDelays1){
  Stage s1(3);
  EXPECT_EQ(0, s1.GetDelays().size());
}

TEST(Stage, GetDelays2){
  std::vector<Cyclist> cyclists = {
    {"Alice", 2001, "UAE", "C1"},
    {"Bob", 2002, "LDL", "C2"},
    {"Carol", 2003, "Visma", "C3"}
    };

    Stage s1(3);
    s1.Simulate(cyclists);
    bool f=false;
    // Comprobando que hay un ciclista con delay igual a 0
    for (const auto& [id, delay] : s1.GetDelays()) {
      if (delay==0) {f=true;}
    }
    EXPECT_TRUE(f);
}

TEST(Stage, GetDelays3){
  std::vector<Cyclist> cyclists = {
    {"Alice", 2001, "UAE", "C1"},
    {"Bob", 2002, "LDL", "C2"},
    {"Carol", 2003, "Visma", "C3"}
    };

    Stage s1(3);
    s1.Simulate(cyclists);
    bool f=false;
    // Comprobando que ningún delay es <0
    for (const auto& [id, delay] : s1.GetDelays()) {
      if (delay<0) {f=true;}
    }
    EXPECT_FALSE(f);
}

TEST(Stage, GetDelays4){
  std::vector<Cyclist> cyclists = {
    {"Alice", 2001, "UAE", "C1"},
    {"Bob", 2002, "LDL", "C2"},
    {"Carol", 2003, "Visma", "C3"}
    };

    Stage s1(3);
    s1.Simulate(cyclists);
    bool f=false;
    // Comprobando que ningún delay es > hard*400
    int max_delay=s1.GetHard()*400;
    for (const auto& [id, delay] : s1.GetDelays()) {
      if (delay>max_delay) {f=true;}
    }
    EXPECT_FALSE(f);
}

TEST(Stage, CatalogDelay1){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  Stage s1(5);
  s1.Simulate(catalog.Data());
  bool f=false;
    // Comprobando que hay un ciclista con delay igual a 0
    for (const auto& [id, delay] : s1.GetDelays()) {
      if (delay==0) {f=true;}
    }
    EXPECT_TRUE(f);
}

TEST(Stage, CatalogDelay2){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  Stage s1(5);
  s1.Simulate(catalog.Data());
  bool f=false;
    // Comprobando que ningún delay es <0
    for (const auto& [id, delay] : s1.GetDelays()) {
      if (delay<0) {f=true;}
    }
    EXPECT_FALSE(f);
  }
  
TEST(Stage, CatalogDelay3){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  Stage s1(5);
  s1.Simulate(catalog.Data());
  bool f=false;
  // Comprobando que ningún delay es > hard*400
  int max_delay=s1.GetHard()*400;
  for (const auto& [id, delay] : s1.GetDelays()) {
    if (delay>max_delay) {f=true;}
  }
  EXPECT_FALSE(f);
}

