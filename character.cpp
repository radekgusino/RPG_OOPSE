#include <iostream>
#include <stdlib.h>
#include <limits>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;
#include "character.hpp"
#include "inventory.hpp"

    string profes [5] = { "None" ,"Thief" , "Mage" , "Berserk" , "Warrior"};
    string prof;
    void character :: ch_empty()
    {
      chName = "Noone";
      str = 0;
      dex = 0;
      end = 0;
      inte = 0;
      chari = 0;
      exp = str + dex + end + inte + chari;
      lvl = exp/10;
      prof = profes[0];
    }
    void character :: ch_stats()
    {
      exp = str + dex + end + inte + chari;
      lvl = exp/10;
      bool a=true;
      int pick;
      while(a)
      {
      system("clear");
      cout<<"INPUT YOUR STATS\n";
      cout<<"1. Strength         ["<<str<<"] \n";
      cout<<"2. Dexterity        ["<<dex<<"] \n";
      cout<<"3. Endurance        ["<<end<<"] \n";
      cout<<"4. Inteligence      ["<<inte<<"]\n";
      cout<<"5. Charisma         ["<<chari<<"]\n";
      cout<<"6. Next\n";
      cin>>pick;
      switch(pick)
      {
        case 1: cout<<"Value of stat: ";cin>>str;break;
        case 2: cout<<"Value of stat: ";cin>>dex;break;
        case 3: cout<<"Value of stat: ";cin>>end;break;
        case 4: cout<<"Value of stat: ";cin>>inte;break;
        case 5: cout<<"Value of stat: ";cin>>chari;break;
        case 6: a = false;break;
      }
      exp = str + dex + end + inte + chari;
      lvl = exp/10;
      }

    }

    void character :: ch_disp()
    {
      cout<<" Name:       "<<chName<<endl;
      cout<<" Class:      "<<prof<<endl;
      cout<<" Level       ["<<lvl<<"] \n";
      cout<<" Expierience ["<<exp<<"] \n";
      cout<<" Strength    ["<<str<<"] \n";
      cout<<" Dexterity   ["<<dex<<"] \n";
      cout<<" Endurance   ["<<end<<"] \n";
      cout<<" Inteligence ["<<inte<<"]\n";
      cout<<" Charisma    ["<<chari<<"]\n";
    }

    void character :: ch_save()
    {
      cout<<"name your character:\n";
      cin>>chName;
      ofstream file(("/home/imirgrp/kuliga/oopsie/RPG/characters/" + chName + ".txt").c_str());
      file<<chName<<" "<<prof<<" "<<exp<<" "<<lvl<<" "<<str<<" "<<dex<<" "<<end<<" "<<inte<<" "<<chari<<endl;
    }

    void character :: ch_saveBttle()
    {

      ofstream file(("/home/imirgrp/kuliga/oopsie/RPG/characters/" + chName + ".txt").c_str());
      file<<chName<<" "<<prof<<" "<<exp<<" "<<lvl<<" "<<str<<" "<<dex<<" "<<end<<" "<<inte<<" "<<chari<<endl;
    /*  ofstream files(("/home/imirgrp/kuliga/oopsie/RPG/charHistory/" + chName + ".txt")).c_str());
      files<<result<<endl;*/
    }

    void character :: ch_load()
    {
      string char_name;
      cout<<"name of your character:\n";
      cin>>char_name;
      ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/characters/" + char_name + ".txt").c_str());
      while(file>>chName>>prof>>exp>>lvl>>str>>dex>>end>>inte>>chari);
      ifstream ffile(("/home/imirgrp/kuliga/oopsie/RPG/Eq/" + char_name + "Eq.txt").c_str());
      ffile>>curr_eq;
    }

    void character :: int_bonus()
    {
      inte += 10;
      prof = profes[2];
    }
    void character :: dex_bonus()
    {
      dex += 10;
      prof = profes[1];
    }
    void character :: end_bonus()
    {
      end += 10;
      prof = profes[4];
    }
    void character :: str_bonus()
    {
      str += 10;
      prof = profes[3];
    }

    void character :: eq_stats_equal(int eqq)
    {
      switch(eqq)
      {
        case 0: str -= 10;break;
        case 1: inte -= 10;break;
        case 2: dex -= 10;end -= 10;inte -= 10;str -= 10;break;
        case 3: end -= 10;break;
        case 4: dex -= 10;break;
      }

    }
    void character :: eq_stats(int eqq)
    {
      curr_eq = eqq;
      switch(eqq)
      {
        case 0: str += 10;break;
        case 1: inte += 10;break;
        case 2: dex += 10;end += 10;inte += 10;str += 10;break;
        case 3: end += 10;break;
        case 4: dex += 10;break;
      }

    }

    void character :: eq_name_disp(int eqq)
    {
      cout<<"Currently equiped: \n";
      switch(eqq)
      {
        case 0: cout<<" Grudge Sword+9"<<endl;
        cout<<"   Strength bonus: 10"<<endl;
        cout<<"   Inteligence bonus: 0"<<endl;
        cout<<"   Dexterity bonus: 0"<<endl;
        cout<<"   Endurance bonus: 0"<<endl;
        break;
        case 1: cout<<" EbonyBow"<<endl;
        cout<<"   Strength bonus: 0"<<endl;
        cout<<"   Inteligence bonus: 10"<<endl;
        cout<<"   Dexterity bonus: 0"<<endl;
        cout<<"   Endurance bonus: 0"<<endl;
        break;
        case 2: cout<<" Morellonomicon"<<endl;
        cout<<"   Strength bonus: 10"<<endl;
        cout<<"   Inteligence bonus: 10"<<endl;
        cout<<"   Dexterity bonus: 10"<<endl;
        cout<<"   Endurance bonus: 10"<<endl;
        break;
        case 3: cout<<" PoisonSword"<<endl;
        cout<<"   Strength bonus: 0"<<endl;
        cout<<"   Inteligence bonus: 0"<<endl;
        cout<<"   Dexterity bonus: 0"<<endl;
        cout<<"   Endurance bonus: 10"<<endl;
        break;
        case 4: cout<<" Thornmail"<<endl;
        cout<<"   Strength bonus: 0"<<endl;
        cout<<"   Inteligence bonus: 0"<<endl;
        cout<<"   Dexterity bonus: 10"<<endl;
        cout<<"   Endurance bonus: 0"<<endl;
        break;
      }
    }


    void thief :: stat_bonus(character & ch)
    {
      ch.dex_bonus();
    }

    void mage :: stat_bonus(character & ch)
    {
      ch.int_bonus();
    }

    void warrior :: stat_bonus(character & ch)
    {
      ch.end_bonus();
    }

    void berserker :: stat_bonus(character & ch)
    {
      ch.str_bonus();
    }



    Equipment::Equipment()
    {
        iName = "Empty";
        iStr = 0;
        iDex = 0;
        iInt = 0;
        iEnd = 0;
    }

    Equipment::Equipment(Equipment &eq, Item item)
    {
    iName = item.itName;
    iStr = item.itStr;
    iDex = item.itDex;
    iInt = item.itInt;
    iEnd = item.itEnd;
    }


  void Equipment::bonusStatsSave(character &ch){
    string FilePath = ch.chName+"BonusFromEq.txt";
    fstream outFile;
    outFile.open(FilePath.c_str(),fstream::out);
    outFile<<iStr<<"\n"<<iDex<<"\n"<<iInt<<"\n"<<iEnd<<"\n";
    outFile.close();
  }
  void Equipment::bonusStatsRead(character &ch){
    string FilePath = ch.chName + "BonusFromEq.txt";
    ifstream inFile (FilePath.c_str());
    inFile >> iStr >> iDex >> iInt >> iEnd;
  }
