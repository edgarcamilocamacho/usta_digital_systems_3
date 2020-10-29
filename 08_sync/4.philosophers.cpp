#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define num_phi  5

void *rutine_philosopher(void *id);
enum State {THINKING, HUNGRY, EATING};
sem_t palillo[5];
State state[num_phi];

int main(int arcg, char** argv){
  int *id_phi = new int[num_phi];
  srand (time(NULL));
  pthread_t philosopher[num_phi];
  for(int i=0; i<5; i++)
    sem_init(&palillo[i], 0, 1);
  for(int i=0; i<num_phi; i++){
    id_phi[i] = i;
    pthread_create(&philosopher[i],NULL,rutine_philosopher,(void*)&id_phi[i]);
    state[i] = THINKING;
  }
  while(1){
    for(int i=0; i<num_phi; i++){
      switch (state[i]) {
        case THINKING: cout << "THINKING" << "    "; break;
        case HUNGRY: cout << "HUNGRY" << "    "; break;
        case EATING: cout << "EATING" << "    "; break;
      }

    }
    cout << endl;
    usleep(1000000*1);
  }

}

void *rutine_philosopher(void *id){
  int self = *(int *)id;
  int seg;
  //cout << "philosopher " << self << " created." << endl;
  while(1){
    state[self] = HUNGRY;
    sem_wait(&palillo[self]);
    sem_wait(&palillo[(self+1)%num_phi]);
    state[self] = EATING;
    seg = rand() % 10 + 3;
    usleep(1000000*seg);
    sem_post(&palillo[self]);
    sem_post(&palillo[(self+1)%num_phi]);
    state[self] = THINKING;
    seg = rand() % 10 + 3;
    usleep(1000000*seg);
  }
}
