#include <stdio.h>
#include <sys/sem.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

const int N = 1000;
typedef struct
{
    int pid;
    char buf[N];
} shmbuf;
int sem_id, ret;
int main()
{
    key_t key = ftok(".", "a");
    struct sembuf sops[2];
    sops[0].sem_num = 0;
    sops[0].sem_op = 1;
    sops[0].sem_flg = 0;
    sops[1].sem_num = 1;
    sops[1].sem_op = -1;
    sops[1].sem_flg = 0;

    unsigned short sem_array[2];
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;

    sem_array[0] = 0;
    sem_array[1] = 1;
    arg.array = sem_array;
    ret = semctl(sem_id, 0, SETALL, arg);
    sem_id = semget(key, 2, IPC_CREAT | 0644);

    int shmid = shmget(key, sizeof(shmbuf), IPC_CREAT | IPC_EXCL | 0666);
    pid_t pid;
    while ((pid = fork()) == -1)
        ;
    if (pid == 0)
    {
        while (1)
        {
            semop(sem_id, (struct sembuf *)&sops[0], 1);
            semop(sem_id, (struct sembuf *)&sops[0], 1);
            sleep(1);
        }
    }
    else
    {
        while (1)
        {
            semop(sem_id, (struct sembuf *)&sops[1], 1);
            semop(sem_id, (struct sembuf *)&sops[0], 1);
            sleep(1);
        }
    }
}