#ifndef GBC_C_WRAPPER_H
#define GBC_C_WRAPPER_H

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
