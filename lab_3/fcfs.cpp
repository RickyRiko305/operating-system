#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


int main(){
   int n,i,avg1=0,avg2=0;
   vector <pair<int,int> > vect;
   printf("enter the no. of processes\n");
   scanf("%d",&n);
   int *pid  = (int*)malloc(sizeof(int)*n); 
   int *at  = (int*)malloc(sizeof(int)*n); 
   int *bt  = (int*)malloc(sizeof(int)*n);
   int *wt  = (int*)malloc(sizeof(int)*n);
   int *tt  = (int*)malloc(sizeof(int)*n);	
   
   for(i=1; i<=n ; i++){
     pid[i] = i;
     printf("enter the arrival time for pid: %d \n:",i);
     scanf("%d",&at[i]);
     printf("enter the burst time for pid: %d \n:",i);     
     scanf("%d",&bt[i]);
     vect.push_back(make_pair(at[i],bt[i]));    
     
     wt[i] = 0;
     tt[i] = 0;    
      
   }
   sort(vect.begin(), vect.end());
   
   for(i=1; i<=n ; i++){
     if(i==1){
       wt[i] = 0;
       tt[i] = vect[i-1].second;
       //sum = vect[i-1].first + bt[vect[i-1].second];
     }
     else{
        if(vect[i-1].first > (tt[i-1] + vect[i-2].first)){
          wt[i] = 0;
          tt[i] = wt[i] + vect[i-1].second;//bt[vect[i-1].second];   
          //sum += bt[vect[i-1].second];
        }
        else{
          wt[i] = vect[i-2].first+ tt[i-1] - vect[i-1].first; ///at[i];
          tt[i] = wt[i] +vect[i-1].second;
        }
       //wt[i] = wt[i-1] + bt[i-1];
       //tt[i] = tt[i-1] + bt[i];
        
      }
   }
   printf("pid     burst-time   wait-time  t-time\n");
   for(i=1; i<=n; i++){
      printf("%d      %d       %d       %d\n",pid[i],vect[i-1].second,wt[i],tt[i]); 

      avg1 += wt[i];
      avg2 += tt[i]; 
   }

   double a1,a2;
   
   a1 = (double)avg1/n;
   a2 = (double)avg2/n;

   printf("\n\n avg1 = %f   avg2 = %f\n",a1,a2); 

   
  



 return 0;
}
