// This function generates 'x' with probability px/100, 'y' with
// probability py/100 and 'z' with probability pz/100:
// Assumption: px + py + pz = 100 where px, py and pz lie
// between 0 to 100
#include<stdio.h>
#include<stdlib.h>
int random(int x, int y, int z, int px, int py, int pz)
{	
		// Generate a number from 1 to 100
		int r = rand()%100;
	
		// r is smaller than px with probability px/100
		if (r <= px)
			return x;

		// r is greater than px and smaller than or equal to px+py
		// with probability py/100
		if (r <= (px+py))
			return y;

		// r is greater than px+py and smaller than or equal to 100
		// with probability pz/100
		else
			return z;
}
int main()
{
    int x=40,           y=25        ,       z=35,
        px=0.4   ,   py=0.25   ,       pz=0.35;
    int w= random(x,y,z,px,py,pz);
    printf("%d",w);
    return 0;
}
