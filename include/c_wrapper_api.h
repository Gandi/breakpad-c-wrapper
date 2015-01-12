#ifndef BREAKPAD_C_API_H__
#define BREAKPAD_C_API_H__

typedef void*   CExceptionHandler;

#ifdef __cplusplus
extern "C"
{
#endif
CExceptionHandler newCExceptionHandlerSimple(void);
#ifdef __cplusplus
}
#endif

#endif


