#include <node.h>
#include <v8.h>

#include <iostream>

using namespace v8;

extern "C" {
  void init(Handle<Object> target);
}

uv_check_t *check_handle_;

void
UV_CheckState(uv_check_t* handle, int status) {
  assert(status == 0);
  assert(handle == check_handle_);

  std::cout << "running check" << std::endl;
}

Handle<Value> RegisterCheck(const Arguments& args) {
  HandleScope scope;

  std::cout << "registering check" << std::endl;
  check_handle_ = new uv_check_t;
  uv_check_init(uv_default_loop(), check_handle_);
  uv_check_start(check_handle_, UV_CheckState);

  return scope.Close(Undefined());
}

Handle<Value> UnregisterCheck(const Arguments& args) {
  HandleScope scope;

  std::cout << "unregistering check" << std::endl;
  uv_check_stop(check_handle_);
  delete check_handle_;
  uv_unref(uv_default_loop());

  return scope.Close(Undefined());
}

void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "registerCheck", RegisterCheck);
  NODE_SET_METHOD(target, "unregisterCheck", UnregisterCheck);
}

NODE_MODULE(check, init)

