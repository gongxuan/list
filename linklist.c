/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linklist.c                                                           */
/*  PRINCIPAL AUTHOR      :  gongxuan                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/10                                                           */
/*  DESCRIPTION           :  linklist for menu program                                            */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Gongxuan, 2014/09/11
 *
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct  DataNode *next;
} tDataNode;

#define CH_NUM 100	//define the size of ch 

//find the cmd and return it,if not find return NULL
tDataNode* FindCmd(tDataNode * head, char * cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;        
    }
    tDataNode *p = head;
    while(p != NULL)
    {
        if(!strcmp(p->cmd, cmd))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
//show all the cmd 
int ShowAllCmd(tDataNode * head)
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s\n", p->cmd);
        p = p->next;
    }
    return 0; 
}
// input the cmd and stop by input the "0"
tDataNode *InputCmd()
{
tDataNode *head = NULL;
tDataNode *p = NULL;
char *ch;
while(1)
{
p = (tDataNode*)malloc(sizeof(tDataNode));
ch = (char *)malloc(CH_NUM);
printf("Input a cmd >");
gets(ch);
if(strcmp(ch,"0")==0)
break;
p->cmd = ch;
ch = NULL;
p->next = head;
head = p;
}
return head;
}
int main()
{
tDataNode *test = NULL;
test = (tDataNode*)malloc(sizeof(tDataNode));
test = InputCmd();
ShowAllCmd(test);
system("pause");
tDataNode *p = NULL;
p = FindCmd(test,"gong");
if(p==NULL)
printf("can't find gong\n");
else
printf("%s\n",p->cmd);
system("pause");
return 0;
}
