/*******************************************************************//**
*
* \file     Threads.c
*
* \brief    Implementation file for Threads module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Threads.h"
#include <psxbios.h>
#include <stdint.h>
#include <stdbool.h>
#include <thread.h>
#include <stdio.h>

/* *************************************
 * Defines
 * *************************************/

#define TABLE_OF_TABLES_ADDR    ((unsigned int)0x100)

/* *************************************
 * Types definition
 * *************************************/

enum tToTBlock
{
    TOT_BLOCK_ExCB,
    TOT_BLOCK_PCB,
    TOT_BLOCK_TCB,
    TOT_BLOCK_RESERVED_1,
    TOT_BLOCK_EvCB,
    TOT_BLOCK_RESERVED_2,
    TOT_BLOCK_RESERVED_3,
    TOT_BLOCK_RESERVED_4,
    TOT_BLOCK_FCB,
    TOT_BLOCK_RESERVED_5,
    TOT_BLOCK_DCB,

    MAX_TOT_BLOCKS
};

struct tToT
{
    void* pTable;
    unsigned long ulSize;
};

struct tToT* sToT = (struct tToT*)TABLE_OF_TABLES_ADDR;

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

/*******************************************************************//**
*
* \brief    This function creates a new thread which will be started
*           from a given function pointer.
*
* \param    pThreadHandler
*               Function pointer to thread handler.
*
* \return   Returns true if thread could be created, false otherwise.
*
************************************************************************/
bool ThreadsCreate(void (*const pThreadHandler)(void))
{
    enum
    {
        /* Maximum number of threads allowed. */
        MAX_THREADS_ALLOWED = 4,

        /* Stack size for each newly allocated thread.*/
        SUB_STACK_SIZE = 128,

        /* Initial address for subthread stack pointer. */
        INITIAL_SUB_STACK_ADDR = 0x801FFB00,

        /* Error code returned by PSX kernel
         * when a thread could not be created. */
        INVALID_TCB = 0xFFFFFFFF
    };

    /* Disable interrupts while thread is initialized. */
    EnterCriticalSection();

    /* Store substack pointer address. */
    static unsigned int pSubStackPtr = INITIAL_SUB_STACK_ADDR;

    /* Store number of successfully created threads. */
    static uint8_t ulThreadsCreated;

    /* This variable will be returned to upper
     * layers and inform about thread creation results. */
    bool bResult = false;

    if (OpenThread((unsigned int)pThreadHandler, pSubStackPtr, GetGP()) != INVALID_TCB)
    {
        /* Thread could be created successfully. */
        bResult = true;

        /* Increment number of created threads. */
        ulThreadsCreated++;

        /* Decrement substack pointer SUB_STACK_SIZE
         * bytes for the next time this function is called. */
        pSubStackPtr -= SUB_STACK_SIZE;
    }
    else
    {
        /* Something went wrong when initializing the thread. */
    }

    /* Re-enable interrupts. */
    ExitCriticalSection();

    /* Return thread creation results. */
    return bResult;
}
