#include <catalog.h>
#include "gtest/gtest.h"
#include <iostream>
#include "persons.h"
#include "catalog.h"
#include "gclist.h"
#include "stage.h"

TEST(CyclistCatalog, Add){
    Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
    Cyclist c2{"Xabier Mikel Azparren", 1999, "Q36.5 Pro Cycling Team", "d1a1b002"};
    Cyclist c3{"Enekoitz Azparren", 2002, "Q36.5 Pro Cycling Team", "d1a1b003"};
    Cyclist c4{"Marcel Camprubí", 2001, "Q36.5 Pro Cycling Team", "d1a1b004"};
    Cyclist c5{"Damien Howson", 1992, "Q36.5 Pro Cycling Team", "d1a1b005"};
    Cyclist c6{"José Mendes", 1985, "Red Bull-BORA-hansgrohe", "d1a1b006"};
    Cyclist c7{"Giulio Pellizzari", 2003, "Red Bull-BORA-hansgrohe", "d1a1b007"};
    CyclistCatalog cc;
    cc.Add(c1);
    cc.Add(c2);
    cc.Add(c3);
    cc.Add(c4);
    cc.Add(c7);
    cc.Add(c6);
    cc.Add(c7);
    EXPECT_EQ(cc.Size(), 7);
}
TEST(GCList, Constructor){
    CyclistCatalog cc;
    EXPECT_TRUE(cc.Load("../data/cyclists.csv"));
    EXPECT_EQ(100, cc.Size());    
    GCList gc(cc);
    EXPECT_EQ(100, gc.Size());  
}

TEST(GCList, ApplyStage){
    CyclistCatalog cc;
    EXPECT_TRUE(cc.Load("../data/cyclists.csv"));
    EXPECT_EQ(100, cc.Size());    
    GCList gc(cc);
    EXPECT_EQ(100, gc.Size());  
    Stage s1(1);
    s1.Simulate(cc.Data());
    gc.ApplyStage(s1);   
    int anterior=0;
    bool flag = true;
    for (auto [k,v]: gc.GetClassification()){
        if (anterior>v) {flag=false;break;}
        anterior=v;
    }
    EXPECT_TRUE(flag);
    Stage s2(2);
    s2.Simulate(cc.Data());
    gc.ApplyStage(s2);   
    anterior=0;
    flag = true;
    for (auto [k,v]: gc.GetClassification()){
        if (anterior>v) {flag=false;break;}
        anterior=v;
    }
    EXPECT_TRUE(flag);
}
TEST(GCList, GetCassification){
    CyclistCatalog cc;
    EXPECT_TRUE(cc.Load("../data/cyclists.csv"));
    EXPECT_EQ(100, cc.Size());    
    GCList gc(cc);
    EXPECT_EQ(100, gc.Size());  
    Stage s1(1);
    s1.Simulate(cc.Data());
    gc.ApplyStage(s1);   
    Stage s2(2);
    s2.Simulate(cc.Data());
    gc.ApplyStage(s2);   
    std::cout<< gc.GetClassification(5);
}