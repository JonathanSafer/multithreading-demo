/* This script spawns X threads. Each thread has a unique incrementing identifier (0-X). The main function waits for 10 seconds and then signals for the spawned threads to begin. 
Each thread gets the value of a shared number, increments the shared number, and prints the retrieved value and its unique ID number. Each thread performs this action Z times.
X and Z are command line arguments. */

#include<thread>
#include<iostream>
#include <unistd.h>
#include <vector>

using namespace std;

int sharedNum = 0;
mutex sharedNumMutex;

void incrementSharedNum(int threadNum);
void incrementer(int threadNum, int Z);

int main(int argc, char *argv[]){
    //setup X and Z
    int X = atoi(argv[1]);
    int Z = atoi(argv[2]);

    //sleep for 10 seconds
    cout << "Sleeping for 10 seconds..." << endl;
    sleep(10);

    //declare vector of X threads
    vector<thread> threads(Z);

    //populate thread vector
    for(int i = 0; i < X; i++){
        threads[i] = thread(incrementer, i, Z);
    }

    //iterate thru thread vector with .join() to ensure that all threads finish
    for(int i = 0; i < X; i++){
        threads[i].join();
    }
    return 0;
}

void incrementSharedNum(int threadNum){
    //acquire lock
    sharedNumMutex.lock();

    cout << "Thread #" << threadNum << " value: " << sharedNum << endl;

    sharedNum++;

    //release lock
    sharedNumMutex.unlock();
}

void incrementer(int threadNum, int Z){
    //increment shared number Z times
    for(int i = 0; i < Z; i++){
        incrementSharedNum(threadNum);
    }
}

