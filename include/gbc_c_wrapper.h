#ifndef GBC_C_WRAPPER_H
#define GBC_C_WRAPPER_H

#include <sys/types.h>

typedef void*   CExceptionHandler;

#ifdef __cplusplus
extern "C"
{
#endif
CExceptionHandler newCExceptionHandlerSimple(void);
void RegisterAppMemory(void* ptr, size_t length);
void UnregisterAppMemory(void* ptr);
#ifdef __cplusplus
}
#endif

#endif
