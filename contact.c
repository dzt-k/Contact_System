#include "contact.h"

#define NAME_LEN 30
#define PHONE_LEN 20

Contact* head = NULL;

void menu(){
    printf("\n==========THE CONTACT==========\n");
    printf("1.Add new\n");
    printf("2.Show ALL\n");
    printf("3.Search\n");
    printf("4.Delete\n");
    printf("5.Modify\n");
    printf("0.Save,and quit\n");
    printf("\n===============================\n");
  }

  void add_contact(){
    Contact* newNode = (Contact*)malloc(sizeof(Contact));
    if (newNode == NULL){
        printf("ERROR!\n");
        return;
    }
    printf("name");
    scanf("%s",newNode -> name);
    printf("age");
    scanf("%d",&newNode -> age);
    printf("phone number");
    scanf("%s",newNode -> phone);
    newNode -> next = NULL;

    if (head == NULL){
        head = newNode;
    }else{
        Contact* temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    printf("success\n");
  }

  void search_contact(){
    char target_name[NAME_LEN];
    printf("WHO YOU WANT:");
    scanf("%s",target_name);

    Contact* current = head;
    while (current != NULL){
        if (strcmp(current -> name,target_name) == 0){
            printf("FINISH! name:%s age:%d phone:%s\n",current -> name, current -> age, current ->phone);
            return;
        }
        current =current -> next; 
    }
    printf("Error,no such person found\n");
  }

  void show_all_contact(){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
    printf("\n%-15s %-10s %-15s\n","name","age","phone");
    printf("----------------------------------------\n");

    Contact* current = head;
    while(current != NULL){
        printf("%-15s %-10d %-15s\n",current -> name,current -> age,current -> phone);
        current = current -> next;
    }
  }

  void delete_contact(){
    char target_name[NAME_LEN];
    printf("Who you want to delete:");
    scanf("%s",target_name);

    Contact* current = head;
    Contact* prev = NULL;

    while(current != NULL && strcmp(current -> name,target_name) != 0){
        prev = current;
        current = current -> next;
    }
    if (current == NULL){
        printf("no such person found\n");
        return;
    }
    if (prev == NULL){
        head = current -> next;
    }else{
        prev -> next = current -> next;
    }
        free(current);
        current = NULL;
        printf("Success\n");
  }

  void modify_contact(){
    char target_name[NAME_LEN];
    printf("How to motify:");
    scanf("%s",target_name);

    Contact* current = head;
    while (current != NULL){
      if (strcmp(current -> name,target_name) == 0){
         printf("name");
    scanf("%s",current -> name);
    printf("age");
    scanf("%d",&current -> age);
    printf("phone number");
    scanf("%s",current -> phone);
    printf("MOTIFY OVER\n");
    return;
      }
      current = current -> next;
    }
    printf("no such person found\n");
  }

  void free_list(){
    Contact* current = head;
    Contact* temp = NULL;
    while(current != NULL){
        temp = current;
        current = current -> next;
        free (temp);
    }
    head = NULL;
  }

  void  save_to_file(){
    FILE* fp = fopen("contacts.dat","wb");
    if (fp == NULL){
        printf("ERROR,open dead");
        return;
    }

    Contact* current = head;
    int count;
    while(current != NULL){
        fwrite(current,sizeof(Contact),1,fp);
        current = current -> next;
        count++;
    }
    fclose(fp);
    printf("Save to file %d\n",count);
  }

  void load_from_file(){
    FILE* fp = fopen("contacts.dat","rb");
    if (fp == NULL){
        return;
    }
    Contact temp;
    while (fread(&temp,sizeof(Contact),1,fp) == 1){
        Contact* newNode = (Contact*)malloc(sizeof(Contact));
        if (newNode == NULL){
            break;
        }
        *newNode = temp;
        newNode -> next = NULL;

        if (head == NULL){
        head = newNode;
    }else{
        Contact* last = head;
        while (last -> next != NULL){
            last = last -> next;
        }
        last -> next = newNode;
     }
    }
    fclose(fp);
    printf("loading...\n");
  }