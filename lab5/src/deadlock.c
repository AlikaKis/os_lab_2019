#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do_one_thing();
void do_another_thing();
int a = 1;
int b = 2;
pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

int main() {
  pthread_t thread1, thread2;

  if (pthread_create(&thread1, NULL, (void *)do_one_thing, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&thread2, NULL, (void *)do_another_thing, NULL) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_join(thread1, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  if (pthread_join(thread2, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  return 0;
}

void do_one_thing() {
    int temp1;
    int temp2;
    pthread_mutex_lock(&mut1);
    printf("thread 1, getting a\n");
    temp1 = a;
    sleep(1);   // чтобы второй поток успел залочить mut2
    pthread_mutex_lock(&mut2);
    temp2 = b;
    printf("thread 1, getting b\n");
    printf("thread 1: sum = %d\n", temp1 + temp2);
    pthread_mutex_unlock(&mut2);
	pthread_mutex_unlock(&mut1);
}

void do_another_thing() {
    int temp1;
    int temp2;
    pthread_mutex_lock(&mut2);
    printf("thread 2, getting b\n");
    temp1 = b;
    pthread_mutex_lock(&mut1);
    temp2 = a;
    printf("thread 2, getting a\n");
    printf("thread 2: sum = %d\n", temp1 + temp2);
    pthread_mutex_unlock(&mut1);
	pthread_mutex_unlock(&mut2);
}