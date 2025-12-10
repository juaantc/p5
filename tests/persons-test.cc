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

#include "persons.h"
#include "gtest/gtest.h"

TEST(Person, Constructor) {
  Person p1;
  EXPECT_EQ("UNKNOWN", p1.GetName());
  EXPECT_EQ(-1, p1.GetBirthYear());

  Person p2("Pedro", 1990);
  EXPECT_EQ("Pedro", p2.GetName());
  EXPECT_EQ(1990, p2.GetBirthYear());
}
TEST(Person, Setters) {
  Person p1;
  p1.SetName("Ana");
  EXPECT_EQ("Ana", p1.GetName());
  p1.SetBirthYear(2001);
  EXPECT_EQ(2001, p1.GetBirthYear());

  p1.SetName("Carlos");
  p1.SetBirthYear(2002);
  EXPECT_EQ("Carlos", p1.GetName());
  EXPECT_EQ(2002, p1.GetBirthYear());
}
TEST(Cyclist, Constructor) {
  Cyclist c1;
  EXPECT_EQ("UNKNOWN", c1.GetName());
  EXPECT_EQ(-1, c1.GetBirthYear());
  EXPECT_EQ("UNKNOWN", c1.GetTeam());
  EXPECT_EQ("UNKNOWN", c1.GetCyclistId());

  Cyclist c2("Lola", 2005, "team1", "33XX");
  EXPECT_EQ("Lola", c2.GetName());
  EXPECT_EQ(2005, c2.GetBirthYear());
  EXPECT_EQ("team1", c2.GetTeam());
  EXPECT_EQ("33XX", c2.GetCyclistId());
}
TEST(Cyclist, Setters) {
  Cyclist c1;
  c1.SetName("Ana");
  EXPECT_EQ("Ana", c1.GetName());
  c1.SetBirthYear(2001);
  EXPECT_EQ(2001, c1.GetBirthYear());
  c1.SetTeam("team2");
  c1.SetCyclistId("ID66");
  EXPECT_EQ("team2", c1.GetTeam());
  EXPECT_EQ("ID66", c1.GetCyclistId());
  c1.SetTeam("team5");
  c1.SetCyclistId("ID55");
  EXPECT_EQ("team5", c1.GetTeam());
  EXPECT_EQ("ID55", c1.GetCyclistId());  
}
TEST(Director, Constructor) {
  Director d1;
  EXPECT_EQ("UNKNOWN", d1.GetName());
  EXPECT_EQ(-1, d1.GetBirthYear());
  EXPECT_EQ("UNKNOWN", d1.GetTeam());
  EXPECT_EQ("UNKNOWN", d1.GetUciLicenseId());

  Director d2("Tom", 2005, "team1", "33XX", 2000);
  EXPECT_EQ("Tom", d2.GetName());
  EXPECT_EQ(2005, d2.GetBirthYear());
  EXPECT_EQ("team1", d2.GetTeam());
  EXPECT_EQ("33XX", d2.GetUciLicenseId());
  EXPECT_EQ(2000, d2.GetDirectorSince());
}
TEST(Director, Setters) {
  Director d1;
  d1.SetName("Ana");
  EXPECT_EQ("Ana", d1.GetName());
  d1.SetBirthYear(2001);
  EXPECT_EQ(2001, d1.GetBirthYear());
  d1.SetTeam("team2");
  d1.SetUciLicenseId("ID66");
  EXPECT_EQ("team2", d1.GetTeam());
  EXPECT_EQ("ID66", d1.GetUciLicenseId());
  d1.SetTeam("team5");
  d1.SetUciLicenseId("ID55");
  EXPECT_EQ("team5", d1.GetTeam());
  EXPECT_EQ("ID55", d1.GetUciLicenseId());  
  d1.SetDirectorSince(2007);
  EXPECT_EQ(2007, d1.GetDirectorSince());  
}