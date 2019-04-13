

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
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>



/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 6
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
void faceStringCHL_Outputs_wrapper(const real_T *AUs,
	real_T *faceStrArr)
{
	/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#define NRAU 16
#define ASIZE 2048



	int ii;
	int vAU[NRAU] = { 1, 2, 4, 5, 6, 7, 9, 10, 11, 12, 15, 16, 17, 20, 23, 26 };
	char strTemp[256];
	char strAUTemp[ASIZE];
	char strAU[ASIZE];

	memset(strTemp, 0, 256);
	memset(strAUTemp, 0, ASIZE);
	memset(strAU, 0, ASIZE);




	for (ii = 0; ii < NRAU; ii++) {
		if (fabs(AUs[ii]) > 0.05) {
		    time_t tNow;
	        tNow = time(NULL);
	        int iSecs = (int)(tNow - floor((double)(tNow / 1000.)) * 1000); //get the last 1000 seconds
			std::stringstream ss;
			ss << std::setfill('0');
			ss << std::setw(5) << rand() << iSecs;
			sprintf(strTemp, "<faceFacs au=\"%d\" side=\"BOTH\" id=\"%s\" start=\"0\" end=\"3\" amount=\"%04.2f\"/>", AUs[ii], ss.str().c_str(), vAU[ii]);
			strcat(strAUTemp, strTemp);
		}
	}

	sprintf(strAU, "%s", strAUTemp);

	for (ii = 0; ii < ASIZE; ii++) {
		faceStrArr[ii] = (char)strAU[ii];
	}
	/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
