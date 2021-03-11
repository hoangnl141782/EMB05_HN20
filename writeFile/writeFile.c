// SPDX-License-Identifier: GPL-2.0

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXCOUNT		5000000ULL


char filename[10];
int name;

void *writetoFile(void *numberOfFile)
{
	int randomnumber;
	char numChar;
	unsigned long long i = 0;
	int fileNumber = *(int *) numberOfFile;
	int fileCount = 0;
	FILE *fp;
	//int fd = -1;

	for (fileCount = 0; fileCount < fileNumber; fileCount++) {
		sprintf(filename, "a%d.txt", name);
		fp = fopen(filename, "w");
		//fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fp == NULL) {
		//if (fd == -1) {
			printf("Can not open file...\n");
		} else {
			for (i = 0; i < MAXCOUNT; i++) {
				randomnumber = rand() % 10;
				numChar = randomnumber + '0';
				fputc(numChar, fp);
				//fputc(' ', fp);
				//write(fd, &numChar, sizeof(char));
			}
		}
		name++;
		fclose(fp);
		//close(fd);
	}
	
	return NULL;

}

int main(int argc, char *argv[])
{
	//Var
	time_t timeDiff;
	int maxFile = 8;
	int maxFile0 = 2;
	int maxFile1 = 2;
	int maxFile2 = 2;
	int maxFile3 = 2;
	int maxFile4 = 2;
	pthread_t thread0;
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	/*pthread_t thread4;*/

	//Code
	printf("Single core:\n");
	srand(time(NULL));
	timeDiff = time(0);
	writetoFile((void *) &maxFile);
	timeDiff = time(0) - timeDiff;
	printf("%d------%ld\n", name, timeDiff);

	printf("Multithread:\n");
	timeDiff = time(0);
	pthread_create(&thread0, NULL, writetoFile, (void *) &maxFile0);
	pthread_create(&thread1, NULL, writetoFile, (void *) &maxFile1);
	pthread_create(&thread2, NULL, writetoFile, (void *) &maxFile2);
	pthread_create(&thread3, NULL, writetoFile, (void *) &maxFile3);
	/*pthread_create(&thread4, NULL, writetoFile, (void *) &maxFile4);*/
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	/*pthread_join(thread4, NULL);*/
	timeDiff = time(0) - timeDiff;
	printf("%d------%ld\n", name, timeDiff);

	return 0;
}