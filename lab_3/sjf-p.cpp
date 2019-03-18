#include <bits/stdc++.h>
using namespace std;
 


int main()
{
    
    int n ,i,avg1=0,avg2=0;
    printf("enter the number of processes :\n");
    scanf("%d",&n);
    int *pid  = (int*)malloc(sizeof(int)*n); 
    int *at  = (int*)malloc(sizeof(int)*n); 
    int *bt  = (int*)malloc(sizeof(int)*n);
    int *wt  = (int*)malloc(sizeof(int)*n);
    int *tt  = (int*)malloc(sizeof(int)*n);
    int *temp  = (int*)malloc(sizeof(int)*n);
    //vector <pair<int,int> > vect;
    for(int i=0; i<n ; i++){
     pid[i] = i+1;
     printf("enter the arrival time for pid: %d \n:",i);
     scanf("%d",&at[i]);
     printf("enter the burst time for pid: %d \n:",i);     
     scanf("%d",&bt[i]);
     temp[i] = bt[i];
     //vect.push_back(make_pair(at[i],i));    
     
     wt[i] = 0;
     tt[i] = 0;        
   }
   //sort(vect.begin(),vect.end());
 
    
    
 
    int completion = 0, t = 0, min = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
 
    
    while (completion != n) {
 
        
        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (temp[j] < min) && (temp[j] > 0) ){
                min = temp[j];
                shortest = j;
                check = true;
            }
        }
 
        if (check == false) {
            t++;
            continue;
        }
 
        
        temp[shortest]--;
 
        
        min = temp[shortest];
        if (min == 0)
            min = INT_MAX;
 
        
        if (temp[shortest] == 0) {
 
            
            completion++;
 
            
            finish_time = t + 1;
 
            
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
 
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        
        t++;
    }
    
    for (int i = 0; i < n; i++)
        tt[i] = bt[i] + wt[i];
        
        
    
	cout << "Processes "
        << " Burst time "
        << " Waiting time "
        << " Turn around time\n";
 
    
    for (int i = 0; i < n; i++) {
        avg1 = avg1 + wt[i];
        avg2 = avg2 + tt[i];
        cout << "   " << pid[i] << "   "
            << bt[i] << "     " << wt[i]
            << "     " << tt[i] << endl;
    }
 
    cout << "\nAvg1 wt = "
        << (float)avg1 / (float)n;
    cout << "\nAvg2 tt = "
        << (float)avg2 / (float)n;    
   
 
    
    return 0;
}
