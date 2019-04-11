
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
#include "include/json.hpp"

using namespace std;
using json = nlohmann::json;

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
 * Output function
 *
 */
void breathingJSON_Outputs_wrapper(const real_T *thx,
                                   const real_T *abd,
                                   const real_T *neck,
                                   real_T *JSON,
                                   const real_T *charname, const int_T p_width0)
{
     /* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */

     double yaw = 0;
     double roll = 0;
     double pitch = *neck;

     double t0 = std::cos(yaw * 0.5f);
     double t1 = std::sin(yaw * 0.5f);
     double t2 = std::cos(roll * 0.5f);
     double t3 = std::sin(roll * 0.5f);
     double t4 = std::cos(pitch * 0.5f);
     double t5 = std::sin(pitch * 0.5f);

     double w = t0 * t2 * t4 + t1 * t3 * t5;
     double x = t0 * t3 * t4 - t1 * t2 * t5;
     double y = t0 * t2 * t5 + t1 * t3 * t4;
     double z = t1 * t2 * t4 - t0 * t3 * t5;

     // create an empty structure (null)
     json j;

     // add a number that is stored as double (note the implicit conversion of j to an object)

     //-- std::string neck_joint = "mixamorig:Hips/mixamorig:Spine/mixamorig:Spine1/mixamorig:Spine2/mixamorig:Neck/mixamorig:Head";
     std::string neck_joint = "Hips/Spine/Spine1/Spine2/Neck/Head";

     // std::string char_name = "FuseCharacter";

     std::ostringstream oss("");
     for (int temp = 0; temp < p_width0; temp++)
     {
          oss << (char)charname[temp];
     }

      std::string char_name =  oss.str();

     j["character"] = char_name;

     j["blendshape_ctrl"]["mesh"] = "Tops";

     j["blendshape_ctrl"]["blendshapes_names"] = {"Tops_BreatheChest", "Tops_BreatheStomach"};
     j["blendshape_ctrl"]["blendshapes_weights"] = {*thx, *abd};

     j["joint_rotation"]["name"] = "Hips/Spine/Spine1/Spine2/Neck/Head";
     j["joint_rotation"]["quaternion"] = {x, y, z, w};

     std::string s = j.dump();
     //     std::cerr << "json: " << s << std::endl;

#define ASIZE 2048

     char caJSON[ASIZE];
     memset(caJSON, 0, ASIZE);

     sprintf(caJSON, "%s", s.c_str());

     for (int ii = 0; ii < ASIZE; ii++)
     {
          JSON[ii] = (char)caJSON[ii];
     }

     /*
std::string int_array_to_string(int int_array[], int size_of_array) {
	std::ostringstream oss("");
	for (int temp = 0; temp < size_of_array; temp++) {
		oss << (char)int_array[temp];
	}
	return oss.str();
}
*/

     /* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
