#include<iostream>
#include<cmath>
using namespace std;

float f(float x){
	//Enter your function here
	return log(x);
}

int main(){
	float U_limit,L_limit;
	int n;
	cout<<"Enter the upper limit, lower limit and no of intervals: ";
	cin>>U_limit>>L_limit>>n;
	float arr[n+1][2];
	float h=(U_limit-L_limit)*1.0/n;
	printf("\nH is: %f\n--------------\n",h);
	printf("\nx\t  y\n");
	for(int i=0;i<=n;i++){
		if(i==0){
			arr[i][0]=L_limit;
			arr[i][1]=f(arr[i][0]);
			printf("\n%f %f",arr[i][0],arr[i][1]);
			continue;
		}
		arr[i][0]=arr[i-1][0]+h;
		arr[i][1]=f(arr[i][0]);
		printf("\n%f %f",arr[i][0],arr[i][1]);
	}
	//---------------
	float sum=(arr[0][1]+arr[n][1])/2;
	for(int i=1;i<n;i++){
		sum=sum+arr[i][1];
	}
	sum=(sum*h);
	printf("\nAnswer is: %f",sum);
}

