#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

#define N 10

void* new_thread(void* thread_id) { 
	printf("%d - thread id\n", *(int*)thread_id); 
	return 0;
} 


int main(int argc, char const *argv[]) {
	
	pthread_t thread_id[N]; 
	for (int i = 0; i < N; ++i) {
		printf("Thread creation\n");
		if(pthread_create(&thread_id[i], NULL, new_thread, (void *)&i)) {
			printf("Creation failed\n");
			return 1;
		}
		pthread_join(thread_id[i], NULL); 
		// printf("After Thread\n"); 
		// exit(0); 
	}
	return 0;
}