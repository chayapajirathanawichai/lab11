#include <stdio.h>
#include<stdlib.h>
#define no_score 5
typedef struct{
	char name[16];
	char surname[20];
	int score[no_score];
	float total;
}Student;
void writeStudenttofile(Student *); //add
void readStudentData(Student *);
void findtotalScore(Student *);
float findAverage(Student *);
void findLessThanTen(Student *);

int main(){
	Student std[10];
	writeStudenttofile(std);
	float avg;
	readStudentData(std);
	findtotalScore(std);
	
	avg=findAverage(std);
	printf("\n\nAverage score is %.2f",avg);
	findLessThanTen(std);
	return 0;
}

void writeStudenttofile(Student *pStd){
	FILE *fptr;
	fptr=fopen(".\\lab11\\no2\\std10.dat","wb"); //write block
	if(fptr==NULL){
		printf("can't open file\n");return;
	}
	printf("Input 10 Student data\n");
	for(int i=0;i<10;i++){
		printf("Student %d\n",i+1);
		printf("Name: ");scanf("%s",pStd[i].name);
		printf("Surname: ");scanf("%s",pStd[i].surname);
		for(int j=0;j<no_score;j++){
			printf("Score %d: ",j+1);scanf("%d",&pStd[i].score[j]);
			printf("\n");
		}
		fwrite(&pStd[i],sizeof(Student),1,fptr);
	}
	fclose(fptr);
	printf("Data saved successfully\n\n");
}

void readStudentData(Student *pStd){
	int i;
	FILE *fptr;
	fptr=fopen(".\\lab11\\no2\\std10.dat","rb");
	if(fptr==NULL){
		printf("can't open file\n");return;
	}
	for(i=0;i<10;i++){
		fread(&pStd[i],sizeof(Student),1,fptr);
	}
	fclose(fptr);
	printf("Read Success!\n");
}

void findtotalScore(Student *pStd) {
	int i;
	printf("find total score\n");
	for(i=0;i<10;i++){
		pStd[i].total=0;
		for(int j=0;j<no_score;j++){
			pStd[i].total+=pStd[i].score[j];
		}
	printf("%s %s: Total = %.2f\n", pStd[i].name, pStd[i].surname, pStd[i].total);	
	}
}

void findLessThanTen(Student *s) {
	int i,count=0;
	printf("\n\nScore less than 10");
	for (i=0; i<10; i++) {
		for(int j=0;j<no_score;j++){
			if (s[i].score[j] < 10) {
				printf("\n\tTest no.%d - %d\n", i+1, s[i].score[i]);
				count++;
			}
		}
		
	}
	if (count==0) //no test less than 10 points.
	printf(" -> None\n");
}

float findAverage(Student *std){
	float sum;
	for(int i=0;i<no_score;i++){
		sum=0.0;
		for(int j=0;j<10;j++){
			sum+=std[i].score[j];
		}
		return sum/(10*no_score);
	}
}
