/* 
 * File:   app_i2c_ihm.h
 * Author: Caroline
 *
 * Created on 3 de Julho de 2022, 18:35
 */

#ifndef APP_I2C_IHM_H
#define	APP_I2C_IHM_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes


#ifdef	__cplusplus
extern "C" {
#endif

#define RX_DATA_LENGTH          1
    
typedef enum
{
    I2C_STATE_STATUS_VERIFY,
    I2C_STATE_READ_DATA,
    I2C_STATE_WAIT_READ_COMPLETE,
    I2C_STATE_WRITE_DATA,
    I2C_STATE_WAIT_WRITE_COMPLETE,
    I2C_STATE_CHECK_INTERNAL_WRITE_STATUS,
    I2C_STATE_VERIFY,
    I2C_STATE_IDLE_APP,
    I2C_STATE_XFER_SUCCESSFUL,
    I2C_STATE_XFER_ERROR,

} APP_I2C_STATES;

typedef enum
{
    I2C_TRANSFER_STATUS_IN_PROGRESS,
    I2C_TRANSFER_STATUS_SUCCESS,
    I2C_TRANSFER_STATUS_ERROR,
    I2C_TRANSFER_STATUS_IDLE,

} I2C_TRANSFER_STATUS;

typedef enum
{
    IHM_INT_STATE,
    IHM_NO_INT_STATE,

} IHM_INTERRUPT_STATUS;

typedef struct
{
    /* Application's current state */
    APP_I2C_STATES  state;

    uint8_t  rxBuffer[RX_DATA_LENGTH];

    volatile I2C_TRANSFER_STATUS transferStatus;
    
    volatile IHM_INTERRUPT_STATUS ihmStatus ;
    
    uint8_t ackData;

} APP_IHM_DATA;

void APP_I2C_IHM_Initialize( void );
void APP_I2C_IHM_Tasks( void );

#ifdef	__cplusplus
}
#endif

#endif	/* APP_I2C_IHM_H */

