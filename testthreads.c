#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void func1(void* arg1, void* arg2) {
  int num1 = *(int*)arg1;
  int num2 = *(int*)arg2;
  printf(1, "hello from func1, arg1: %d, arg2: %d\n", num1, num2);
  sleep(100);
  exit();
}

void func2(void* arg1, void* arg2) {
  int num1 = *(int*)arg1;
  int num2 = *(int*)arg2;
  printf(1, "hello from func2, arg1: %d, arg2: %d\n", num1, num2);
  sleep(100);
  exit();
}


int
main(int argc, char *argv[])
{
  int arg11 = 1;
  int arg12 = 2;
  int arg21 = 3;
  int arg22 = 4;
  printf(1, "Hello from parent\n");
  thread_create(&func1, (void *)&arg11, (void *)&arg12);
  thread_create(&func2, (void *)&arg21, (void *)&arg22);
  thread_join();
  thread_join();
  exit();  
}