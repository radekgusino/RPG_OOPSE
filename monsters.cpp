#include <iostream>
#include <stdlib.h>
#include <limits>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;
#include "monsters.hpp"

  string monsters_names[10] = { "Giant" , "Undead", "Ghost", "Skeleton",
   "Orc", "Vampire", "Witch", "Gnoll", "Demon", "Genie" };
  string monsters_names_2[7] = { "Hungry" , "Angry", "Weak", "Cursed",
    "Evil","Strong","Deadly"};

  void monsters :: ch_stats()
  {
    str = rand() % 10 + 1;
    dex = rand() % 10 + 1;
    end = rand() % 10 + 1;
    inte = rand() % 10 + 1;
    chari = rand() % 10 + 1;
    exp = str + dex + end + inte + chari;
    lvl = exp/10;
  }
  void monsters :: ch_load()
  {
    string char_name;
    cout<<"file with your monsters:\n";
    cin>>char_name;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/monsters/" + char_name + ".txt").c_str());
    while(file>>monster_name>>monster_name2>>exp>>lvl>>str>>dex>>end>>inte>>chari);
  }
  void monsters :: ch_save()
  {
    fstream file;
    string char_name;
    cout<<"name of your character:\n";
    cin>>char_name;
    char_name = "/home/imirgrp/kuliga/oopsie/RPG/monsters/" + char_name + ".txt";
    file.open(char_name.c_str(), ios::in | ios::app );
    int tmp = rand() % 9 + 0;
    int tmp2 = rand() % 6 + 0;
    file<<monsters_names_2[tmp2]<<" "<<monsters_names[tmp]<<" "<<exp<<" "<<lvl<<" "<<str<<" "<<dex<<" "<<end<<" "<<inte<<" "<<chari<<endl;
  }
  void monsters :: ch_empty()
  {

  }
  void monsters :: ch_disp()
  {
    cout<<monster_name<<" "<<monster_name2<<endl;
    cout<<" Level       ["<<lvl<<"] \n";
    cout<<" Expierience ["<<exp<<"] \n";
    cout<<" Strength    ["<<str<<"] \n";
    cout<<" Dexterity   ["<<dex<<"] \n";
    cout<<" Endurance   ["<<end<<"] \n";
    cout<<" Inteligence ["<<inte<<"]\n";
    cout<<" Charisma    ["<<chari<<"]\n";
  }
