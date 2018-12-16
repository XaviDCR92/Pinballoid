/*******************************************************************//**
*
* \file     IO.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of IO module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "IO.h"
#include "Interrupts.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/* *************************************
 * Defines
 * *************************************/

enum
{
    FILE_BUFFER_SIZE = (182 << 10)
};

/* *************************************
 * Types definition
 * *************************************/

/* *************************************
 * Global variables definition
 * *************************************/

/* *************************************
 * Local variables definition
 * *************************************/

/* This buffer holds file data read from CD-ROM.
 * It is cleared out on each call to IOLoadFile(),
 * so copy its contents into an auxilar buffer if needed. */
static uint8_t au8FileBuffer[FILE_BUFFER_SIZE];

/* *************************************
 *  Local prototypes declaration
 * *************************************/

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Loads a file with absolute file path indicated by
*           strFileName.
*
*           File data is stored into a dynamically-allocated buffer
*           (via calls to malloc()) which can then be handled
*           by external modules.
*
* \param    strFilePath
*               Relative file path e.g.:
*               "DATA\\SPRITES\\TILESET1.TIM".
*
* \param    fileSize
*               Pointer to size_t variable where file size will
*               be stored.
*
* \return   Address to a read-only buffer with file data if successful,
*           NULL pointer otherwise.
*
* \return   fileSize
*  is assigned to actual file size in bytes
*           if successful, IO_INVALID_FILE_SIZE otherwise.
*
************************************************************************/
const uint8_t* IOLoadFile(const char* const strFilePath, size_t* const fileSize)
{
    if (strFilePath)
    {
        enum
        {
            MAX_FILE_PATH_LENGTH = 128
        };

        /* This buffer shall be used to concatenate "cdrom:\\"
         * and ";1" substrings along with indicated file path. */
        static char buffer[MAX_FILE_PATH_LENGTH];

        /* Create absolute file path from indicated path. */
        snprintf(buffer, sizeof (buffer), "cdrom:\\%s;1", strFilePath);

        if (buffer != NULL)
        {
            /* Temporarily disable VBlank interrupt. */
            InterruptsDisableInt(INT_SOURCE_VBLANK);

            /* Get file data from input file path. */
            FILE* const pFile = fopen(buffer, "r");

            /* Re-enable VBlank interrupt. */
            InterruptsEnableInt(INT_SOURCE_VBLANK);

            if (pFile != NULL)
            {
                /* Move file pointer to end of file. */
                if (fseek(pFile, 0, SEEK_END) == 0 /* Success code. */)
                {
                    if (fileSize != NULL)
                    {
                        /* File pointer could be successfully
                         * moved to the new position. */

                        /* Return file size in bytes to upper layers. */
                        *fileSize = ftell(pFile);

                        if (*fileSize < FILE_BUFFER_SIZE)
                        {
                            /* Buffer was successfully allocated according
                             * to file size. Now read file data into buffer. */

                            /* Reset file pointer iterator position first. */
                            if (fseek(pFile, 0, SEEK_SET) == 0 /* Sucess code. */)
                            {
                                /* Read file data into newly allocated buffer. */
                                const size_t eReadBytes = fread(au8FileBuffer, sizeof (uint8_t), *fileSize, pFile);

                                /* Close input opened file first. */
                                fclose(pFile);

                                if (eReadBytes == *fileSize)
                                {
                                    /* All bytes could be read from input file successfully. */

                                    /* Finally, return address to buffer so it can be
                                     * used by external modules. */
                                    return au8FileBuffer;
                                }
                                else
                                {
                                    /* Not all bytes from file were read.
                                     * Fall through. */
                                }
                            }
                            else
                            {
                                /* Something went wrong with fseek().
                                 * Fall through. */
                            }
                        }
                        else
                        {
                            /* Buffer cannot hold such amount of data.
                             * Fall through. */
                        }

                        /* Set file size to an invalid value. */
                        *fileSize = IO_INVALID_FILE_SIZE;
                    }
                    else
                    {
                        /* Invalid pointer to file size. */
                    }
                }
                else
                {
                    /* Something went wrong with fseek().
                     * Fall through. */
                }
            }
            else
            {
                /* File does not exist. Fall through. */
            }
        }
        else
        {
            /* File path could not be stored. */
        }
    }
    else
    {
        /* Invalid pointer to file path. */
    }

    /* Return failure code if this was reached. */
    return NULL;
}

#if 0
{
    struct CdFileInfo finfo;
    /* […init…] */

    if(CdFsFindFile(&bundleinfo, "FILE.EXT;1") == false)
    {
        /* [error handling] */
    }

    CdRead(buffer, no_of_sectors, finfo.lba+(2*5), CdlModeSpeed); CdReadSync(0);
}
#endif /* 0 */
