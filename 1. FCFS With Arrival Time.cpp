#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin >> n;
    int at[n], bt[n], ct[n],wt[n],tat[n],rt[n],start[n];
    
    cout<<"Enter Arrival Time of all the processes: ";
        for(int i=0; i<n; i++) {
        cin >> at[i];
    }

    cout<<"Enter Burst Time of all the processes: ";
        for(int i=0; i<n; i++) {
        cin >> bt[i];
    }

    //First Processes
    start[0] = at[0];
    ct[0] = start[0]+ bt[0];

    //Calculate for the rest
    for(int i=1; i<n; i++){
        if(at[i] > ct[i-1])
            start[i] = at[i];
        else
            start[i] = ct[i-1];
        ct[i] = start[i] + bt[i];
    }

    float totalWT =0, totalTAT = 0, totalRT = 0;

    for(int i=0; i<n; i++){
        tat[i] = ct[i]-at[i];
        wt[i]  = tat[i]-bt[i];
        rt[i]  = start[i]- at[i];

        totalWT  += wt[i];
        totalTAT += tat[i];
        totalRT  += rt[i];
    }

    //PRINT TABLE
    cout << endl<< "---------------------------------------------";
    cout<<endl<<"PNO\t AT\t BT\t ST\t CT\t TAT\t WT\t RT\t";
        cout <<"\n---------------------------------------------\n";
    for(int i=0; i<n; i++){
        cout<<"P["<<i+1<<"]\t "<<at[i]<<"\t "<<bt[i]<<"\t "<<start[i]<<"\t ";
        cout<<ct[i]<<"\t "<<tat[i]<<"\t "<<wt[i]<<"\t "<<rt[i]<<endl;
    }
    cout << "---------------------------------------------\n";

    cout<<endl<<endl<<"Average Waiting time = "<<totalWT / n <<endl;

    cout<<"Average Turn Around time = "<<totalTAT / n <<endl;

    cout<<"Average Response time = "<<totalRT / n <<endl;

return 0;
}


//Input

// Enter the number of processes: 4
// Enter Arrival Time of all the processes: 0 1 5 6
// Enter Burst Time of all the processes: 2 2 3 4

//Output

// ---------------------------------------------
// PNO	 AT	 BT	 ST	 CT	 TAT	 WT	 RT	
// ---------------------------------------------
// P[1]	 0	 2	 0	 2	 2	 0	 0
// P[2]	 1	 2	 2	 4	 3	 1	 1
// P[3]	 5	 3	 5	 8	 3	 0	 0
// P[4]	 6	 4	 8	 12	 6	 2	 2
// ---------------------------------------------

// Average Waiting time = 0.75
// Average Turn Around time = 3.5
// Average Response time = 0.75
