#ifndef battleHistory_hpp
#define battkeHistory_hpp

using namespace std;

struct lst_el{
  lst_el * next;
  int key;
  string name;
  string battleResult;
  string mname1;
  string mname2;
};


class TsingleList{
lst_el * head, * tail;
int cnt;

public:
TsingleList();
~TsingleList();
unsigned size();
lst_el * push_head(lst_el * el);
lst_el * push_tail(lst_el * el);
lst_el * rmHead();
lst_el * rmTail();
lst_el * insert(lst_el * el1, lst_el * el2);
lst_el * erase(lst_el * el);
lst_el * index(int n);
void showKeys();
void showNames();
void showElements(string ss);
void saveElements(string ss);
void loadElements(string ss);
void hist_load(string ss);
void hist_save(string imie,string imiep,string imiep2,string res);
};

#endif
