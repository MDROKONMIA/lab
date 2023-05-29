#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Process
{
    int pid, arrivalTime, burstTime, waitingTime, compelitionTime, turnAroundTime;
};

void findWaitingTime(vector<Process> &process, ll n)
{
    vector<int> remainingTime;
    for (auto p : process)
    {
        remainingTime.push_back(p.burstTime);
    }
    ll complete = 0, time = 0, minArrivalTime = INT_MAX, shortes = 0;
    bool check = false;
    while (complete != n)
    {
        for (ll i = 0; i < n; i++)
        {
            if ((process[0].arrivalTime <= time) && (process[i].arrivalTime < minArrivalTime) && (remainingTime[i] > 0))
            {
                shortes = i;
                check = true;
                minArrivalTime = process[i].arrivalTime;
            }
        }

        if (!check)
        {
            time += 1;
            continue;
        }
        minArrivalTime = INT_MAX;
        time += remainingTime[shortes];
        remainingTime[shortes] = 0;
        process[shortes].compelitionTime = time;
        process[shortes].waitingTime = process[shortes].compelitionTime - process[shortes].burstTime - process[shortes].arrivalTime;
        if (process[shortes].waitingTime < 0)
        {
            process[shortes].waitingTime = 0;
        }
        complete += 1;
    }
}
void findTurnAroundTime(vector<Process> &process, ll n){
    for(ll i=0; i<n; i++){
        process[i].turnAroundTime=process[i].compelitionTime-process[i].arrivalTime;
    }
}

int main()
{
    ll n;
    cout << "Enter the number of process: ";
    cin >> n;
    vector<Process> process(n);
    for (ll i = 0; i < n; i++)
    {
        cout << "Enter the process name, arrival time & burst time:";
        cin >> process[i].pid >> process[i].arrivalTime >> process[i].burstTime;
    }

    findWaitingTime(process, n);
    findTurnAroundTime(process, n);

    ll totalTurnAroundTime = 0, totalWaitingTime = 0;
    cout << endl
         << "Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Complition Time\t Turn Arround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].pid << "\t\t\t\t " << process[i].arrivalTime << "\t\t\t\t " << process[i].burstTime<< "\t\t\t\t " << process[i].waitingTime << "\t\t\t\t " << process[i].compelitionTime << "\t\t\t\t " << process[i].turnAroundTime << endl;
        totalTurnAroundTime += process[i].turnAroundTime;
        totalWaitingTime += process[i].waitingTime;
    }
    cout << endl
         << "Average waiting time: " << (double)totalWaitingTime / n << endl;
    cout << "Average termiante time: " << (double)totalTurnAroundTime / n << endl;

    return 0;
}