#ifndef character_hpp
#define character_hpp
#include "templates.hpp"
#include "inventory.hpp"


class character : public base
{
  public:
    void ch_empty();
    void ch_stats();
    void ch_disp();
    void ch_save();
    void ch_saveBttle();
    void ch_load();
    void int_bonus();
    void dex_bonus();
    void end_bonus();
    void str_bonus();
    void eq_stats(int eqq);
    void eq_stats_equal(int eqq);
    void eq_name_disp(int eqq);
    friend class mage;
    friend class warrior;
    friend class thief;
    friend class berserker;
    friend class invManagment;
  };


class thief : public profession
{
public:
  void stat_bonus(character & ch);
};

class mage : public profession
{
public:
  void stat_bonus(character & ch);
};

class warrior : public profession
{
public:
  void stat_bonus(character & ch);
};

class berserker : public profession
{
public:
  void stat_bonus(character & ch);
};

class Equipment
{
public:
    string iName;
    int id, place, iStr, iDex, iInt, iEnd;
    Equipment();
    Equipment(Equipment &eq, Item item);
    void bonusStatsSave(character &ch);
    void bonusStatsRead(character &ch);
};
#endif
