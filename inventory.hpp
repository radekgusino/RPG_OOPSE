#ifndef inventory_hpp
#define inventory_hpp
#include "character.hpp"
using namespace std;


struct node
{
  string name;
  int id,bonSTR,bonDEX,bonINT,bonEND, quantity;
  struct node* next;
  struct node* prev;
};


class invManagment
{
  node *head,*tail;
public:
  string iName[5];
  int iQuant[5];
  int a[11],b[11],c[11],d[11];
  void create_list();
  void print(string chname);
  void print_eq(string chname);
  void add_item(string iname,string chname);
  void load_item();
  void load_inv(string chname);
  int eq_list_l(string chname);
  void eq_list_s(string chname,int it);


  friend class character;
};

#endif
