#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter the number of Processes: ";
    cin >> num;

    int arrivalTime[num], burstTime[num], remainingTime[num], waitingTime[num], turnaroundTime[num];
    int completionTime[num], process[num], totalTime = 0, completed = 0;
    int shortest = 0, minRemainingTime = INT_MAX;
    bool found = false;
    for (int i = 0; i < num; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrivalTime[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i]; 
        process[i] = i + 1;
    }

    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    while (completed != num) {
        for (int i = 0; i < num; i++) {
            if (arrivalTime[i] <= totalTime && remainingTime[i] < minRemainingTime && remainingTime[i] > 0) {
                shortest = i;
                minRemainingTime = remainingTime[i];
                found = true;
            }
        }

        if (!found) {
            totalTime++;
            continue;
        }

        remainingTime[shortest]--;
        minRemainingTime = remainingTime[shortest];
        if (minRemainingTime == 0) minRemainingTime = INT_MAX;

        if (remainingTime[shortest] == 0) {
            completed++;
            found = false;

            completionTime[shortest] = totalTime + 1; 
            turnaroundTime[shortest] = completionTime[shortest] - arrivalTime[shortest]; 
            waitingTime[shortest] = turnaroundTime[shortest] - burstTime[shortest]; 
             totalWaitingTime += waitingTime[shortest];
            totalTurnaroundTime += turnaroundTime[shortest];
        }

        totalTime++;
    }

    float avgWaitingTime = (float)totalWaitingTime / num;
    float avgTurnaroundTime = (float)totalTurnaroundTime / num;
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < num; i++) {
        cout << process[i] << "\t\t" << arrivalTime[i] << "\t\t" << burstTime[i]
             << "\t\t" << completionTime[i] << "\t\t" << waitingTime[i]
             << "\t\t" << turnaroundTime[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}


