#ifndef SIGNAALIT_H_INCLUDED
#define SIGNAALIT_H_INCLUDED

#include <setjmp.h>
#include <signal.h>

extern jmp_buf paluuTila;

void hoidaSIGFPE(int s);

void hoidaSIGSEGV(int s);

#endif /* SIGNAALIT_H_INCLUDED */
