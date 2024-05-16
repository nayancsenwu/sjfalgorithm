#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int burstTime; 
    int waitingTime; 
    int turnAroundTime; 
};

bool compareBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

void findWaitingTime(Process processes[], int n) {
    processes[0].waitingTime = 0; 

   
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
    }
}


void findTurnAroundTime(Process processes[], int n) {
   
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}


void findAverageTime(Process processes[], int n) {
    findWaitingTime(processes, n);
    findTurnAroundTime(processes, n);

    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    cout << "Processes  Burst Time  Waiting Time  Turnaround Time\n";


    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
        cout << "   " << processes[i].pid << "\t\t" << processes[i].burstTime << "\t    " << processes[i].waitingTime << "\t\t    " << processes[i].turnAroundTime << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)totalWaitingTime / (float)n;
    cout << "\nAverage Turnaround Time = " << (float)totalTurnAroundTime / (float)n << endl;
}

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        cout << "Enter burst time for process " << processes[i].pid << ": ";
        cin >> processes[i].burstTime;
    }
    sort(processes, processes + n, compareBurstTime);

    findAverageTime(processes, n);

    return 0;
}
