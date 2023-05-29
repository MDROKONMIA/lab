#include <bits\stdc++.h>
#define ll long long
using namespace std;

struct Process
{
    int pid, arrivalTime, burstTime, waitingTime, turnAroundTime, completionTime;
};

void findWaitingTime(vector<Process> &process, ll n, ll timeQuantum)
{
    vector<int> remainingTime;
    for (ll i = 0; i < n; i++)
    {
        remainingTime.push_back(process[i].burstTime);
    }

    ll complete = 0, time = 0;

    while (complete != n)
    {
        bool check=false;
        for (ll i = 0; i < n; i++)
        {
            if (process[i].arrivalTime <= time && remainingTime[i] > 0)
            {
                check=true;
                if (remainingTime[i] <= timeQuantum)
                {
                    complete++;
                    cout<<"("<<time<<")"<<process[i].pid<<"->"<<remainingTime[i]<<"|";
                    time += remainingTime[i];
                    remainingTime[i]=0;
                    process[i].completionTime = time;
                    process[i].waitingTime = process[i].completionTime - process[i].arrivalTime - process[i].burstTime;
                }
                else
                {
                    remainingTime[i] -= timeQuantum;
                    cout << "(" << time << ")" << process[i].pid << "->" << timeQuantum << "|";
                    time+=timeQuantum;

                }
            }
        }
        if(check==false)time++;
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
    ll n, tq;
    cout << "Enter the number of process & time quantam:";
    cin >> n >> tq;
    cout << endl;
    vector<Process> process(n);
    for (ll i = 0; i < n; i++)
    {
        cout << "Enter process id, arrival time & burst time: ";
        cin >> process[i].pid >> process[i].arrivalTime >> process[i].burstTime;
        cout << endl;
    }

    findWaitingTime(process, n,tq);
    findTurnAroundTime(process, n);

    ll totalTurnAroundTime = 0, totalWaitingTime = 0;
    cout << endl
         << "Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Complition Time\t Turn Arround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].pid << "\t\t\t\t " << process[i].arrivalTime << "\t\t\t\t " << process[i].burstTime<< "\t\t\t\t " << process[i].waitingTime << "\t\t\t\t " << process[i].completionTime << "\t\t\t\t " << process[i].turnAroundTime << endl;
        totalTurnAroundTime += process[i].turnAroundTime;
        totalWaitingTime += process[i].waitingTime;
    }
    cout << endl
         << "Average waiting time: " << (double)totalWaitingTime / n << endl;
    cout << "Average termiante time: " << (double)totalTurnAroundTime / n << endl;

    return 0;
}