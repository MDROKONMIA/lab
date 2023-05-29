#include <bits\stdc++.h>
#define ll long long
using namespace std;

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
    vector<int> processname(n), arrivaltime(n), burtstime(n);
    for (ll i = 0; i < n; i++)
    {
        cout << "Enter the process name, arrival time and burst time: ";
        cin >> processname[i] >> arrivaltime[i] >> burtstime[i];
        cout << endl;
    }
    cout << endl;
    // soring process using there arrival time;
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            if (arrivaltime[i] > arrivaltime[j])
            {
                swap(arrivaltime[i], arrivaltime[j]);
                swap(processname[i], processname[j]);
                swap(burtstime[i], burtstime[j]);
            }
        }
    }

    //
    ll prevFinishTime = arrivaltime[0];
    vector<int> startTime(n), waitingTime(n), turnArroundTime(n), finishTime(n);

    for (ll i = 0; i < n; i++)
    {
        if (i == 0)
        {
            finishTime[i] = arrivaltime[i] + burtstime[i];
            startTime[i] = arrivaltime[i];
        }
        else
        {
            if (arrivaltime[i] >= finishTime[i - 1])
            {
                finishTime[i] = arrivaltime[i] + burtstime[i];
                startTime[i] = arrivaltime[i];
            }
            else
            {
                finishTime[i] = finishTime[i - 1] + burtstime[i];
                startTime[i] = finishTime[i - 1];
            }
        }
        turnArroundTime[i] = finishTime[i] - arrivaltime[i];
        waitingTime[i] = turnArroundTime[i] - burtstime[i];
    }

    ll totalwaitingTime = 0, totalTurnArroundTime = 0;
    cout << "ProcessName     ArrivalTime    BurstTime    starttime   WaitingTime     TarminateTime  FinishTime" << endl;
    for (ll i = 0; i < n; i++)
    {
        cout << "\n\t" << processname[i] << "\t\t\t\t" << arrivaltime[i] << "\t\t\t\t" << burtstime[i] << "\t\t\t" << startTime[i] << "\t\t\t" << waitingTime[i] << "\t\t\t\t" << turnArroundTime[i] << "\t\t\t\t" << finishTime[i] << endl;
        // printf("\n%s\t%6d\t\t%6d\t%6d\t%6d\t%6d", processname[i], arrivaltime[i], burtstime[i], startTime[i], tarminateTime[i], finishTime[i]);
        totalTurnArroundTime += turnArroundTime[i];
        totalwaitingTime += waitingTime[i];
    }
    double avWt = (double)totalwaitingTime / n, avTerminate = (double)totalTurnArroundTime / n;
    cout << endl
         << "Average waiting time: " << avWt << endl;
    cout << "Average termiante time: " << avTerminate << endl;
    return 0;
}