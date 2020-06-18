/* ==================================================================== */
/* Template toolbox_skeleton */
/* This file is released under the 3-clause BSD license. See COPYING-BSD. */
/* ==================================================================== */
#include "api_scilab.h"
#include "Scierror.h"
#include "sci_malloc.h"
#include "kruskal_wallis.h"
#include <localization.h>

/* ==================================================================== */
int sci_ckruskal_wallis(char *fname, void* pvApiCtx)
{
    SciErr sciErr;

    int *piAddressVarOne = NULL;
    char *dVarOne = NULL;

    int *piAddressVarTwo = NULL;
    char *dVarTwo = NULL;

    int dOut = 0;

    /* --> result = csum(3,8)
    /* check that we have only 2 input arguments */
    /* check that we have only 1 output argument */
    CheckInputArgument(pvApiCtx, 1, 1) ;
    CheckOutputArgument(pvApiCtx, 1, 1) ;

    /* get Address of inputs */
    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressVarOne);
    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }


    /* check input type */
    if ( !isStringType(pvApiCtx, piAddressVarOne) )
    {
        Scierror(999, _("%s: Wrong type for input argument #%d: A string expected.\n"), fname, 1);
        return 0;
    }

    

    if ( getAllocatedSingleString(pvApiCtx, piAddressVarOne, &dVarOne) )
    {
        Scierror(999, _("%s: Wrong size for input argument #%d: A string expected.\n"), fname, 1);
        return 0;
    }


    /* call c function csum */
    kruskal_wallis(&dVarOne,&dOut);

    /* create result on stack */
    createSingleString(pvApiCtx, nbInputArgument(pvApiCtx) + 1, dOut);

    AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;

    ReturnArguments(pvApiCtx);

    return 0;
}
/* ==================================================================== */

