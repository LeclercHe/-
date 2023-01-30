#ifndef PAGE_MANAGER_H
#define PAGE_MANAGER_H


typedef struct PageAction{
    char   *name;                   /*页面名字*/
    void   (*Run)(void *pParams);   /*页面的运行函数*/
    struct PageAction *ptNext;      /*链表*/
}PageAction,*PPageAction;




void RegisterPage(PPageAction ptPageAction);
void PagesRegister(void);
PPageAction Page(char *name);

#endif
