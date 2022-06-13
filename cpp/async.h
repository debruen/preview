#ifndef async_h
#define async_h

#include <napi.h>

#include <chrono>
#include <thread>
#include <iomanip>

#include "src/program.h"

// -- -- -- -- -- data
class AsyncCreate : public Napi::AsyncWorker {

  private:
    Program& _program;
    nlohmann::json _data;
    boolean _created = false;

  public:
    AsyncCreate(Napi::Function& callback, Program& program, nlohmann::json data)
      : AsyncWorker(callback), _program(program), _data(data) {
    };
    virtual ~AsyncCreate() {};

    void Execute() {
      _created = _program.create(_data);
    };

    void OnOK() {
      Callback().Call({Env().Null(), Napi::Boolean::New(Env(), _created)});
    };
};

#endif
