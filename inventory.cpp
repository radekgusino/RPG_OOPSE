#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "inventory.hpp"
#include "character.hpp"
using namespace std;




  int invManagment :: eq_list_l(string chname)
  {
    int itt;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/charEq/" + chname + "Eq.txt").c_str());
    file>>itt;
    return itt;
  }

  void invManagment :: eq_list_s(string chname,int it )
  {
    string filepath = "/home/imirgrp/kuliga/oopsie/RPG/charEq/" + chname + "Eq.txt";
    fstream ofile;
    ofile.open(filepath.c_str(),fstream::out);
    ofile<<it;
    ofile.close();
  }

  void invManagment :: print_eq(string chname)
  {
    int zz = 0;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/charInventory/" + chname + "Inventory.txt").c_str());
    while(file>>iName[zz]>>iQuant[zz])
    {
      if (iQuant[zz]!=0)
      {
        cout<<zz<<") "<<iName[zz]<<" "<<iQuant[zz]<<endl;
      }
      zz++;
    }

    }

  void invManagment :: print(string chname)
  {
    int zz = 0;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/charInventory/" + chname + "Inventory.txt").c_str());
      cout<<chname<< "'s INVENTORY: "<<endl;
    while(file>>iName[zz]>>iQuant[zz])
    {
      if (iQuant[zz]!=0)
      {
        cout<<" "<<iName[zz]<<" ("<<iQuant[zz]<<")"<<endl;
        cout<<"   Strength bonus: "<<a[zz]<<endl;
        cout<<"   Inteligence bonus: "<<b[zz]<<endl;
        cout<<"   Dexterity bonus: "<<c[zz]<<endl;
        cout<<"   Endurance bonus: "<<d[zz]<<endl;
      }
      zz++;
    }

    }

  void invManagment :: add_item(string iname,string chname)
  {
    int zz = 0;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/charInventory/" + chname + "Inventory.txt").c_str());
    while(file>>iName[zz]>>iQuant[zz])
    {
      if (iName[zz]==iname)
      {
        iQuant[zz]+=1;
      }
      zz++;
    }
    string filepath = "/home/imirgrp/kuliga/oopsie/RPG/charInventory/" + chname + "Inventory.txt";
    fstream ofile;
    ofile.open(filepath.c_str(),fstream::out);
    ofile<<iName[0]<<" "<<iQuant[0]<<endl<<iName[1]<<" "<<iQuant[1]<<endl<<iName[2]<<" "<<iQuant[2]<<endl<<iName[3]<<" "<<iQuant[3]<<endl<<iName[4]<<" "<<iQuant[4];
    ofile.close();
  }

  void invManagment :: load_item()
  {
    int z=0;
    string i[11];
    node*temp = head;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/items.txt"));
    while(file>>i[z]>>a[z]>>b[z]>>c[z]>>d[z])
    {
      z++;
    }
}

  void invManagment :: load_inv(string chname)
  {
    int zz = 0;
    ifstream file(("/home/imirgrp/kuliga/oopsie/RPG/charInventory/" + chname + "Inventory.txt").c_str());
    while(file>>iName[zz]>>iQuant[zz])
    {
      zz++;
    }

    }
  /*
    node*temp = head;

    {
      cout<<tmps<<" "<<tmp<<endl;
      temp->name = tmps;
      temp->quantity = tmp;
      temp = temp->next;
  /*  temp->name = tmps[i];
    temp->quantity = tmp[i];
    cout<<"blagam xd";
    temp = temp->next;
    cout<<temp->name<<endl;
    i++;
    */
