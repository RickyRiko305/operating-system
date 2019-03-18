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
   
   for(i=0; i<n ; i++){
     pid[i] = i+1;
     printf("enter the arrival time for pid: %d \n:",i);
     scanf("%d",&at[i]);
     printf("enter the burst time for pid: %d \n:",i);     
     scanf("%d",&bt[i]);
     vect.push_back(make_pair(at[i],i));    // making the pair of arrival time and index
     
     wt[i] = 0;
     tt[i] = 0;    
      
   }
   sort(vect.begin(), vect.end());   //sorting the according to arrival;
   

    int completion=0,k=0; //completion is the time for total process time passed,,,, k is the index for the waiting time
    vector <pair<int,int> > q;     ///making pair of burst time and the index , the order of pairing is according to the vect(pair) which we sorted
    
    
    ///////////////////////////////////////////////computing the first value of the pair starts
    
    q.push_back(make_pair(bt[vect[0].second],vect[0].second));// = bt[vect[0].second];
    int j=1;
    printf("pid       bt      wt       t-t\n");
    while(vect[0].first >= vect[j].first){
    	
    	//q[j] = bt[vect[j].second];
    	q.push_back(make_pair(bt[vect[j].second],vect[j].second));
    	j++;
	}
	sort(q.begin(), q.end());
	printf("%d       ",pid[q[0].second]);
	printf("%d       ",bt[q[0].second]);
	printf("%d       ",wt[k]);  ////waiting time for this is zero 
	tt[q[0].first] = wt[k++] + bt[q[0].second];
	avg2 += tt[q[0].first];     ////avg2 summation
	printf("%d       \n",tt[q[0].first]);
	completion = at[q[0].second] + bt[q[0].second];
	q.erase(q.begin(), q.begin()+1);
	///////////////////////////////////////////////computing the first value of the pair ends
	
	
	
	///repeat the task for remaining while comparing with completion time
	while(( j<vect.size() ) || (q.size()>0)){ // runs while elements are present in arrary (vect) or in (q);
		while(completion >= vect[j].first){
    	
    	//q[j] = bt[vect[j].second];
    		q.push_back(make_pair(bt[vect[j].second],vect[j].second));
    		j++;
		}
		sort(q.begin(), q.end());
		printf("%d       ",pid[q[0].second]);
		printf("%d       ",bt[q[0].second]);
		wt[k] = max(0,completion - at[q[0].second]);  //waiting time
		printf("%d       ",wt[k]);      
		tt[q[0].first] = wt[k++] + bt[q[0].second];
		avg2 += tt[q[0].first];  ////avg2 summation
		printf("%d       \n",tt[q[0].first]);
		completion += bt[q[0].second];  //update completion time 
		q.erase(q.begin(), q.begin()+1);
	}
	
    
  // printf("pid     burst-time   wait-time  t-time\n");
   for(i=0; i<n; i++){
      //printf("%d      %d       %d       %d\n",pid[i],vect[i-1].second,wt[i],tt[i]); 

      avg1 += wt[i];
      //avg2 += tt[i]; 
   }

   double a1,a2;
   
   a1 = (double)avg1/n;
   a2 = (double)avg2/n;

   printf("\n\n avg1 = %f   avg2 = %f\n",a1,a2); 


 return 0;
}
