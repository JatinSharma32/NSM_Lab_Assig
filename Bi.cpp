#include<stdio.h>
#include<math.h>

float eqcal(float x){
	//Equation can be changed
	return pow(x,3)-(9*x)+1;
	
}

int main()
{
	printf("BISECTION MEATHOD\n\n");
	
	float neg,pos;
	float root;
	printf("Enter any 2 integers giving -ve and +ve values in equation respectivly: \n");
	scanf("%f %f",&neg,&pos);
	float a,b;
	float c;
	printf("Enter how many times you want to run this loop: \n");
	scanf("%f",&c);
	if(eqcal(neg)==0){
		root=neg;
		printf("The root is %f\n",root);
	}
	else if(eqcal(pos)==0){
		root=pos;
	    printf("The root is %.2f\n",root);
	}
	else{
		a=pos;
		b=neg;
		printf("Entering in the loop...\n");
		for(int i=0;i<c;i++){
			float mid;
			mid=(a+b)/2;
			if(eqcal(mid)==0){
				printf("The root is %.8f with eqn value as %.3f and a,b as %f %f\n",mid,eqcal(mid),a,b);
				return mid;
			}
			else if(eqcal(mid)>0){
				a=mid;
			}
			else if(eqcal(mid)<0){
				b=mid;
			}
			printf("The root is %.8f with eqn value as %.3f and a,b as %f %f\n",mid,eqcal(mid),a,b);		
		}
	}
	printf("\n\n");

}
