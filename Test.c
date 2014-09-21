
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  test.cpp                               */
/*  PRINCIPAL AUTHOR      :  gongxuan                               */
/*  SUBSYSTEM NAME        :  test                                   */
/*  MODULE NAME           :  test                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/9/19                              */
/*  DESCRIPTION           :  test program                           */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by gongxuan,2014/9/19
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "linktable.h"

#define CMD_MAX 100
typedef struct DataNode
{
	tLinkTableNode *pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

int Help();
tDataNode *FindCmd(tLinkTable * head,char * cmd);
int ShowAllCmd(tLinkTable *head);

static tDataNode data[] = 
{
	{ NULL,"help", "this is help cmd!", Help},
	{ NULL,"version", "menu program v1.0", NULL}
};
/* cmd:"help" show all the cmds */

tLinkTable *head =NULL;
int main()
{

	head = CreateLinkTable();
	AddLinkTableNode(head,(tLinkTableNode *)&data[0]);
	AddLinkTableNode(head,(tLinkTableNode *)&data[1]);

	//Help();

	while(1)
	{
		char cmd[CMD_MAX];
		printf("Input a cmd: ");
		scanf("%s",cmd);
		tDataNode *p = FindCmd(head,cmd);
		if(p == NULL)
		{
			printf("it is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n",p->cmd,p->desc);
		if(p->handler!=NULL)
		{
			p->handler();
		}
	}
	return 0;
}
/*find a cmd and return the point */
tDataNode *FindCmd(tLinkTable * head,char * cmd)
{
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
	while(pNode!=NULL)
	{
		if(!strcmp(pNode->cmd,cmd))
		{
			return pNode;
		}
		pNode = (tDataNode*) GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
	}
	return NULL;
}
/* show all the cmds */
int ShowAllCmd(tLinkTable *head)
{
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
	while(pNode!=NULL)
	{
		printf("%s - %s\n",pNode->cmd,pNode->desc);
		pNode = (tDataNode*) GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
	}
	return 0;
}
int Help()
{
	ShowAllCmd(head);
    return 0; 
}