#include <math.h>
#include <stdio.h>
#include "6erg.h"


double efun(z) 
double z;
{
	if (fabs(z) < 1e-4) {
	return( 1 - z/2);
	}else{
		return( z/(exp(z) - 1));
	}
}
 
double gold(v, ci, co,z) 
double v,ci,co,z;
{
	double arg, eci, eco;
	arg = (0.001)*z*FARADAY*v/(R*(celsius+273.15));
	eco = co*efun(arg);
	eci = ci*efun(-arg);
	return (0.001*z*FARADAY*(eci - eco));
}

 
double  gaussian(v,a,b,c,d) 
double  v,a,b,c,d ;
{
double arg;
arg = pow(((v-c)/b),2.0);
if ((arg>50.0) || (arg<-50.0))
{if (arg>50.0) return(d);
else  return(d+a);}
else return  (d + a*exp(-arg));
}


double boltz(v,half,slope)
double v,half,slope;
{
double arg;
arg = -(v-half)/slope;
if ((arg>50.0) || (arg<-50.0))
{if (arg>50.0) return(0.0);
else  return(1.0);}
else return(1.0/(1.0 + exp(arg)));}



int deriv_(np,xp,Y,F)
double *F,*Y;
int *np;
double *xp;
{
extern double current[C]; 
int el;
double time_;
float vol,P_KSK;
time_ = *xp;
double alpha_i,beta_i,alpha_a,beta_a;

el = *np;
vol = 4.0*PI*pow(RADIUS,3.0)/3000000.0; /*picoliters*/
P_KSK = 1.0/(1.0 + pow(K_SK/Y[CA],4.0));
current[I_CAL] = G_CAL*Y[D_CAL]*(Y[V] - E_CA);
current[I_KSK] = G_KSK*P_KSK*(Y[V] - E_K);
current[I_ERG] = G_ERG*Y[D_ERG]*(Y[V] - E_K);
alpha_i = (0.13)*exp(0.0234*(Y[V]+ 23.0));
/*alpha_i = (0.09)*exp(0.0234*(Y[V]+ 23.0));*/
beta_i  =  (0.0065)*exp(-0.03268*(Y[V]+23.0));
alpha_a = (0.0001)*exp(0.05*(Y[V]+ 50.0));
/*alpha_a = (0.0001)*exp(0.15*(Y[V]+ 50.0));*/
/*beta_a =  (0.0001)*exp(-0.05*(Y[V]+50.0));*/
beta_a =  (0.0001)*exp(-0.15*(Y[V]+25.0));
alpha_i = AI0*exp(AI1*Y[V]);
beta_i  =  BI0*exp(BI1*Y[V]);
alpha_a = AA0*exp(AA1*Y[V]);
beta_a =  BA0*exp(BA1*Y[V]);
current[I_H] =  G_H*pow(Y[D_H],2.0)*(Y[V] - E_H);
if(RED) current[I_H] =  G_H*pow(boltz(Y[V],V_HALF_D_H, V_SLOPE_D_H),2.0)*(Y[V] - E_H);
current[I_L] =  G_L*(Y[V] - E_L);
current[I_CAB] =  G_CAB*(Y[V] - E_CA);
current[I_CLAMP] = -G_CLAMP*(Y[V] - V_SET);
current[I_CAP] =  I_CAP_MAX*Y[CA]/(Y[CA] + K_CAP);
F[V] = (I_STIM + current[I_CLAMP] - ALPHA*current[I_CAP] - current[I_CAL] - current[I_CAB] - current[I_KSK] - current[I_ERG] - current[I_H] - current[I_L])/CM;

F[CA] =  -FF*(current[I_CAL] + current[I_CAB] +current[I_CAP])/(2.0*vol*FARADAY) ;
F[D_CAL] = (boltz(Y[V],V_HALF_D_CAL, V_SLOPE_D_CAL) - Y[D_CAL])/gaussian(Y[V],TAU2_D_CAL,TAU_SLOPE_D_CAL, TAU_HALF_D_CAL,TAU1_D_CAL);
F[D_ERG] = alpha_a + (beta_i - alpha_a)*Y[F_ERG] - (alpha_a+beta_a+alpha_i)*Y[D_ERG]; 
F[F_ERG] =  alpha_i*Y[D_ERG] - beta_i*Y[F_ERG];
/* F[D_H] = (boltz(Y[V],V_HALF_D_H, V_SLOPE_D_H) - Y[D_H])/gaussian(Y[V],TAU2_D_H,TAU_SLOPE_D_H, TAU_HALF_D_H,TAU1_D_H);*/
F[D_H] = (boltz(Y[V],V_HALF_D_H, V_SLOPE_D_H) - Y[D_H])/(TAU1_D_H + TAU2_D_H*boltz(Y[V],TAU_HALF_D_H, TAU_SLOPE_D_H));

return 0;
   }


void scan_(Y) 
double Y[N];
{FILE *fopen(),*sp;
int i;
sp = fopen("state.data","r");
for(i=0;i<N;i++) fscanf(sp,"%lf\n",&Y[i]);
fclose(sp);}

void dump_(Y) 
double Y[N];
{FILE *fopen(),*sp;
int i;
sp = fopen("end.data","w");
for(i=0;i<N;i++) fprintf(sp,"%.16f\n",Y[i]);
fclose(sp);}

int mas(n,amas,l)
        int *n;
        double *amas;
        int *l;
{return 0;}

int dummy(n,t,y,ydot)
        int *n;
        double *t;
        double *y;
        double *ydot;
{return 0;}

