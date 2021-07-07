#include <iostream>
#include <stdlib.h>
#include <limits>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include "monsters.hpp"
#include "templates.hpp"
#include "character.hpp"
#include "inventory.hpp"
#include "battleHistory.hpp"
using namespace std;

////////////////////////////////VARIABLES
  fstream file;

////////////////////////////////BOOLEANS
  bool i3 = true;
////////////////////////////////POINTERS
  int p1, p2, p3, p4, p5;
  int a, b, c, d, e;
////////////////////////////////FUNCTIONS
  void char_creator();
  void monster_creator();
  void char_loader();
  void monster_loader();
  void battle_simulator();
  void inv_eq();
  void inv_disp();
  void inv_search();
  string re_search(string item, invManagment & inv, int zz);
//  void hist_save(TsingleList sl,string imie,string imiep,string imiep2,string res);
  int get_int();
////////////////////////////////CLASS TEMPLATE
  template <class T>
  class battle
  {
  public:
    T chlvl, mlvl, chexp, mexp , bttleRes;
    battle(T a, T b, T c, T d)
    {
      chlvl = a;
      mlvl = b;
      chexp = c;
      mexp = d;
    }
    T fight();
  };

  template <class T>
  T battle<T> :: fight()
  {
    bttleRes = 3;
    if (chlvl >= mlvl)
    {
      cout<<" Your hero won!"<<endl;
      cout<<mexp<<" exp gained!"<<endl<<endl;
      chexp = chexp + mexp;
      bttleRes = 1;
    }
    else
    {
      cout<<" Your hero lost!"<<endl<<endl;
      cout<<"Exp penality: "<<mexp<<endl<<endl;
      chexp = chexp - mexp;
      bttleRes = 0;
      if (chexp<0)
      {
        chexp = 0;
      }
    }
  }
////////////////////////////////MAIN LOOP
int main()
{
  srand((unsigned) time(0));
  int pick;
  do
    {
    system("clear");
    cout<<"***********************"<<endl;
    cout<<"1. Create new character"<<endl;
    cout<<"2. Load character"<<endl;
    cout<<"3. Generate monsters"<<endl;
    cout<<"4. Load monsters"<<endl;
    cout<<"5. Battle simulator"<<endl;
    cout<<"6. Display inventory"<<endl;
    cout<<"7. Equip Item"<<endl;
    cout<<"8. Search for Item"<<endl;
    cout<<"123. Exit"<<endl;
    cout<<"***********************"<<endl;
    pick = get_int();
    switch(pick)
      {
        case 1: system("clear");char_creator();break;
        case 2: system("clear");char_loader();break;
        case 3: system("clear");monster_creator();break;
        case 4: system("clear");monster_loader();break;
        case 5: system("clear");battle_simulator();break;
        case 6: system("clear");inv_disp();break;
        case 7: system("clear");inv_eq();break;
        case 8: system("clear");inv_search();break;
        case 123: system("clear");i3 = false;break;
        default: cout<<"Invalid input"<<endl;break;
      }
    }
  while(i3);
}

void char_creator()
{

  bool bool1 = true;
  bool bool2 = true;
  int mod;
  mage m; thief t; berserker b; warrior w;
  while(bool1)
    {
    character player;
    player.ch_empty();
    player.ch_stats();
    system("clear");
    cout<<"PICK CLASS OF YOUR HERO:\n";
    cout<<"1. Thief\n";
    cout<<"2. Berserk\n";
    cout<<"3. Warrior\n";
    cout<<"4. Mage\n";

    while(bool2)
        {
        mod = get_int();
        switch(mod)
          {
            case 1: bool2 = false;t.stat_bonus(player);break;
            case 2: bool2 = false;b.stat_bonus(player);break;
            case 3: bool2 = false;w.stat_bonus(player);break;
            case 4: bool2 = false;m.stat_bonus(player);break;
            default: cout<<"Invalid input\n";break;
          }
        }

          cout<<"Do you want to player and save your hero?\n";
          cout<<"1. Yes\n";
          cout<<"2. No\n";
          mod = get_int();
          switch(mod)
          {
            case 1: bool1 = false;player.ch_save();break;
            case 2: bool2 = true;break;
            default: cout<<"Invalid input";break;
          }
  }
}

void char_loader()
{
    invManagment inv;
    TsingleList sl;
    int pick_l = 0;
    while(pick_l != 1){
    character player;
    player.ch_load();
    system("clear");
    player.ch_disp();
    player.eq_name_disp(inv.eq_list_l(player.chName));
    cout<<endl;
    cout<<"Latest battles: "<<endl;
    sl.hist_load(player.chName);
    cout<<"1. Back to main menu\n";
    cin>>pick_l;
  }
}

void monster_creator()
{
  int i; int iter;
  cout<<"number of monsters generated: ";
  iter = get_int();
  monsters monsters[iter];
  fstream file;
  int f = rand() % 9 + 0;
  for(i=0;i<iter;i++)
  {
    monsters[i].ch_stats();
    monsters[i].ch_save();
  }
}

void monster_loader()
{
  int pick_l = 0;
  while(pick_l != 1){
    monsters monster;
    monster.ch_load();
    monster.ch_disp();
    cout<<"1. Back to main menu\n";
    cin>>pick_l;
  }
}

void battle_simulator(){
  bool bool1 = true;
  int t;
  TsingleList sl;
  invManagment inv;
  character player;
  player.ch_load();
  monsters monster;
  monster.ch_load();
  battle <int> pve(player.lvl,monster.lvl,player.exp,monster.exp);
  pve.fight();
  player.exp = pve.chexp;
  player.lvl = player.exp/10;
  player.ch_saveBttle();
  inv.load_item();
  inv.load_inv(player.chName);
  if (pve.bttleRes == 1)
  {
    int tmp = rand() % 100 + 1;
    if(tmp<5)
    {
      cout<<"You found GrudgeSword+9!"<<endl;
      inv.add_item("GrudgeSword+9",player.chName);
    }
    else if (tmp>=5&&tmp<20)
    {
      cout<<"You found EbonyBow!"<<endl;
      inv.add_item("EbonyBow",player.chName);
    }
    else if (tmp>=20&&tmp<30)
    {
      cout<<"You found Morellonomicon!"<<endl;
      inv.add_item("Morellonomicon",player.chName);
    }
    else if (tmp>=30&&tmp<50)
    {
      cout<<"You found PoisonSword!"<<endl;
      inv.add_item("PoisonSword",player.chName);
    }
    else if (tmp>=50&&tmp<65)
    {
      cout<<"You found Thornmail!"<<endl;
      inv.add_item("Thornmail",player.chName);
    }
    else
    {
      cout<<"You found nothing"<<endl;
    }

    cout<<"1. Back to main menu"<<endl;
    t = get_int();
    sl.hist_save(player.chName,monster.monster_name,monster.monster_name2,"won");
  }
  else if (pve.bttleRes == 0)
  {
    sl.hist_save(player.chName,monster.monster_name,monster.monster_name2,"lost");
  }
  else
  {
    cout<<"???";
  }
}

void inv_disp()
{
  int pick_l;
  character player;
  invManagment inv;
  player.ch_load();
  inv.load_item();
  inv.load_inv(player.chName);
  inv.print(player.chName);
  cout<<"1. Back to main menu\n";
  cin>>pick_l;
}

void inv_eq()
{
  int pick_l;
  character player;
  invManagment inv;
  player.ch_load();
  player.eq_stats_equal(inv.eq_list_l(player.chName));
  inv.load_item();
  inv.load_inv(player.chName);
  cout<<"which item would you like to equip: "<<endl;
  inv.print_eq(player.chName);
  cin>>pick_l;
  if(inv.iQuant[pick_l]!=0)
  {
      player.eq_stats(pick_l);
      inv.eq_list_s(player.chName,pick_l);
      player.ch_saveBttle();
  }
  else
  {
    cout<<"pick correct item!\n";
  }



  cout<<"1. Back to main menu\n";
  cin>>pick_l;
}

void inv_search()
{
  int pick_l;
  string item;
  character player;
  invManagment inv;
  player.ch_load();
  player.eq_stats_equal(inv.eq_list_l(player.chName));
  inv.load_item();
  inv.load_inv(player.chName);
  cout<<"which item would you like to find? \n";
  cin>>item;
  cout<<re_search(item,inv,0)<<endl;
  cout<<"1. Back to main menu."<<endl;
  get_int();
}

string re_search(string item, invManagment & inv, int zz)
{
  if (zz>=5)
  {
    return "Character does not possess such an item.";
  }
  if (item!=inv.iName[zz])
  {
    {
      return re_search(item, inv, zz+1);
    }
  }
  else if(inv.iQuant[zz]!=0)
  {
    cout<<" "<<inv.iName[zz]<<" ("<<inv.iQuant[zz]<<")"<<endl;
    cout<<"   Strength bonus: "<<inv.a[zz]<<endl;
    cout<<"   Inteligence bonus: "<<inv.b[zz]<<endl;
    cout<<"   Dexterity bonus: "<<inv.c[zz]<<endl;
    cout<<"   Endurance bonus: "<<inv.d[zz]<<endl;
    return "    ";
  }
  else
  {
      return "Character does not possess such an item.";
  }
}

int get_int()
{
int x = 0;
while(!(cin >> x)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input.  Try again: ";
  }
  return x;
}
