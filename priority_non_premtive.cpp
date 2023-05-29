#include <bits\stdc++.h>
#define ll long long
using namespace std;

struct Process
{
    int pid, arrivalTime, burstTime, waitingTime, turnAroundTime, completionTime, priority;
};

void findWaitingTime(vector<Process> &process, ll n)
{
    vector<int> remainingTime;
    for (ll i = 0; i < n; i++)
    {
        remainingTime.push_back(process[i].burstTime);
    }

    int complete = 0, time = 0, highpriority = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n)
    {
        for (ll i = 0; i < n; i++)
        {
            if ((process[i].arrivalTime <= time) && (process[i].priority < highpriority) && (remainingTime[i] > 0))
            {
                highpriority = process[i].priority;
                check = true;
                shortest = i;
            }
        }

        if (check)
            cout << process[shortest].pid;
        if (!check)
        {
            time += 1;
            continue;
        }
        time += remainingTime[shortest];
        remainingTime[shortest] = 0;
        highpriority = INT_MAX;
        complete += 1;
        check = false;
        process[shortest].completionTime = time;
        process[shortest].waitingTime = process[shortest].completionTime - process[shortest].arrivalTime - process[shortest].burstTime;
        if (process[shortest].waitingTime < 0)
        {
            process[shortest].waitingTime = 0;
        }
    }
}

void findTurnAroundTime(vector<Process> &process, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
    }
}

int main()
{
#ifndef __rokon
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cout << "Enter the number of process:";
    cin >> n;
    cout << endl;
    vector<Process> process(n);
    for (ll i = 0; i < n; i++)
    {
        cout << "Enter process id, arrival time , burst time & priority: ";
        cin >> process[i].pid >> process[i].arrivalTime >> process[i].burstTime >> process[i].priority;
        cout << endl;
    }

    findWaitingTime(process, n);
    findTurnAroundTime(process, n);

    ll totalTurnAroundTime = 0, totalWaitingTime = 0;
    cout << endl
         << "Process ID\t Arrival Time\t Burst Time\t Priority\t Waiting Time\t Complition Time\t Turn Arround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].pid << "\t\t\t\t " << process[i].arrivalTime << "\t\t\t\t " << process[i].burstTime << "\t\t\t\t " << process[i].priority << "\t\t\t\t " << process[i].waitingTime << "\t\t\t\t " << process[i].completionTime << "\t\t\t\t " << process[i].turnAroundTime << endl;
        totalTurnAroundTime += process[i].turnAroundTime;
        totalWaitingTime += process[i].waitingTime;
    }
    cout << endl
         << "Average waiting time: " << (double)totalWaitingTime / n << endl;
    cout << "Average termiante time: " << (double)totalTurnAroundTime / n << endl;

    return 0;
}