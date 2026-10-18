#ifndef CONTACT_H
#define CONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体定义
typedef struct Contact {
    char name[50];
    int age;
    char phone[20];
    struct Contact* next;
} Contact;

// 全局头指针声明
extern Contact* head;

// 函数声明
void menu();
void add_contact();
void show_all_contact();
void search_contact();
void delete_contact();
void modify_contact();
void save_to_file();
void load_from_file();
void free_list();

#endif