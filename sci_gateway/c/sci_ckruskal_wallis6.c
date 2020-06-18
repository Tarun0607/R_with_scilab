/* ==================================================================== */
/* Template toolbox_skeleton */
/* This file is released under the 3-clause BSD license. See COPYING-BSD. */
/* ==================================================================== */
#include "api_scilab.h"
#include "Scierror.h"
#include "sci_malloc.h"
#include "kruskal_wallis.h"
#include <localization.h>

static const char fname[] = "ckruskal_wallis6";
/* ==================================================================== */
int sci_ckruskal_wallis6(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)
{
    char *in1 = NULL;
    int out1 = 0;
    /* --> result = csum(3,8)
    /* check that we have only 2 input arguments */
    /* check that we have only 1 output argument */
    if (nin > 1)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 1);
        return 1;
    }

    if (scilab_isStringType(env, in[0]) == 0)
    {
        Scierror(999, _("%s: Wrong type for input argument #%d: A string expected.\n"), fname, 1);
        return 1;
    }


    //get value of input 1
    scilab_getAllocatedSingleString(env, in[0], &in1);
    
    /* call c function csub */
    kruskal_wallis(&in1,&out1);

    //create output var and assign it to first output
    out[0] = scilab_createSingleString(env, out1);
    //return without error
    return 0;
}
/* ==================================================================== */

