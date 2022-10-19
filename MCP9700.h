// License       : License.txt
// Specifications: Spec-MCP9700_MCP9700A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MCP9700.h
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MCP9700_H__
#define __MCP9700_H__

#include "user_define.h"

// Components number
#define iMCP9700                114U                    // Microchip Technology MCP9700, MCP9700A

// MCP9700 System Parts definitions
#define iMCP9700_xoff           0.5F                    // X offset [V]
#define iMCP9700_yoff           0.0F                    // Y offset [degree celsius]
#define iMCP9700_gain           0.01F                   // Gain [V/degree celsius]
#define iMCP9700_max            125.0F                  // Temperature Max [degree celsius]
#define iMCP9700_min            -40.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_MCP9700;

#endif /*__MCP9700_H__*/
