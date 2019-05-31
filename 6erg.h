#define ALPHA 0.0 /* Factor for pump electrogeneity */
#define VAR 1 /* make ERG tau variable*/
#define RED 0 /* makes IH instantaneous*/
#define IN 1 /* switch to turn inactivation on*/
#define N 6 /* 6 */
#define C 8
#define CM 0.0158 /* 0.0158 pF */
#define RADIUS 15.0 /* uM */
#define FF 0.025 /* 0.015 0.025 0.00025 */
#define V_SET -38  /* mV */
#define V 0  /* mV */
#define CA 3  /* mM */
#define D_CAL 2 
#define D_ERG 1 
#define D_H 4 
#define F_ERG 5 
#define I_CAL 0  
#define I_KSK 1 
#define I_ERG 2
#define I_H 3 
#define I_L 4
#define I_CAB 5 
#define I_CAP 6 
#define I_CLAMP 7 
#define I_STIM 0.000 /* range -0.025 to 0.034 0.021 -0.0168 50 pA for 7a*/
#define I_CAP_MAX  0.5    /* nA*/
#define E_CA  50.0
#define E_K  -85.0
#define E_H  -29.0
#define E_L  -65.5 /* -66 -54.00flag */
#define G_CLAMP  0.0 /* 1.0 */
#define G_CAL 0.0023 /*0.0023 uS*/
#define G_KSK 0.000 /*0.001 0.0015*/
#define G_ERG 0.015 /* 0.015 uS flag */
#define G_H   0.008 /* 0.008 uS*/
#define G_L   0.0055 /*0.0055 uS flag*/
#define G_CAB    0.0002  
#define K_CAP    0.000500 /*mM*/
#define K_SK    0.000190 /*mM*/
#define V_HALF_D_CAL -45.0
#define V_SLOPE_D_CAL 7.0
#define TAU_HALF_D_CAL -70.0
#define TAU_SLOPE_D_CAL 25.0
#define TAU1_D_CAL 0.3
#define TAU2_D_CAL 18.0
#define V_HALF_D_ERG -35.0 /* -50 mV */
#define V_SLOPE_D_ERG 5.0 /* 5.0 */
#define V_HALF_F_ERG -70.0 /* -70 mV*/
#define V_SLOPE_F_ERG -20.0
#define AI0 0.1 /* 0.1 */
#define AI1 0.02 
#define BI0 0.003 /* 0.003*/
#define BI1 -0.03
#define AA0 0.00225  /* 0.00225 0.012*/
#define AA1 0.12  /* 0.12 0.15 */  
#define BA0 0.4e-4 /* 0.4e-4*/
#define BA1 -0.05
#define TAU1_D_ERG 4000.0 /* 5000.0 flag */
#define TAU1_F_ERG 15.0 /* 15 */
#define V_HALF_D_H -77.6   /* -77.624*/
#define V_SLOPE_D_H -17.317/* -17.317 */
#define TAU_HALF_D_H -22.686
#define TAU_SLOPE_D_H 29.597  
#define TAU1_D_H 26.21
#define TAU2_D_H 3136.0

#define VHOLD -80.0
#define P1_V  -40.0
#define P2_V -60.0
#define P3_V -60.0
#define P1_ON 0.1
#define P1_OFF 50000.0
#define P2_OFF 50000.0
#define P3_OFF 50000.0

/* INTEGRATION PARAMETERS */

/* these only apply to C code */
#define LWORK 199 /* N(4*N + 8)+7*/
#define LIWORK 25 /*3*N+7*/
#define LRCONT 28 /*4*N+4*/
#define DURATION 5
#define TIMEON 0
#define TIMEOFF 0
#define PERIOD  250
#define ENDTIME 10000
#define START_TIME  0

#define PI  3.1416
#define FARADAY  96520 
#define R  8.3134 
#define celsius 10.00 
#define T celsius + 273
#define PRINT  0
#define DEBUG 0
#define PULSEON 300000
#define PULSEOFF 300000

