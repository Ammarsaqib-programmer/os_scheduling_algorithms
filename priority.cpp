#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter the number of Processes: ";
    cin >> num;
    int id[num], burstTime[num], remainingTime[num], arrivalTime[num], completionTime[num], waitingTime[num], priority[num];
    for (int i = 0; i < num; i++) {
        id[i] = i + 1;
        cout << "Enter Arrival Time for Process " << id[i] << ": ";
        cin >> arrivalTime[i];
        cout << "Enter Burst Time for Process " << id[i] << ": ";
        cin >> burstTime[i];
        cout << "Enter Priority for Process " << id[i] << ": ";
        cin >> priority[i];
        remainingTime[i] = burstTime[i];  
    }
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (priority[i] > priority[j]) {
                int tempPriority = priority[i];
                priority[i] = priority[j];
                priority[j] = tempPriority;

                int tempBurstTime = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = tempBurstTime;

                int tempArrivalTime = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = tempArrivalTime;

                int tempRemainingTime = remainingTime[i];
                remainingTime[i] = remainingTime[j];
                remainingTime[j] = tempRemainingTime;

                int tempId = id[i];
                id[i] = id[j];
                id[j] = tempId;
            }
        }
    }

    int currentTime = 0;  
    for (int i = 0; i < num; i++) {
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }
        
        completionTime[i] = currentTime + burstTime[i];
        waitingTime[i] = completionTime[i] - arrivalTime[i] - burstTime[i];
        currentTime = completionTime[i];  
    }

    cout << "\nProcess ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tCompletion Time\n";
    for (int i = 0; i < num; i++) {
        cout << id[i] << "\t\t"<< arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" << priority[i] << "\t\t" << waitingTime[i] << "\t\t" << completionTime[i] << endl;
    }

    return 0;
}

