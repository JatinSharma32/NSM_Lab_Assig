#include<stdio.h>
#include<math.h>

float g(float n){
	return pow(2.71828182846,-n);
}

float f(float n){
	return pow(2.71828182846,-n)-n;
}

int main(){
	printf("\t\tIteration Meathod\n\n");
	float a,b,x;
	printf("Enter two integers giving +ve and -ve value in equation: ");
	scanf("%f %f",&a,&b);
	printf("How many runs you want: ");
	int c;
	scanf("%d",&c);
	if(f(a)>f(b)){
		x=b;
	}
	else if(f(a)<f(b)){
		x=a;
	}
	if(f(x)==0){
		printf("The root is %f for f(%f) as %f\n",x,x,f(x));
		return x;
	}
	else{
		while(c--){
			float x=g(x);
			if(f(x)==0||(f(x)<0.00009&&f(x)>-0.00009)){
				printf("The root is %f for f(%f) as %f\n",x,x,f(x));
				return x;
			}
			printf("The root is %f for f(%f) as %f\n",x,x,f(x));
		}
	}
}

