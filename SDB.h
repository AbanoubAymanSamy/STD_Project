#ifndef SDB_H_
#define SDB_H_
#include "STD.h"
#define maxCountOfStudents 10

typedef struct SimpleDb{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
	} Student;
	
	
bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint32 *count, uint32 *list);
bool SDB_IsIdExist(uint32 id);


#endif	