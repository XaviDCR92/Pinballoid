#ifndef FILE_DATA_H
#define FILE_DATA_H

/*******************************************************************//**
*
* \file     FileData.h
*
* \author   Xavier Del Campo
*
* \brief    Include file for FileData module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include <stdbool.h>
#include <stddef.h>

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/

struct FileData
{
    const char* const path; /**< Relative file path. */
    void* const data;   /**< Pointer to data to be written. */
    const enum
    {
        DATA_TYPE_UNDEFINED,
        DATA_TYPE_SPRITE,
        DATA_TYPE_SOUND,

        MAX_DATA_TYPES
    } dataType;
};

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

bool FileDataLoad(struct FileData* const fileList);
bool FileDataLoadList(struct FileData* const* const fileList, const size_t files);

#endif /* FILE_DATA_H */

