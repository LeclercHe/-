
#include "configer.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

static ItemCfg g_tItemCfgs[ITEMCFG_MAX_NUM];
static int g_iItemCfgCount = 0;

int ParseConfigFile(void)
{
    FILE *fp;
    char buf[100];
    char *p = buf;
    
    /* 打开配置文件*/
    fp = fopen(CFG_FILE, "r");
    if(!fp)
    {
        printf("can't open config file %s!\n",CFG_FILE);
        return -1;
    }
    while(fgets(buf, 100, fp)) //读出每一行
    {
        buf[99] = '\0';
        /*吃掉开头的空格或TAB*/
        p = buf;
        while(*p == ' ' || *p == '\t')
        {
            p++;
        }
        /*忽略注释*/
        if(*p == '#')
            continue;
        /*处理*/
        g_tItemCfgs[g_iItemCfgCount].command[0] = '\0';
        g_tItemCfgs[g_iItemCfgCount].index = g_iItemCfgCount;
        sscanf(p, "%s %d %s", g_tItemCfgs[g_iItemCfgCount].name, 
                              &g_tItemCfgs[g_iItemCfgCount].bCanBeTouched,
                              g_tItemCfgs[g_iItemCfgCount].command);
        g_iItemCfgCount++;
    }
    return 0;
}


int GetItemCfgCount(void)
{
    return g_iItemCfgCount;
}

PItemCfg GetItemCfgByIndex(int index)
{
    if(index < g_iItemCfgCount)
        return &g_tItemCfgs[index];
    else
        return NULL;
}

PItemCfg GetItemCfgByName(char *name)
{
    int i;
    for(i =0 ; i <g_iItemCfgCount; i++)
    {
        if(strcmp(name, g_tItemCfgs[i].name) == 0)
            return &g_tItemCfgs[i];
    }
    return NULL;
}

