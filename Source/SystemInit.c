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
#include <thread.h>
#include <stdio.h>
#include <stdint.h>

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

static void Thread2(void);

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
    enum
    {
        INVALID_TCB = 0xFFFFFFFF
    };

    /* Initialize PSXSDK libs. */
    PSX_InitEx(PSX_INIT_SAVESTATE | PSX_INIT_CD);

    /* Initialize Gfx module. */
    GfxInit();

    unsigned int result;

    /* Disable interrupts while thread is initialized. */
    EnterCriticalSection();

    printf("gp = 0x%08X\n", GetGP());

    //~ result = OpenThread((unsigned int)&Thread2, 0x801FFB00, GetGP());
    result = OpenThread((unsigned int)&Thread2, 0x801FFB00, GetGP());

    if (result == 0xFFFFFFFF)
    {
        /* Something went wrong when initializing the thread. */
    }

    /* Re-enable interrupts. */
    ExitCriticalSection();

    printf("result = 0x%08X\n", result);

    /* Initialize Timers module. */
    TimersInit();
}

static void Thread2(void)
{
    while (1)
    {
        printf("Yo!\n");
    }
}
