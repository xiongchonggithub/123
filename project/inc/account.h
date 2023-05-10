#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include<stdio.h>
#include<string.h>

#include"../src/account.c"

#include"display.h"
#include"ymd.h"


int compare(char *login_id,char *login_password);
void system_login();
int system();
void system_acc();
int system_sw(int ret);
void nor();
void vip();
void admin();
void acc_enter();


#endif