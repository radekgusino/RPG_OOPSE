#ifndef monsters_hpp
#define monsters_hpp
#include "templates.hpp"

class monsters : public base {
public:
  string monster_name, monster_name2;
  void ch_stats();
  void ch_load();
  void ch_save();
  void ch_empty();
  void ch_disp();
 };
#endif
