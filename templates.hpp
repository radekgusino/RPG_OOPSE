#ifndef templates_hpp
#define templates_hpp

using namespace std;

class base
{
public:
  int str;
  int dex;
  int end;
  int inte;
  int chari;
  int exp;
  int lvl;
  int curr_eq;
  string chName;

  virtual void ch_stats()=0;
  virtual void ch_load()=0;
  virtual void ch_save()=0;
  virtual void ch_empty()=0;
  virtual void ch_disp()=0;
};

class profession
{
public:
  virtual void stat_bonus(){};
};

class Item
{
public:
    string itName;
    int id, itStr, itDex, itInt, itEnd;
    Item(string namen, int idn, int statn1, int statn2, int statn3, int statn4);
    Item(string namen);
    Item();
};
#endif
