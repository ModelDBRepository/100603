/* solout.c */
#include <math.h>
#include <stdio.h>
#include "6erg.h"

#define T_RES 1
#define V_LOW_RES 2.0
#define V_HIGH_RES 0.05

int out_(nr,xold,x,state,n,irtrn)
        int *nr;
        double *xold;
        double *x;
        double *state;
        int *n;
        int *irtrn;
{
static double t_old,yold,yolder,yprev,tprev;
extern double current[C],vset,oinf,iinf,cur_init;
static double oldcurrent[C];
static double oldstate[N],oldiinf,oldoinf;
extern double phi();
int i;
if(*nr==1) 
{
     /* if(1) printf("%f %f\n",*x,current[I_ERG]);*/
     if(G_CLAMP>0) printf("%f %f\n",*x,current[I_ERG]-cur_init); 
     else
     {printf("%f ",*x);
    printf("%f ", state[0]);
if(CA==1) printf("%f ",1e6*state[CA]);
       else printf("%f ",state[1]);
     for(i=2;i<N;i++) printf("%f ", state[i]);
     printf("%f %f ",current[I_ERG],current[I_CAL]);
/*printf("%f ",state[3] + state[5]);*/
     printf("\n");}
yolder=yold;
yold=state[0];
yprev=yold;
t_old=*x;}
else if((fabs(tprev - t_old) > T_RES) || (yold-yolder)/(state[0]-yold)<0
|| fabs(yold-yprev)> V_LOW_RES )
{
     /*if(1) printf("%f %f\n",*x,current[I_ERG]);*/
     if(G_CLAMP>0) printf("%f %f \n",*x,current[I_ERG]-cur_init); 
     else
     {printf("%f ",tprev);
     printf("%f ", oldstate[0]);
if(CA==1) printf("%f ",1e6*oldstate[CA]);
       else printf("%f ",oldstate[1]);
     for(i=2;i<N;i++) printf("%f ", oldstate[i]);
     printf("%f %f ",current[I_ERG],oldcurrent[I_CAL]);
/* printf("%f ",oldstate[3] + oldstate[5]);*/
     printf("\n");}
fflush(stdout);
yprev=yold;
t_old=tprev;}
yolder=yold;
yold=state[0];
tprev=*x;
for(i=0;i<N;i++) oldstate[i]=state[i];
for(i=0;i<C;i++) oldcurrent[i]=current[i];
oldoinf = oinf;
oldiinf = iinf;
}
