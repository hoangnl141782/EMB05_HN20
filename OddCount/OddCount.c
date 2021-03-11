#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define BIL		1000000000ULL
#define MUL		100
#define DIVMUL		10

unsigned long long oddSum = 0;

void *oddCount(void *ptr)
{
	unsigned long long i = 0;
	unsigned long long n = *(unsigned long*)ptr;
	unsigned long long oddCountTmp = 0;

	for (i = 1; i <= n; i++) {
		if ((i & 1) == 1)
			oddCountTmp++;
	}

	oddSum += oddCountTmp;

	return NULL;
}

int main(int argc, char *argv[])
{
	//Var
	time_t timeDiff;
	unsigned long long count = MUL*BIL;
	unsigned long count0 = DIVMUL*BIL;
	unsigned long count1 = DIVMUL*BIL;
	unsigned long count2 = DIVMUL*BIL;
	unsigned long count3 = DIVMUL*BIL;
	unsigned long count4 = DIVMUL*BIL;
	unsigned long count5 = DIVMUL*BIL;
	unsigned long count6 = DIVMUL*BIL;
	unsigned long count7 = DIVMUL*BIL;
	unsigned long count8 = DIVMUL*BIL;
	unsigned long count9 = DIVMUL*BIL;
	
	pthread_t thread0;
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	pthread_t thread5;
	pthread_t thread6;
	pthread_t thread7;
	pthread_t thread8;
	pthread_t thread9;

	//Code
	printf("Single core:\n");
	oddSum = 0;
	timeDiff = time(0);
	oddCount((void *) &count);
	timeDiff = time(0) - timeDiff;
	printf("Odd Count: %lld\n", oddSum);
	printf("----------------------%ld sec\n", timeDiff);

	printf("Multithread:\n");
	oddSum = 0;
	timeDiff = time(0);
	pthread_create(&thread0, NULL, oddCount, (void*) &count0);
	pthread_create(&thread1, NULL, oddCount, (void*) &count1);
	pthread_create(&thread2, NULL, oddCount, (void*) &count2);
	pthread_create(&thread3, NULL, oddCount, (void*) &count3);
	pthread_create(&thread4, NULL, oddCount, (void*) &count4);
	pthread_create(&thread5, NULL, oddCount, (void*) &count5);
	pthread_create(&thread6, NULL, oddCount, (void*) &count6);
	pthread_create(&thread7, NULL, oddCount, (void*) &count7);
	pthread_create(&thread8, NULL, oddCount, (void*) &count8);
	pthread_create(&thread9, NULL, oddCount, (void*) &count9);
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	pthread_join(thread6, NULL);
	pthread_join(thread7, NULL);
	pthread_join(thread8, NULL);
	pthread_join(thread9, NULL);
	timeDiff = time(0) - timeDiff;
	printf("Odd Count: %lld\n", oddSum);
	printf("----------------------%ld sec\n", timeDiff);

	return 0;
}

