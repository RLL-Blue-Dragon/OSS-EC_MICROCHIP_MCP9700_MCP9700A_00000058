// License       : License.txt
// Specifications: Spec-MCP9700_MCP9700A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MCP9700.cpp
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MCP9700.h"

#if     iMCP9700_ma == iSMA                             // Simple moving average filter
static float32 MCP9700_sma_buf[iMCP9700_SMA_num];
static sma_f32_t MCP9700_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMCP9700_SMA_num ,                              // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MCP9700_sma_buf[0]                             // buffer
};

#elif   iMCP9700_ma == iEMA                             // Exponential moving average filter
static ema_f32_t MCP9700_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMCP9700_EMA_K                                  // Exponential smoothing factor
};

#elif   iMCP9700_ma == iWMA                             // Weighted moving average filter
static float32 MCP9700_wma_buf[iMCP9700_WMA_num];
static wma_f32_t MCP9700_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMCP9700_WMA_num ,                              // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMCP9700_WMA_num * (iMCP9700_WMA_num + 1)/2 ,   // kn sum
        &MCP9700_wma_buf[0]                             // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MCP9700 =
{
        iMCP9700                ,
        iMCP9700_pin            ,
        iMCP9700_xoff           ,
        iMCP9700_yoff           ,
        iMCP9700_gain           ,
        iMCP9700_max            ,
        iMCP9700_min            ,
        iMCP9700_ma             ,
        
#if     iMCP9700_ma == iSMA                             // Simple moving average filter
        &MCP9700_Phy_SMA        ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMCP9700_ma == iEMA                             // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MCP9700_Phy_EMA        ,
        (wma_f32_t*)iDummy_adr
#elif   iMCP9700_ma == iWMA                             // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MCP9700_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
