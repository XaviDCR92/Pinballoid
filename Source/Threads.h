#ifndef THREAD_HANDLER_H__
#define THREAD_HANDLER_H__

/*******************************************************************//**
*
* \file     Threads.h
*
* \author   Xavier Del Campo
*
* \brief    Include file for Threads module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include <stdbool.h>

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

bool ThreadsCreate(void (*const pThreadHandler)(void));

#endif /* THREAD_HANDLER_H__ */
