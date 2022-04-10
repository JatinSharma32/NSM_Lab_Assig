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
		ans=ans*(u-(i+1));
	}
	//cout<<"\nU after all is: "<<ans<<"\n";
	return ans;
}

int main(){
	printf("\t Newton Forward Diff Interpolation\n\n");
	int n;
	cin>>n;
	float x[n],y[n][n];
	cout<<"Enter x and y in this format\n: x y\n";
	for(int i=0;i<n;i++){
		cout<<": ";
		cin>>x[i]>>y[i][0];
	}
	cout<<"\nEnter x for which you want y: ";
	float value;
	cin>>value;
	float u=(value-x[0])/(x[1]-x[0]);
	cout<<"\nValue of u is: "<<u<<"\n";
	//this for loop is for columns and started from 1 because 0th column is our inputed y
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			y[j][i]=y[j+1][i-1]-y[j][i-1];
		}
	}
	cout<<"\nForward Diff Table:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			cout<<y[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	float ans=0;
	for(int i=0;i<n;i++){
		ans=ans+((u_calculator(u,i)/faq(i))*y[0][i]);
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


