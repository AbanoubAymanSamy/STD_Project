#include<stdio.h>
#include"SDB.h"

//this to know the number of students.
Student countOfBase[maxCountOfStudents];
uint32 studentCurrentCount = 0;

//this function to check if the data base is full or not.
bool SDB_IsFull(){
	if(studentCurrentCount>=maxCountOfStudents){
		return true;
	}
	else{
		return false;
	}
}

//this function let the user know the number of students in database.
uint8 SDB_GetUsedSize(){
	return studentCurrentCount;
}

//this function let the user can add a new student to the database.
bool SDB_AddEntry(){
//i wrote the if condition to check the user can add or not.
	if(SDB_IsFull()){
        printf("\nSorry the database is full.");
        return false;
	}	
	Student Name;
	printf("\nEnter the student ID: ");
	scanf("%d",&Name.Student_ID);
	printf("\nEnter the student year: ");
	scanf("%d",&Name.Student_year);
	printf("\nEnter the student Course1 ID: ");
	scanf("%d",&Name.Course1_ID);
	printf("\nEnter the student Course1 grade: ");
	scanf("%d",&Name.Course1_grade);
	printf("\nEnter the student Course2 ID: ");
	scanf("%d",&Name.Course2_ID);
	printf("\nEnter the student Course2 grade: ");
	scanf("%d",&Name.Course2_grade);
	printf("\nEnter the student Course3 ID: ");
	scanf("%d",&Name.Course3_ID);
	printf("\nEnter the student Course3 grade: ");
	scanf("%d",&Name.Course3_grade);
	
	
	countOfBase[studentCurrentCount]=Name;
    studentCurrentCount++;	       //this line to add 1 to the number of students in the database.
    printf("\nthe new student added successfully");
	return true;
}

//this function to let the user to delete informations of the id which he will enter.
void SDB_DeleteEntry(uint32 id){
    for (uint32 i=0;i<studentCurrentCount;i++){
        if (countOfBase[i].Student_ID == id){
            for(uint32 j=i;j<studentCurrentCount-1;j++){
                countOfBase[j]=countOfBase[j+1];
            }
            studentCurrentCount--;
            printf("\nStudent with ID %d deleted successfully.", id);
            return;
        }
	}
}

//this function let the user to know everything about the id which he was added to database.
bool SDB_ReadEntry(uint32 id){
    for(uint32 i=0; i<studentCurrentCount;i++){
        if(countOfBase[i].Student_ID == id){
            printf("\nStudent ID: %d", countOfBase[i].Student_ID);
            printf("\nYear: %d", countOfBase[i].Student_year);
            printf("\nCourse 1 ID: %d, Grade: %d", countOfBase[i].Course1_ID,countOfBase[i].Course1_grade);
            printf("\nCourse 2 ID: %d, Grade: %d", countOfBase[i].Course2_ID,countOfBase[i].Course2_grade);
            printf("\nCourse 3 ID: %d, Grade: %d", countOfBase[i].Course3_ID,countOfBase[i].Course3_grade);
            return true;
        }
    }
    printf("\nStudent with ID %d not found in the database.", id);
    return false;
}

//this function let the user to get the list of ids.
void SDB_GetList(uint32 *count, uint32 *list){
    *count=studentCurrentCount;
    for(uint32 i=0;i<studentCurrentCount;i++){
        list[i]=countOfBase[i].Student_ID;
    }
}

//this function let the user to check if the id which he was entered is in database or not.
bool SDB_IsIdExist(uint32 id){
    for(uint32 i=0; i<studentCurrentCount;i++){
        if(countOfBase[i].Student_ID == id){
            return true;
        }
    }
    return false;
}