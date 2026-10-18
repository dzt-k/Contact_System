#include "contact.h"

int main() {
    load_from_file();
    int choice;
    do {
        menu();
        printf("What will you do?");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_contact(); break;
            case 2: show_all_contact(); break;
            case 3: search_contact(); break;
            case 4: delete_contact(); break;
            case 5: modify_contact(); break;
            // 其他 case...
        }
    } while (choice != 0);
    
    save_to_file();
    free_list();
    return 0;
}