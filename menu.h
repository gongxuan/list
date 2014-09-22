/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  menu.h                                 */
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
#ifndef _MENU_H_
#define _MENU_H_
#include <stdio.h>

typedef struct DataNode
{
	tLinkTableNode *pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)(tLinkTable *head);
} tDataNode;
/* 
 * cmd:"help" show all the cmds 
 */
int Help(tLinkTable *head);
/*
 * find a cmd and return the point 
 */
tDataNode *FindCmd(tLinkTable * head,char * cmd);
/* 
 * show all the cmds 
 */
int ShowAllCmd(tLinkTable *head);
/* 
 * menu program control inputs and the outputs
 */
int menu(tLinkTable *head);

static tDataNode data[] = 
{
	{ NULL,"help", "this is help cmd!", Help},
	{ NULL,"version", "menu program v1.0", NULL}
};

#endif /* _MENU_H_ */