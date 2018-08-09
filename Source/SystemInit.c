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
#include "Threads.h"
#include <psx.h>
#include <stdint.h>
#include <stdio.h>
#include <thread.h>

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
    /* Initialize PSXSDK libs. */
    PSX_InitEx(PSX_INIT_SAVESTATE | PSX_INIT_CD);

    /* Initialize Gfx module. */
    GfxInit();

    /* Initialize Timers module. */
    TimersInit();

    if (ThreadsCreate(&Thread2))
    {
        /* New thread could be allocated successfully. */
        while (1)
        {
            static int i;
            printf("i = %d\n", i++);
        }
    }
    else
    {
        /* Thread could not be created. Exit. */
    }
}

static void Thread2(void)
{
    while (1)
    {
            printf("Thread2\n");
    }
}
