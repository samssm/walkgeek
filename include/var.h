/*
 * var.h
 *
 * Copyright (c) 2012, Oleg Tsaregorodtsev
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef VAR_H_
#define VAR_H_

/* Includes ------------------------------------------------------------------*/
/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  VAR_SystemState,
  VAR_ScreenMode,

  VAR_ApplicationState,

  VAR_AudioStatus,
  VAR_PlayerState,
  VAR_AudioVolume,
  VAR_AudioPosition,
  VAR_Audio_NeglectedDMA_Count,

  VAR_BatteryState,

  VAR_MSC_Speed,
  MAX_DISPLAY_VARIABLES
} VAR_Index;

/* Exported macro ------------------------------------------------------------*/
#define SetVariable(var_ix, var, val) do { if (var != val) { \
  SyncVariable(var_ix); } var = val; } while(0)

/* Exported functions --------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
extern u32 displayVariableFlags[];

/* Exported static inline functions ------------------------------------------*/
static inline void SyncVariable(VAR_Index var)
{
  displayVariableFlags[var] = true;
}

#endif /* VAR_H_ */