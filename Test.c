/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  test.c                                 */
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
#include "linktable.h"
#include "menu.h"
#include <stdio.h>

tLinkTable *head =NULL;
int main()
{
	head = CreateLinkTable();
	AddLinkTableNode(head,(tLinkTableNode *)&data[0]);
	AddLinkTableNode(head,(tLinkTableNode *)&data[1]);
	Help(head);
	menu(head);
	return 0;
}

