#include <stdio.h>
#include <client/linux/handler/exception_handler.h>
#include "gbc_c_wrapper.h"

class ExceptionGandlerSingleton
{
public:
  static
  google_breakpad::ExceptionHandler* getInstance(google_breakpad::MinidumpDescriptor &descriptor, google_breakpad::ExceptionHandler::MinidumpCallback dumpCallback)
  {
    if (!instance_) {
        descriptor_ = descriptor;
        dumpCallback_ = dumpCallback;
        instance_ = new google_breakpad::ExceptionHandler(descriptor_, 0, dumpCallback_, 0, true, -1);
    }

    return instance_;
  }

  static
  google_breakpad::ExceptionHandler* getInstance()
  {
    if (!instance_) {
        instance_ = new google_breakpad::ExceptionHandler(descriptor_, 0, dumpCallback_, 0, true, -1);
    }

    return instance_;
  }

  static
  void destroy_instance()
  {
    delete instance_;
    instance_ = 0;
  }

private:
  static google_breakpad::MinidumpDescriptor descriptor_;
  static google_breakpad::ExceptionHandler::MinidumpCallback dumpCallback_;
  static google_breakpad::ExceptionHandler* instance_;
};

google_breakpad::MinidumpDescriptor ExceptionGandlerSingleton::descriptor_;
google_breakpad::ExceptionHandler::MinidumpCallback ExceptionGandlerSingleton::dumpCallback_;
google_breakpad::ExceptionHandler* ExceptionGandlerSingleton::instance_;

static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                         void* context,
                         bool succeeded)
{
  printf("Dump path: %s.dmp\n", descriptor.path());
  return succeeded;
}

extern "C" CExceptionHandler newCExceptionHandlerSimple(void)
{
  google_breakpad::MinidumpDescriptor descriptor("/tmp");
  return reinterpret_cast<void*>(ExceptionGandlerSingleton::getInstance(descriptor, dumpCallback));
}

extern "C" void RegisterAppMemory(void* ptr, size_t length)
{
  ExceptionGandlerSingleton::getInstance()->RegisterAppMemory(ptr, length);
}

extern "C" void UnregisterAppMemory(void* ptr)
{
  ExceptionGandlerSingleton::getInstance()->UnregisterAppMemory(ptr);
}
