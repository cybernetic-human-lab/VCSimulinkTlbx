

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
#define y_width 2048
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
void AUsMaleBML_Outputs_wrapper(const real_T *AUs,
			real_T *faceStrArr)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#define NRAU 27
#define ASIZE 2048

int ii;
int vAU[NRAU]={1, 2, 27, 26, 6, 18, 22, 14, 17, 10, 5, 43, 4, 9, 39, 38, 25, 24, 23, 19, 13, 7, 12, 11, 15, 16, 20};
char strTemp[256];
char strAUTemp[ASIZE];
char strAU[ASIZE];

memset(strTemp, 0, 256);
memset(strAUTemp, 0, ASIZE);
memset(strAU, 0, ASIZE);

for(ii=0; ii<NRAU; ii++){
    if(AUs[ii]>0.05){
        sprintf(strTemp, "<face type=\"FACS\" au=\"%d\" amount=\"%04.2f\"/>", vAU[ii], AUs[ii]);
        strcat(strAUTemp, strTemp);
    }
}

sprintf(strAU, "%s", strAUTemp);

for(ii = 0; ii<ASIZE; ii++){
    faceStrArr[ii] = (char)strAU[ii];
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
