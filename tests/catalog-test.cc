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

#include <catalog.h>
#include "gtest/gtest.h"

TEST(CyclistCatalog, Constructor){
  CyclistCatalog c;
  EXPECT_EQ(0, c.Size());
}
TEST(CyclistCatalog, Load){
  CyclistCatalog catalog;
  EXPECT_EQ(0, catalog.Size());

  EXPECT_TRUE(catalog.Load("../data/cyclists.csv"));
  EXPECT_EQ(100, catalog.Size());
}
TEST(CyclistCatalog, LoadERROR){
  CyclistCatalog catalog;
  EXPECT_FALSE(catalog.Load("../data/cycxxxxx.csv"));
}
TEST(CyclistCatalog, Data){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  EXPECT_EQ("Joao Almeida",catalog.Data()[2].GetName());
  EXPECT_EQ("Emanuel Buchmann",catalog.Data()[99].GetName());
  EXPECT_EQ(1992,catalog.Data()[99].GetBirthYear());
}

TEST(CyclistCatalog, GetTeam){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  EXPECT_EQ("visma lease a bike",catalog.GetTeam("c0a1b106"));
  EXPECT_EQ("ineos grenadiers",catalog.GetTeam("c0a1b202"));
}

TEST(CyclistCatalog, GetByTeam){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  std::vector<Cyclist> v= catalog.GetByTeam("visma lease a bike");
  EXPECT_EQ(10, v.size());
  EXPECT_EQ("Jonas Vingegaard", v[0].GetName());
  EXPECT_EQ("Wout van Aert", v[1].GetName());
  EXPECT_EQ("Sepp Kuss", v[2].GetName());
  EXPECT_EQ("Christophe Laporte", v[3].GetName());
  EXPECT_EQ("Dylan van Baarle", v[4].GetName());
  EXPECT_EQ("Matteo Jorgenson", v[5].GetName());
  EXPECT_EQ("Tiesj Benoot", v[6].GetName());
  EXPECT_EQ("Jan Tratnik", v[7].GetName());
  EXPECT_EQ("Olav Kooij", v[8].GetName());
  EXPECT_EQ("Attila Valter", v[9].GetName());
  v= catalog.GetByTeam("uae team emirates");
  EXPECT_EQ("Tadej Pogacar", v[0].GetName());
  EXPECT_EQ("Adam Yates", v[1].GetName());
  EXPECT_EQ("Joao Almeida", v[2].GetName());
  EXPECT_EQ("Juan Ayuso", v[3].GetName());
  EXPECT_EQ("Brandon McNulty", v[4].GetName());
  EXPECT_EQ("Rafal Majka", v[5].GetName());
  EXPECT_EQ("Marc Soler", v[6].GetName());
  EXPECT_EQ("Tim Wellens", v[7].GetName());
  EXPECT_EQ("Felix Grossschartner", v[8].GetName());
  EXPECT_EQ("Pavel Sivakov", v[9].GetName());
}
TEST(CyclistCatalog, GetYoungest){
  CyclistCatalog catalog;
  catalog.Load("../data/cyclists.csv");
  std::vector<Cyclist> v= catalog.GetYoungest();
  EXPECT_EQ("Juan Ayuso", v[0].GetName());
}
TEST(DirectorCatalog, Constructor){
  DirectorCatalog c;
  EXPECT_EQ(0, c.Size());
}
TEST(DirectorCatalog, Load){
  DirectorCatalog catalog;
  EXPECT_EQ(0, catalog.Size());

  EXPECT_TRUE(catalog.Load("../data/directors.csv"));
  EXPECT_EQ(10, catalog.Size());
}
TEST(DirectorCatalog, LoadERROR){
  DirectorCatalog catalog;
  EXPECT_FALSE(catalog.Load("../data/cycxxxxx.csv"));
}
TEST(DirectorCatalog, Data){
  DirectorCatalog catalog;
  catalog.Load("../data/directors.csv");
  EXPECT_EQ("Rod Ellingworth",catalog.Data()[2].GetName());
  EXPECT_EQ("Enrico Poitschke",catalog.Data()[9].GetName());
  EXPECT_EQ(1969,catalog.Data()[9].GetBirthYear());
  EXPECT_EQ(2017,catalog.Data()[9].GetDirectorSince());
}


