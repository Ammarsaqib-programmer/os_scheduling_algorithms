#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int totalProcesses, timeSlice;
    cout << "Enter the total number of processes: ";
    cin >> totalProcesses;

    int processID[totalProcesses], burstDuration[totalProcesses], pendingTime[totalProcesses], arrival[totalProcesses];
    int completion[totalProcesses], waiting[totalProcesses];

    // Input for each process
    for (int i = 0; i < totalProcesses; i++) {
        processID[i] = i + 1;
        cout << "Enter Arrival Time for Process " << processID[i] << ": ";
        cin >> arrival[i];
        cout << "Enter Burst Time for Process " << processID[i] << ": ";
        cin >> burstDuration[i];
        pendingTime[i] = burstDuration[i]; // Initialize remaining burst time
    }

    cout << "Enter Time Quantum: ";
    cin >> timeSlice;

    int clockTime = 0; // Track the system time
    int finishedProcesses = 0;
    bool isDone = false;

    // Execute processes in round-robin fashion
    while (finishedProcesses < totalProcesses) {
        isDone = true;

        for (int i = 0; i < totalProcesses; i++) {
            if (arrival[i] <= clockTime && pendingTime[i] > 0) {
                isDone = false;

                // Temporary variable to hold the time slice for each process
                int executionTime = min(pendingTime[i], timeSlice);

                pendingTime[i] -= executionTime;  // Decrease remaining time
                clockTime += executionTime;       // Increment clock time

                // Check if the process has completed
                if (pendingTime[i] == 0) {
                    completion[i] = clockTime;
                    waiting[i] = completion[i] - arrival[i] - burstDuration[i];
                    if (waiting[i] < 0) waiting[i] = 0; // Ensure non-negative waiting time
                    finishedProcesses++; // Increment number of completed processes
                }

                cout << "Executing Process " << processID[i] << " from time " 
                     << clockTime - executionTime << " to " << clockTime << endl;
            }
        }

        if (isDone) {
            clockTime++;
        }
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\n";
    int totalWaitingTime = 0;
    for (int i = 0; i < totalProcesses; i++) {
        cout << processID[i] << "\t\t" << arrival[i] << "\t\t" << burstDuration[i] << "\t\t" 
             << waiting[i] << "\t\t" << completion[i] << endl;
        totalWaitingTime += waiting[i];
    }

    float avgWaitingTime = (float)totalWaitingTime / totalProcesses;
    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;

    return 0;
}

