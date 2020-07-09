#include <iostream>
#include "pthread.h"

void *pThreadFunction(void *vargp) {
  std::cout << "pthread!\n\n";
  return NULL;
}

int main() {
  std::cout <<
      "C doesn't have built in-support for threading, and has to rely on a platform-dependent\n"
      "implementation called POSIX threads (or Pthreads).\n"
      "\n"
      "pthreads work like so:\n"
      "\n"
      "\t1. create a pthread_t - this is the identifier for the thread.\n"
      "\t2. call pthread_create - this starts the thread, takes four args:\n"
      "\t                         a pthread_t\n"
      "\t                         an optional pthread_attr_t\n"
      "\t                         a start routine w/ signature void *func(void *arg);\n"
      "\t                         an optional void *arg passed to the start routine\n"
      "\t3. exit the routine with pthread_exit(status void*)\n"
      "\t   (or just return a void *status or NULL from the start routine).\n"
      "\n"
      "Misc other API:\n"
      "\n"
      "\tpthread_join(pthread_t, void **retval) - waits for the thread to exit, copying the\n"
      "\t    exit result into retval.\n"
      "\tpthread_detach(pthread_t) - mark the thread as detached so the system releases its\n"
      "\t    resources without waiting for a join.\n"
      "\n";

  pthread_t thread_id;
  pthread_create(&thread_id, NULL, pThreadFunction, NULL);
  pthread_join(thread_id, NULL);

  return 0;
}
