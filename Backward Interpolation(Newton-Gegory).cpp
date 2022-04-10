#include<iostream>
using namespace std;

int faq(int n){
	if(n==0){
		return 1;
	}
	int faq=1;
	for(int i=1;i<=n;i++){
		faq=faq*i;
	}
	//cout<<"\nFactorial of "<<n<<" is "<<faq<<"\n";
	return faq;
	
}

float u_calculator(float u,int n){
	if(n==0){
		return 1;
	}
	n--; //check me out
	float ans=u;
	for(int i=0;i<n;i++){
		ans=ans*(u+(i+1));
	}
	//cout<<"\nU after all is: "<<ans<<"\n";
	return ans;
}

int main(){
	int n;
	cin>>n;
	float x[n],y[n][n];
	cout<<"Enter x and y in this format\n: x y\n";
	for(int i=0;i<n;i++){
		cout<<": ";
		cin>>x[i]>>y[i][0];
	}
	cout<<"\nEnter value of x for which you want to find value of y: ";
	float value;
	cin>>value;
	float u=(value-x[n-1])/(x[1]-x[0]);
	cout<<"\nValue of u is: "<<u<<"\n";
	//this for loop is for columns and started from 1 because 0th column is our inputed y
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			y[j][i]=y[j][i-1]-y[j-1][i-1];
		}
	}
	cout<<"\nBackward Diff Table:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
			cout<<y[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	float ans=0;
	for(int i=0;i<n;i++){
		ans=ans+((u_calculator(u,i)/faq(i))*y[n-1][i]);
	}
	cout<<"Answer is: "<<ans<<"\n";
}

