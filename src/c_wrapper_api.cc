#include "c_wrapper_api.h"
#include "client/linux/handler/exception_handler.h"
#include <stdio.h>

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
  return reinterpret_cast<void*>(new google_breakpad::ExceptionHandler(descriptor, NULL, dumpCallback, NULL, true, -1));
}

