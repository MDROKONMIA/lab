#include <bits\stdc++.h>
#define ll long long
using namespace std;

struct Process
{
    int pid, arrivalTime, burstTime, waitingTime, turnArroundTime, completionTime;
};

void findWaitingTime(vector<Process> &process, ll n)
{
    vector<int> reaminingTime;
    for (auto proc : process)
        reaminingTime.push_back(proc.burstTime);
    ll complete = 0, time = 0, shortest = 0, minimum = INT_MAX;
    bool check = false;

    while (complete != n)
    {
        for (ll i = 0; i < n; i++)
        {
            if ((process[i].arrivalTime <= time) && (reaminingTime[i] < minimum) && (reaminingTime[i] > 0))
            {
                shortest = i;
                check = true;
                minimum = reaminingTime[i];
            }
        }
        if(check) cout<<process[shortest].pid;
        if (!check)
        {
            time++;
            continue;
        }
        time += reaminingTime[shortest];
        reaminingTime[shortest] = 0;
        minimum = INT_MAX;
        if (reaminingTime[shortest] == 0)
        {
            complete++;
            check = false;
            process[shortest].completionTime = time;
            process[shortest].waitingTime = process[shortest].completionTime - process[shortest].arrivalTime - process[shortest].burstTime;
            if (process[shortest].waitingTime < 0)
            {
                process[shortest].waitingTime = 0;
            }
        }
    }
}
void findTurnArroundTime(vector<Process> &process, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        process[i].turnArroundTime = process[i].completionTime - process[i].arrivalTime;
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
        cout << "Enter process id, arrival time & burst time: ";
        cin >> process[i].pid >> process[i].arrivalTime >> process[i].burstTime;
        cout << endl;
    }
    findWaitingTime(process, n);
    findTurnArroundTime(process, n);

    ll totalTurnArroundTime = 0, totalWaitingTime = 0;
    cout << endl
         << "Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Complition Time\t Turn Arround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].pid << "\t\t\t\t " << process[i].arrivalTime << "\t\t\t\t " << process[i].burstTime << "\t\t\t\t " << process[i].waitingTime << "\t\t\t\t " << process[i].completionTime << "\t\t\t\t " << process[i].turnArroundTime << endl;
        totalTurnArroundTime += process[i].turnArroundTime;
        totalWaitingTime += process[i].waitingTime;
    }
    cout << endl
         << "Average waiting time: " << (double)totalWaitingTime / n << endl;
    cout << "Average termiante time: " << (double)totalTurnArroundTime / n << endl;

    return 0;
}