#include <stdio.h>
#include "SDB.h"


/* i wrote the function under SDB_APP function to arrange the codes
and the name of function which i have to write it before SDB_APP()
function to let the code run correctly.*/

void SDB_action(uint32 choice);
//the function which let the user to choose what is he want to do.
void SDB_APP() {
    uint32 choice;
// i used the do-while loop ;because it`s the best choice in this position.
    do {
        printf("\nChoose an option:");
        printf("\n1. To add entry, enter 1");
        printf("\n2. To get used size in database, enter 2");
        printf("\n3. To read student data, enter 3");
        printf("\n4. To get the list of all student IDs, enter 4");
        printf("\n5. To check if ID is existed, enter 5");
        printf("\n6. To delete student data, enter 6");
        printf("\n7. To check if database is full, enter 7");
        printf("\n8. To exit, enter 0");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        SDB_action(choice);
    } while (choice != 0);
}

/*
this is function works when the user enter number
for example the user enter 5 this function will do
the choice number 5 and in our state check if the id is exist or not
*/
 
void SDB_action(uint32 choice) {
    uint32 id;
    uint32 count;
    uint32 list[maxCountOfStudents];

    switch (choice) {
        case 1:SDB_AddEntry(); break;
        case 2:printf("\nUsed size in database: %d", SDB_GetUsedSize()); break;
        case 3:printf("\nEnter student ID to read: "); scanf("%d", &id); SDB_ReadEntry(id); break;
        case 4:
            SDB_GetList(&count, list);
            printf("\nNumber of students: %d", count);
            for (uint32 i=0; i<count;i++) {
                printf("\nStudent ID: %d",list[i]);
            }
            break;
        case 5:
            printf("\nEnter student ID to check existence: ");
            scanf("%d", &id);
            if (SDB_IsIdExist(id)) {
                printf("\nStudent with ID %d exists in the database.",id);
            } else {
                printf("\nStudent with ID %d does not exist in the database.",id);
            }
            break;
        case 6:
            printf("\nEnter student ID to delete: ");
            scanf("%d", &id); SDB_DeleteEntry(id); break;
        case 7:
            if (SDB_IsFull()){
                printf("\nThe database is full.");
            }
			else{
                printf("\nThe database is not full.");
            } break;
        case 0:printf("\nExiting the program."); break;
    }
}
