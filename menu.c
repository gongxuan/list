/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  menu.c                                 */
/*  PRINCIPAL AUTHOR      :  gongxuan                               */
/*  SUBSYSTEM NAME        :  menu                                   */
/*  MODULE NAME           :  menu                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/9/19                              */
/*  DESCRIPTION           :  menu program                           */
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
#include "menu.h"
#define CMD_MAX 100
/* 
 * menu program control inputs and the outputs
 */
int menu(tLinkTable *head)
{
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
			p->handler(head);
		}
	}
	return 0;
}
/*
 * find a cmd and return the point 
 */
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
/* 
 * show all the cmds 
 */
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
/* 
 * cmd:"help" show all the cmds 
 */
int Help(tLinkTable *head)
{
	ShowAllCmd(head);
    return 0; 
}