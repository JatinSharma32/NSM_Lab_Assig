#include<iostream>
using namespace std;

float fx(float y,float z){
	return (85-(6*y)+z)/27;
}

float fy(float x,float z){
	return (72-(6*x)-(2*z))/15;
}

float fz(float x,float y){
	return (110-x-y)/54;
}

float mode(float x,float y){
	if(x-y<0){
		return (-1)*(x-y);
	}
	return x-y;
}

int main(){
	float x=0,y=0,z=0,pastx=0,pasty=0,pastz=0;
	int i=0;
	while(1){
		x=fx(pasty,pastz);
		y=fy(x,pastz);
		z=fz(x,y);
		printf("This is %dth ittration\n",i+1);
		printf("x%d=(85-(6*%f)+%f)/27=%f\n",i+1,pasty,pastz,x);
		printf("y%d=(72-(6*%f)-(2*%f))/15=%f\n",i+1,x,pastz,y);
		printf("z%d=(110-%f-%f)/54=%f\n\n",i+1,x,y,z);
		float diff_x=mode(x,pastx),diff_y=mode(y,pasty),diff_z=mode(z,pastz);
		pastx=x;
		pasty=y;
		pastz=z;
		if((diff_x<.001)&&(diff_y<.001)&&(diff_z<.001)){
			break;
		}
		i++;
	}
	printf("\nThe values of x, y and z are: %f, %f and %f\n",x,y,z);
}

