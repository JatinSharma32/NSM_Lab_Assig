#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x){
    return pow(x,3)-(2*x)-5;
}

int main(){
	printf("\t\t\t REGULA FALSI MEATHOD\n\n");
	int a,b;
	float c,d;
	printf("For equation (x^3)-(2*x)-5=0\n");
	printf("Enter two integers giving -ve and +ve values in equation respectively: ");
	scanf("%d %d",&a,&b);
    //Now we got all the 4 variables a, f(a), b and f(b)
    int p;
    printf("How many runs you want: ");
    scanf("%d",&p);
    if(f(a)==0){
    	printf("The root is %d\n.",a);
    	return a;
	}
	else if(f(b)==0){
		printf("The root is %d\n.",b);
		return b;
	}
	else{
		c=a;
		d=b;
		while(p--){
			float x=((c*f(d))-(d*f(c)))/(f(d)-f(c));
			
			//Now finding f(x) is it + or - or 0.
			if(f(x)>=0){
				printf("The root is %d\n.",x);
				return x;
			}
			else if(f(x)<0){
				c=x;
			printf("The x is %.5f with eqn value %.5f\n",x,f(x));
			}
		}
	}
}
