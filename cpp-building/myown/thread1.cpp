#include <stdio.h>  
#include <pthread.h>  
#include <unistd.h>

pthread_key_t   key;  
void echomsg(void*)  
{  
        printf("destructor excuted in thread %d\n",(int)pthread_self());  
}  
void * child1(void *arg)  
{  
        pthread_t tid=pthread_self();  
        printf("thread %ld enter\n",tid);  
        pthread_setspecific(key,(void *)tid);  
        sleep(2);  
        printf("thread %d returns %d\n",tid,pthread_getspecific(key));  
        sleep(5);  
}  
void * child2(void *arg)  
{  
        int tid=(int)pthread_self();  
        printf("thread %d enter\n",tid);  
        pthread_setspecific(key,(void *)tid);  
        sleep(1);  
        printf("thread %d returns %d\n",tid,pthread_getspecific(key));  
        sleep(5);  
}  
int main(void)  
{  
        pthread_t tid1,tid2;  
        printf("hello\n");  
        pthread_key_create(&key,echomsg);  
        pthread_create(&tid1,NULL,child1,NULL);  
        pthread_create(&tid2,NULL,child2,NULL);  
        sleep(10);  
        pthread_key_delete(key);  
        printf("main thread exit\n");  
        return 0;  
}
