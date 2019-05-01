#include <mex.h>
#include <simstruc.h>

#include <string>
#include <iostream>
//--#include <iomanip>
#include <sstream>
#include <Windows.h>

std::string int_array_to_string(const uint16_T * int_array, int size_of_array) {
  std::ostringstream oss("");

  for (int temp = 0; temp < size_of_array; temp++) {
    oss << (char)int_array[temp];
  }
  std::string str = oss.str();
  std::size_t found = str.find('\0');
  str = str.substr(0, found);
  return str;
}

void myStart(real_T *xD, const uint8_T *ActionUnitIDs, const int_T p_width0,
             SimStruct *S){

  /* we need to do a size check: size(AUs) >= p_width0  */
#define PORT_AUs 0
  int iSizePortAUs = ssGetInputPortWidth(S, PORT_AUs);
  int iNrAU = p_width0;

  std::cerr << "iNrAU: " << iNrAU << std::endl;
  
  if(iNrAU>iSizePortAUs){
    /* more AUs specified that the size of the dimension of the input array */
    std::stringstream ssError;
    ssError << "The size " << iSizePortAUs << " of the AU input array is smaller than the size of " << iNrAU << " of the AU ID vector";
    ssSetErrorStatus(S, ssError.str().c_str());
    std::cerr<< ssError.str() << std::endl;
  }
}


void myUpdate(const real_T *AUs,
              const real_T *duration,
              uint8_T *faceStrArr,
              const real_T *xD,
              const uint8_T *ActionUnitIDs, const int_T p_width0,
              const int_T u_width,
              SimStruct *S){

  int iNrAU = p_width0;
  int iStrLen = ssGetOutputPortWidth(S, 0);
  //  std::cerr << "iNrAU: " << iNrAU << std::endl;

  int iID;
 std::stringstream ss;
 
  for (int ii = 0; ii < iNrAU; ii++) {
    if (fabs(AUs[ii]) > 0.05) {
      iID = abs((int)GetTickCount64()*rand());
      
      ss << "<faceFacs au=\"" << (int)ActionUnitIDs[ii] << "\" side=\"BOTH\" id=\"" << iID << "\" start=\"0\" end=\"" << (double)*duration << "\" amount=\"" << AUs[ii] << "\"/>";
      //      std::cerr << "s: " << ss.str() << std::endl;
    }
  }

  std::string strTemp = ss.str();

  int iMax = strTemp.size();
  iMax = (iMax > iStrLen ? iStrLen : iMax);
  for (int ii = 0; ii < iMax; ii++) {
    faceStrArr[ii] = (char)strTemp.at(ii);
  }

  
}



