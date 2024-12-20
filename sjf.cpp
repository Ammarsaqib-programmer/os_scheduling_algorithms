#include<iostream>
using namespace std;

int main() {
    int num; 
    int totalWaitingTime = 0, totalThroughputTime = 0; 
    float averageWaitingTime;

    cout << "Enter the number of Processes: ";
    cin >> num;

    int burstTime[num], waitingTime[num], completionTime[num], process[num], Throughput = 0;

    for(int i = 0; i < num; i++) {
        cout << "Enter burst time for process " <<i+1<< ": ";
        cin >> burstTime[i];
        process[i] = i + 1; 
    }
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (burstTime[i] > burstTime[j]) {
                swap(burstTime[i], burstTime[j]);
                swap(process[i], process[j]);
            }
        }
    }
    waitingTime[0] = 0; 

    for(int i = 1; i < num; i++) {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
        totalWaitingTime += waitingTime[i];
    }

    for (int i = 0; i < num; i++) {
        completionTime[i] = waitingTime[i] + burstTime[i];
        totalThroughputTime += completionTime[i];
    }

    Throughput = completionTime[num-1];

    averageWaitingTime = (float)totalWaitingTime / num;

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tCompletion Time\n";
    for(int i = 0; i < num; i++) {
        cout << process[i]<<"\t\t"<< burstTime[i]<< "\t\t"<< waitingTime[i] <<"\t\t"<<completionTime[i] << endl;
    }

    cout << "\nThroughput time of all Processes: " << Throughput << endl;
    cout << "Average Waiting Time: " << averageWaitingTime << endl;

    return 0;
}

