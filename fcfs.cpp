#include <iostream>
using namespace std;
int main() {
    int num; 
    int totalWaitingTime = 0, totalTurnaroundTime = 0; 
    float averageWaitingTime, averageTurnaroundTime;
    cout << "Enter the number of Processes: ";
    cin >> num;
    int burstTime[num], waitingTime[num], turnaroundTime[num], Throughput = 0;
    for (int i = 0; i < num; i++) {
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> burstTime[i];
        Throughput += burstTime[i]; 
    }
    waitingTime[0] = 0; 
    for (int i = 1; i < num; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        totalWaitingTime += waitingTime[i]; 
    }
    for (int i = 0; i < num; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    cout << "\nProcesses\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < num; i++) {
        cout << i + 1 << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    averageWaitingTime = (float)totalWaitingTime / num;
    averageTurnaroundTime = (float)totalTurnaroundTime / num;

    cout << "\nTotal Throughput of all Processes: " << Throughput << endl;
    cout << "Average Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;

    return 0;
}

