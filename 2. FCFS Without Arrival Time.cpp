#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin >> n;

    int bt[n], ct[n], wt[n], tat[n], rt[n], start[n];

    cout<<"Enter Burst Time of all the processes: ";
    for(int i=0; i<n; i++) {
        cin >> bt[i];
    }

    // First Process
    start[0] = 0;
    ct[0] = start[0] + bt[0];

    // Calculate for the rest
    for(int i=1; i<n; i++){
        start[i] = ct[i-1];     
        ct[i] = start[i] + bt[i];
    }

    float totalWT = 0, totalTAT = 0, totalRT = 0;

    for(int i=0; i<n; i++){
        tat[i] = ct[i];          // AT = 0 , (TAT = CT)
        wt[i]  = tat[i] - bt[i]; // WT = TAT - BT
        rt[i]  = wt[i];          // RT = WT (Cause there is no preemption)

        totalWT  += wt[i];
        totalTAT += tat[i];
        totalRT  += rt[i];
    }

    // PRINT TABLE
    cout << endl<< "---------------------------------------------";
    cout<<endl<<"PNO\t BT\t ST\t CT\t TAT\t WT\t RT\t";
    cout <<"\n---------------------------------------------\n";

    for(int i=0; i<n; i++){
        cout<<"P["<<i+1<<"]\t "<<bt[i]<<"\t "<<start[i]<<"\t ";
        cout<<ct[i]<<"\t "<<tat[i]<<"\t "<<wt[i]<<"\t "<<rt[i]<<endl;
    }

    cout << "---------------------------------------------\n";

    cout<<endl<<"Average Waiting time = "<<totalWT / n <<endl;
    cout<<"Average Turn Around time = "<<totalTAT / n <<endl;
    cout<<"Average Response time = "<<totalRT / n <<endl;

    return 0;
}


//Input

// Enter the number of processes: 5
// Enter Burst Time of all the processes: 8 3 2 1 4

//Output

// ---------------------------------------------
// PNO	 BT	 ST	 CT	 TAT	 WT	 RT	
// ---------------------------------------------
// P[1]	 8	 0	 8	 8	 0	 0
// P[2]	 3	 8	 11	 11	 8	 8
// P[3]	 2	 11	 13	 13	 11	 11
// P[4]	 1	 13	 14	 14	 13	 13
// P[5]	 4	 14	 18	 18	 14	 14
// ---------------------------------------------

// Average Waiting time = 9.2
// Average Turn Around time = 12.8
// Average Response time = 9.2
