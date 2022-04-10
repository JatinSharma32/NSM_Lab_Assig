#include<stdio.h>
#include<math.h>

float f(float x){
	return pow(x,3)-(6*x)+4;
}

float f_(float x){
	return (3*pow(x,2))-6;
}

int main(){
	printf("\t\tNEWTON RAPHSON MEATHOD\n\n");
	float a,b,x;
	printf("Enter any integers giving -ve and +ve value in equation: ");
	scanf("%f %f",&a,&b);
	if(f(a)>f(b)){
		x=b;
	}
	else if(f(a)<f(b)){
		x=a;
	}
	printf("How many runs you want: ");
	int c;
	scanf("%d",&c);
	if(f(x)==0){
		printf("The root is %f with f(%f) as %f\n",x,x,f(x));
	}
	else{
		float past=x;
		for(int i=0;i<c;i++){
			float x=x-(f(x)/f_(x));
			// Niche vale if mai ye "||f(x)<0.000009" add kerne pe or...
			if(f(x)==0||f(x)<0.0000009){
				printf("The root is %f with f(%f) as %f\n",x,x,f(x));
				return x;
			}
			//...ye niche vala pura else if block hatane pe program chal gaya.
			/*else if(past-x<0.00009){
				printf("\nPrinting:\n%f-(%f/%f)=%f\nThe root is %f with f(%f) as %f\n",past,f(past),f_(past),x,x,x,f(x));
			}*/
			printf("The root is %f with f(%f) as %f\n",x,x,f(x));
			past=x;
		}
	}
}
