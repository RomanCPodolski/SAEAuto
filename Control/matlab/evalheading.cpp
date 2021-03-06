/*
 * evalheading.cpp
 *
 * Code generation for function 'evalheading'
 *
 * C source code generated on: Mon Sep  1 19:20:44 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "arclengthcurve.h"
#include "buildbfcurvature.h"
#include "builddetailedbf.h"
#include "buildmanouvers.h"
#include "checkpathcollision.h"
#include "equateoffsetcost.h"
#include "equatesafetycost.h"
#include "evalheading.h"
#include "localize.h"
#include "mincost.h"
#include "oblocalize.h"
#include "parevalspline.h"
#include "matlab_emxutil.h"
#include "histc.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * function [sindex, paththeta] = evalheading(scp,ss,dxds,dyds)
 */
void evalheading(real_T scp, const emxArray_real_T *ss, const emxArray_real_T
                 *dxds, const emxArray_real_T *dyds, real_T *sindex, real_T
                 *paththeta)
{
  emxArray_real_T *unusedU0;
  b_emxInit_real_T(&unusedU0, 2);

  /* Find nearest base frame point and calculates the heading at that point */
  /* 'evalheading:5' [~,sindex] = histc(scp,ss); */
  b_histc(scp, ss, unusedU0, sindex);

  /* base frame curve index of initial point */
  /* Calculate Base path heading at point */
  /* 'evalheading:8' if dxds(sindex) < 0 && dyds(sindex) < 0 */
  emxFree_real_T(&unusedU0);
  if ((dxds->data[(int32_T)*sindex - 1] < 0.0) && (dyds->data[(int32_T)*sindex -
       1] < 0.0)) {
    /* q3 */
    /* 'evalheading:10' paththeta = pi + asin(abs(dyds(sindex))); */
    *paththeta = 3.1415926535897931 + asin(fabs(dyds->data[(int32_T)*sindex - 1]));
  } else {
    /* 'evalheading:11' else */
    /* 'evalheading:11' if dxds(sindex) > 0 && dyds(sindex) < 0 */
    if ((dxds->data[(int32_T)*sindex - 1] > 0.0) && (dyds->data[(int32_T)*sindex
         - 1] < 0.0)) {
      /* q4 */
      /* 'evalheading:13' paththeta = 2*pi + asin(dyds(sindex)); */
      *paththeta = 6.2831853071795862 + asin(dyds->data[(int32_T)*sindex - 1]);
    } else {
      /* 'evalheading:14' else */
      /* q1 or q2 */
      /* 'evalheading:16' paththeta = acos(dxds(sindex)); */
      *paththeta = acos(dxds->data[(int32_T)*sindex - 1]);
    }
  }
}

/* End of code generation (evalheading.cpp) */
