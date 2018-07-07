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
        INVALID_TCB = 0xFFFFFFFFul
    };

    /* Initialize PSXSDK libs. */
    PSX_InitEx(PSX_INIT_SAVESTATE | PSX_INIT_CD);

    /* Initialize Gfx module. */
    GfxInit();

    printf("TCB address = 0x%08X\n", *(unsigned int*)0x110);
    printf("TCB size = %d\n", *(unsigned int*)0x114);
    printf("Used TCB = 0x%08X\n", **(unsigned int**)0x110);

    /* Disable interrupts while thread is initialized. */
    EnterCriticalSection();

    printf("gp = 0x%08X\n", GetGP());

    {
        //~ result = OpenThread((unsigned int)&Thread2, 0x801FFB00, GetGP());
        const unsigned int result = OpenThread((unsigned int)&Thread2, 0x801FFB00, GetGP());

        if (result == INVALID_TCB)
        {
            /* Something went wrong when initializing the thread. */
        }

    }

    /* Re-enable interrupts. */
    ExitCriticalSection();

    /* Initialize Timers module. */
    TimersInit();
}

static void Thread2(void)
{
    while (1)
    {
        //~printf("Yo!\n");
    }
}
