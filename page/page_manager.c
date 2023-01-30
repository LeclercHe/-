
#include <string.h>
#include "page_manager.h"
#include "common.h"

static PPageAction g_ptPages = NULL;

void RegisterPage(PPageAction ptPageAction)
{
	ptPageAction->ptNext = g_ptPages;
	g_ptPages = ptPageAction;
}

PPageAction Page(char *name)
{
    PPageAction ptTmp = g_ptPages;
    while(ptTmp)
    {
        if(strcmp(  ptTmp->name,name) == 0)
        {
            return ptTmp;
        }
        ptTmp = ptTmp->ptNext;
    }
    return NULL;
}


void PagesRegister(void)
{
    extern void MainPageRegister(void);
    MainPageRegister();
}

