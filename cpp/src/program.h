
#ifndef program_h
#define program_h

#include "nlohmann/json.hpp"

class Program {

  private:

  public:
    Program();

    bool create(nlohmann::json data);

};

#endif /* program_h */
