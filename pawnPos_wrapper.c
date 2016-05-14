

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
void pawnPos_Outputs_wrapper(const real_T *xpos,
			const real_T *ypos,
			const real_T *zpos,
			real_T *pawnStrArr)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#define ASIZE 2048

char buffer [ASIZE];
char pawnName []="gazeTarget";

int ii;

memset(buffer, 0, ASIZE);
sprintf(buffer, "scene.getPawn(\"%s\").setPosition(SrVec(%08.2f, %08.2f,  %08.2f))", pawnName, xpos[0], ypos[0], zpos[0]);

for(ii = 0; ii<ASIZE; ii++){
    pawnStrArr[ii] = (char)buffer[ii];
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
