/*******************************************************************//***
*
* \file     Interrupts.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of Interrupts module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Gfx.h"
#include "Timers.h"
#include <psx.h>

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Types definition
 * *************************************/

/* *************************************
 * Global variables definition
 * *************************************/

/* *************************************
 * Local variables definition
 * *************************************/

/* *************************************
 *  Local prototypes declaration
 * *************************************/

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//***
*
* \brief    Initializes PSXSDK libs and all SW modules.
*
************************************************************************/
void SystemInit(void)
{
    /* Initialize PSXSDK libs. */
    PSX_InitEx(PSX_INIT_SAVESTATE | PSX_INIT_CD);

    /* Initialize Gfx module. */
    GfxInit();

    /* Initialize Timers module. */
    TimersInit();
}
