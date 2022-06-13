
#include "async.h"

// init Program class
Program program;

// -- -- -- -- -- data
Napi::Value create(const Napi::CallbackInfo& info) {
  std::string string = info[0].As<Napi::String>().Utf8Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  nlohmann::json json = nlohmann::json::parse(string);

  AsyncCreate* _create = new AsyncCreate(callback, program, json);
  _create->Queue();

  std::string msg = "program: preview generation";
  return Napi::String::New(info.Env(),msg.c_str());
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {

  exports["create"] = Napi::Function::New(env, create, std::string("create"));

  return exports;
}

NODE_API_MODULE(addon, Init)
