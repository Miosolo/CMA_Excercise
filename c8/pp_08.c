// analyse students' grades

#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 5

int main(void)
{
	float grades[STUDENTS][SUBJECTS] = {{0}},
		sum_student[STUDENTS] = {0}, sum_subject[SUBJECTS] = {0},
		highest[SUBJECTS] = {0};

	float lowest[SUBJECTS];
	for (int i = 0; i < SUBJECTS; i++)
		lowest[i] = 100;

	// input the grade table
	for (int i = 0; i < STUDENTS; i++)
	{
		printf("Enter student %d's grade: ", i + 1);
		for (int j = 0; j < SUBJECTS; j++)
			scanf("%f", &grades[i][j]);
		fflush(stdin);
	}

	//total & average grade for every student
	printf("Students' total grades:\n");
	for (int i = 0; i < STUDENTS; i++)
	{
		for (int j = 0; j < SUBJECTS; j++)
			sum_student[i] += grades[i][j];
		printf("%.1f\t", sum_student[i]);
	}
	printf("\n");

	printf("Students' average grades:\n");
	for (int i = 0; i < STUDENTS; i++)
		printf("%.1f\t", sum_student[i] / SUBJECTS);
	printf("\n");

	// analyse every subject (average, hightest and lowest grades)
	for (int j = 0; j < SUBJECTS; j++)
	{
		for (int i = 0; i < STUDENTS; i++)
		{
			sum_subject[j] += grades[i][j];
			highest[j] = (grades[i][j] >= highest[j]) ? grades[i][j] : highest[j];
			lowest[j] = (grades[i][j] <= lowest[j]) ? grades[i][j] : lowest[j];
		}
	}

	printf("Average grades of all subjects: \n");
	for (int j = 0; j < SUBJECTS; j++)
		printf("%.1f\t", sum_subject[j] / STUDENTS);
	printf("\n");

	printf("Hightest grades of all subjects: \n");
	for (int j = 0; j < SUBJECTS; j++)
		printf("%.1f\t", highest[j]);
	printf("\n");

	printf("Lowtest grades of all subjects: \n");
	for (int j = 0; j < SUBJECTS; j++)
		printf("%.1f\t", lowest[j]);
	printf("\n");

	return 0;

}
