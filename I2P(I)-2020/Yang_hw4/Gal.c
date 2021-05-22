#include <stdio.h>

int main(void) {
	double con,tol,gal =0 ,ave,ove,mil;
	tol=0;
	con=0;
	
	printf ("Enter the gallons used (-1 to end):");
	scanf ("%lf",&gal);
	printf ("Enter the miles driven:");
	scanf ("%lf",&mil);
	ave = (mil/gal);
	printf ("The miles / gallon for this tank was %f\n\n",ave);
	
	while (gal != -1){
	    tol=tol+gal;
	    con=con+mil;
	    printf ("Enter the gallons used (-1 to end):");
	    scanf ("%lf",&gal);
	    if (gal!= -1){
	        printf ("Enter the miles driven:");
	        scanf ("%lf",&mil);
	        ave = mil/gal;
	        printf ("The miles / gallon for this tank was %f\n\n",ave);
	        tol=tol+gal;
	        con=con+mil;
	    }
    }
	
	if (gal == -1){
	ove=con/tol;
	printf ("The overall average miles/gallon was %f\n\n",ove);
	}
	return 0;
}