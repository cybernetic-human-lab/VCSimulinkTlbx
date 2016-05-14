

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdio.h>
#include <string.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void gazeString_Outputs_wrapper(const real_T *xpos,
			const real_T *ypos,
			const real_T *zpos,
			const real_T *extent,
			real_T *gazeStrArr)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#define ASIZE 2048
int ampli;
//char *buffer;
char buffer [2048];
int ii;
const char * jra[] = {
    "EYES",
    "EYES NECK",
    "EYES CHEST",
    "EYES BACK",
};

memset(buffer, 0, ASIZE);


ampli = (int)floor((extent[0]*3.99999));
ampli = (ampli<4 ? ampli : 0);

//speed is for NECH and EYES
sprintf (buffer, "<gaze sbm:target-pos=\"%3.2f %3.2f %3.2f\" sbm:joint-range=\"%s\"  sbm:joint-speed=\"500 1000\"/>", xpos[0], ypos[0], zpos[0], jra[ampli]);

for(ii = 0; ii<ASIZE; ii++){
    gazeStrArr[ii] = (double)buffer[ii];   
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
