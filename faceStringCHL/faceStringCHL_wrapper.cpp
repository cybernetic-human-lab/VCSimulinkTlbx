
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */

extern void myUpdate(const real_T *AUs,
              const real_T *duration,
              uint8_T *faceStrArr,
              const real_T *xD,
              const uint8_T *ActionUnitIDs, const int_T p_width0,
              const int_T u_width,
              SimStruct *S);
extern void myStart(real_T *xD, const uint8_T *ActionUnitIDs, const int_T p_width0,
             SimStruct *S);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void faceStringCHL_Start_wrapper(real_T *xD,
			const uint8_T *ActionUnitIDs, const int_T p_width0,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */

myStart(xD, ActionUnitIDs, p_width0, S);
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void faceStringCHL_Outputs_wrapper(const real_T *AUs,
			const real_T *duration,
			uint8_T *faceStrArr,
			const real_T *xD,
			const uint8_T *ActionUnitIDs, const int_T p_width0,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void faceStringCHL_Update_wrapper(const real_T *AUs,
			const real_T *duration,
			uint8_T *faceStrArr,
			real_T *xD,
			const uint8_T *ActionUnitIDs, const int_T p_width0,
			const int_T u_width,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */

myUpdate(AUs, duration, faceStrArr, xD, ActionUnitIDs, p_width0, u_width, S);
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

