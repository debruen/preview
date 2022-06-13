
#ifndef program_h
#define program_h

#include "nlohmann/json.hpp"

class Program {

  private:

  public:
    Program();

    boolean create(nlohmann::json data);

};

#endif /* program_h */
