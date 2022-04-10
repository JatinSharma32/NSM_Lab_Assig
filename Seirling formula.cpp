#include<iostream>
using namespace std;
int l=0;
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

float u_calculator(float u,int n,int last){
	if(n==0){
		return 1;
	}
	else if(n==1){
		return u;
	}
	float ans;
	if(n%2==0){
		ans=last*u;
	}
	else{
		ans=(last/u)*((u*u)-(l*l));
		l++;
	}
	//cout<<"\nU after all is: "<<ans<<"\n";
	return ans;
}

float u_calculator2(float u,int n){
	if(n==0){
		return 1;
	}
	n--; //check me out
	float ans=u;
	for(int i=0;i<n;i++){
		ans=ans*(u-(i+1));
	}
	//cout<<"\nU after all is: "<<ans<<"\n";
	return ans;
}

int main(){
	int n;
	cout<<"How many elements are there: ";
	cin>>n;
	float x[n],y[n][n];
	cout<<"\nEnter value of x for which you want to find value of y: ";
	float value;
	cin>>value;
	int min=value,y0;
	cout<<"\nEnter x and y in this format\n: x y\n";
	for(int i=0;i<n;i++){
		cout<<": ";
		cin>>x[i]>>y[i][0];
		if(value-x[i]<min&&value-x[i]>=0){
			min=value-x[i];
			y0=i;
		}
	}
	
	float u=(value-x[y0])/(x[1]-x[0]);
	cout<<"\nValue of u and y0 is: "<<u<<" "<<y0<<"\n";
	//this for loop is for columns and started from 1 because 0th column is our inputed y
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			y[j][i]=y[j+1][i-1]-y[j][i-1];
		}
	}
	float arror[n];
	cout<<"\nForward Diff Table:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(i%2==0){
				arror[i]=y[i][y0];
			}
			else{
				arror[i]=(y[i][y0]+y[i][y0-1])/2;
				y0--;
			}
			cout<<y[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";
	float ans=0;
	int last=0;
	for(int i=0;i<n;i++){
		ans=ans+((u_calculator(u,i,last)/faq(i))*arror[i]);
		last=(u_calculator(u,i,last));
	}
	cout<<"Answer is: "<<ans<<"\n";
	ans=0;
	for(int i=0;i<n;i++){
		ans=ans+((u_calculator2(u,i)/faq(i))*y[0][i]);
	}
	cout<<"Answer is: "<<ans<<"\n";
}


	//This is self trial code just to understand logic:
	
	/*for(int i=0;i<n;i++){
		cout<<"\n"<<i<<"\n";
		for(int j=i;j<n-1;j++){
			if(i==0){
				yo[j]=y[j+1]-y[j];
				cout<<yo[j]<<" ";
				continue;
			}
			yo[j]=yo[j+1]-yo[j];
			cout<<yo[j]<<" ";
		}
	}*/
	/*int a=y[0],b=y[1],yo[n];
	leading_terms[0]=a;
	int ror;
	for(int i=0;i<n;i++){
		for(int j=0/*add this +1 ;j<n-i+1;j++){
			if(j==0){
				ror=b-a;
			}
			//yo[j]=b-a;
			//cout<<b<<"-"<<a<<" "<<b-a<<"\n";
			b=y[i+1];
			a=y[i];
		}
		cout<<ror<<" ";
		/*for(int j=0/*add this +1 ;j<n-i;j++){
			cout<<yo[j]<<" ";
		}
	}*/


