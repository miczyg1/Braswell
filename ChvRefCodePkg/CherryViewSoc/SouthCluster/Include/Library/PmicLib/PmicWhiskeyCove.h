/** @file

  Copyright (c) 2013 - 2015, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _PMIC_REG_WC_H_
#define _PMIC_REG_WC_H_

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/I2CLib.h>
#include <Library/PmicLib.h>
#include <Library/TimerLib.h>
#include <Library/PcdLib.h>
#include "PmicReg.h"
#include "ChvAccess.h"
#include <Guid/PlatformInfo.h>
#include "PmicNVMProvision.h"

#define DELAY_BETWEEN_INSTRUCTION_500 500
#define DELAY_BETWEEN_INSTRUCTION_100 100
#define DELAY_BETWEEN_INSTRUCTION_50 50
#define DELAY_BETWEEN_INSTRUCTION_10 10
#define DELAY_BETWEEN_INSTRUCTION_5  5

#define WC_PMIC_I2C_CHANNEL_NUMBER 0x6
#define WC_PMIC_I2C_DEV_1_SLAVE_ADDRESS 0x4E // For BXT
#define WC_PMIC_I2C_DEV_2_SLAVE_ADDRESS 0x4F // Common
#define WC_PMIC_I2C_DEV_3_SLAVE_ADDRESS 0x5E // Common
#define WC_PMIC_I2C_DEV_4_SLAVE_ADDRESS 0x5F // Common
#define WC_PMIC_I2C_DEV_5_SLAVE_ADDRESS 0x6E // For CHT
#define WC_PMIC_I2C_SCRATCH_SLAVE_ADDRESS 0x6F
#define WC_PMIC_I2C_VCC0_DEVICE_ADDRESS 0x10
#define WC_PMIC_I2C_VCC1_DEVICE_ADDRESS 0x18
#define WC_PMIC_I2C_VNN_DEVICE_ADDRESS  0x12
#define WC_PMIC_I2C_VGG_DEVICE_ADDRESS  0x1A

//VCC0 VCC1 VNN VGG definitions

#define VOUT_MAX_REG 0x30
#define VID_MAX_REG  0x33

//DEV 2 definitions

#define DEV2_ID_TRMPGM_REG 0x00
#define DEV2_ID_OTPVERSION_REG 0x01
#define DEV2_ADC_GPADCREQ_REG 0x02
#define DEV2_ADC_VBATRSLTH_REG 0x03
#define DEV2_ADC_VBATRSLTL_REG 0x04
#define DEV2_ADC_GPADCCNTL_REG 0x05
#define DEV2_ADC_BATTIDRSLTH_REG 0x06
#define DEV2_ADC_BATTIDRSLTL_REG 0x07
#define DEV2_ADC_USBIDRSLTH_REG 0x08
#define DEV2_ADC_USBIDRSLTL_REG 0x09
#define DEV2_ADC_GPMEASRSLTH_REG 0x0A
#define DEV2_ADC_GPMEASRSLTL_REG 0x0B
#define DEV2_ADC_Y0DATAH_REG 0x0C
#define DEV2_ADC_Y0DATAL_REG 0x0D
#define DEV2_ADC_Y1DATAH_REG 0x0E
#define DEV2_ADC_Y1DATAL_REG 0x0F
#define DEV2_SVID_DEV2_STATUS_1_REG 0x10
#define DEV2_SVID_DEV2_STATUS_2_REG 0x11
#define DEV2_ADC_PEAKREQ_REG 0x12
#define DEV2_ADC_PEAKRSLTH_REG 0x13
#define DEV2_ADC_PEAKRSLTL_REG 0x14
#define DEV2_THERM_BATTEMP0H_REG 0x15
#define DEV2_THERM_BATTEMP0L_REG 0x16
#define DEV2_THERM_BATTEMP1H_REG 0x17
#define DEV2_THERM_BATTEMP1L_REG 0x18
#define DEV2_THERM_STHRMIRQ0_REG 0x19
#define DEV2_THERM_STHRMIRQ1_REG 0x1A
#define DEV2_THERM_STHRMIRQ2_REG 0x1B
#define DEV2_SVID_DEV2_STATUS2_LASTREAD_REG 0x1C
#define DEV2_THERM_THRMMONCFG_REG 0x1D
#define DEV2_THERM_THRMMONCTL_REG 0x1E
#define DEV2_THERM_BATTHERMMONCTL_REG 0x1F
#define DEV2_THERM_VBATMONCTL_REG 0x20
#define DEV2_THERM_GPMONCTL_REG 0x21
#define DEV2_THERM_THRMBATZONE_REG 0x22
#define DEV2_THERM_SYS0ALERT0H_REG 0x23
#define DEV2_THERM_SYS0ALERT0L_REG 0x24
#define DEV2_THERM_SYS0ALERT1H_REG 0x25
#define DEV2_THERM_SYS0ALERT1L_REG 0x26
#define DEV2_THERM_SYS1ALERT0H_REG 0x27
#define DEV2_THERM_SYS1ALERT0L_REG 0x28
#define DEV2_THERM_SYS1ALERT1H_REG 0x29
#define DEV2_THERM_SYS1ALERT1L_REG 0x2A
#define DEV2_THERM_SYS2ALERT0H_REG 0x2B
#define DEV2_THERM_SYS2ALERT0L_REG 0x2C
#define DEV2_THERM_SYS2ALERT1H_REG 0x2D
#define DEV2_THERM_SYS2ALERT1L_REG 0x2E
#define DEV2_THERM_BAT0ALERT0H_REG 0x2F
#define DEV2_THERM_BAT0ALERT0L_REG 0x30
#define DEV2_THERM_BAT1ALERT0H_REG 0x31
#define DEV2_THERM_BAT1ALERT0L_REG 0x32
#define DEV2_THERM_PMICALERT0H_REG 0x33
#define DEV2_THERM_PMICALERT0L_REG 0x34
#define DEV2_SVID_DEV2_SETREGADR_REG 0x35
#define DEV2_THERM_GPMEASALERTH_REG 0x36
#define DEV2_THERM_GPMEASALERTL_REG 0x37
#define DEV2_THERM_THRMRSLT0H_REG 0x38
#define DEV2_THERM_THRMRSLT0L_REG 0x39
#define DEV2_THERM_THRMRSLT1H_REG 0x3A
#define DEV2_THERM_THRMRSLT1L_REG 0x3B
#define DEV2_THERM_THRMRSLT2H_REG 0x3C
#define DEV2_THERM_THRMRSLT2L_REG 0x3D
#define DEV2_THERM_THRMRSLT3H_REG 0x3E
#define DEV2_THERM_THRMRSLT3L_REG 0x3F
#define DEV2_THERM_THRMRSLT4H_REG 0x40
#define DEV2_THERM_THRMRSLT4L_REG 0x41
#define DEV2_THERM_THRMRSLT5H_REG 0x42
#define DEV2_THERM_THRMRSLT5L_REG 0x43
#define DEV2_THERM_THRMZN0H_REG 0x44
#define DEV2_THERM_THRMZN0L_REG 0x45
#define DEV2_THERM_THRMZN1H_REG 0x46
#define DEV2_THERM_THRMZN1L_REG 0x47
#define DEV2_THERM_THRMZN2H_REG 0x48
#define DEV2_THERM_THRMZN2L_REG 0x49
#define DEV2_THERM_THRMZN3H_REG 0x4A
#define DEV2_THERM_THRMZN3L_REG 0x4B
#define DEV2_THERM_THRMZN4H_REG 0x4C
#define DEV2_THERM_THRMZN4L_REG 0x4D
#define DEV2_THERM_BATCRITCOLDH_REG 0x4E
#define DEV2_THERM_BATCRITCOLDL_REG 0x4F
#define DEV2_THERM_BATCRITHOTH_REG 0x50
#define DEV2_THERM_BATCRITHOTL_REG 0x51
#define DEV2_THERM_BATCRITH_REG 0x52
#define DEV2_THERM_BATCRITL_REG 0x53
#define DEV2_THERM_PMICCRITH_REG 0x54
#define DEV2_THERM_PMICCRITL_REG 0x55
#define DEV2_THERM_SYS0CRITH_REG 0x56
#define DEV2_THERM_SYS0CRITL_REG 0x57
#define DEV2_THERM_SYS1CRITH_REG 0x58
#define DEV2_THERM_SYS1CRITL_REG 0x59
#define DEV2_THERM_SYS2CRITH_REG 0x5A
#define DEV2_THERM_SYS2CRITL_REG 0x5B
#define DEV2_THERM_SYS0ALERT3H_REG 0x5C
#define DEV2_THERM_SYS0ALERT3L_REG 0x5D
#define DEV2_THERM_SYS1ALERT3H_REG 0x5E
#define DEV2_THERM_SYS1ALERT3L_REG 0x5F
#define DEV2_THERM_SYS2ALERT3H_REG 0x60
#define DEV2_THERM_SYS2ALERT3L_REG 0x61
#define DEV2_THERM_PMICALERT3H_REG 0x62
#define DEV2_THERM_PMICALERT3L_REG 0x63
#define DEV2_THERM_BAT0ALERT3H_REG 0x64
#define DEV2_THERM_BAT0ALERT3L_REG 0x65
#define DEV2_THERM_BAT1ALERT3H_REG 0x66
#define DEV2_THERM_BAT1ALERT3L_REG 0x67
#define DEV2_THERM_THRMCRITEN_REG 0x68
#define DEV2_THERM_THRMALERT3EN_REG 0x69
#define DEV2_THERM_THRMALERT3PAEN_REG 0x6A
#define DEV2_IMON_CM_VCC0_MODE_CTRL_REG 0x6B
#define DEV2_IMON_CM_VCC1_MODE_CTRL_REG 0x6C
#define DEV2_IMON_CM_VCC_MODE_CTRL_REG 0x6D
#define DEV2_IMON_CM_VNN_MODE_CTRL_REG 0x6E
#define DEV2_IMON_CM_VNNAON_MODE_CTRL_REG 0x6F
#define DEV2_IMON_CM_VDD1_MODE_CTRL_REG 0x70
#define DEV2_IMON_CM_VDD2_MODE_CTRL_REG 0x71
#define DEV2_IMON_CM_VCCRAM_MODE_CTRL_REG 0x72
#define DEV2_IMON_CM_VMEM_MODE_CTRL_REG 0x73
#define DEV2_IMON_CM_VFLEX_MODE_CTRL_REG 0x74
#define DEV2_IMON_CM_VPROG1A_MODE_CTRL_REG 0x75
#define DEV2_IMON_CM_VPROG1B_MODE_CTRL_REG 0x76
#define DEV2_IMON_CM_VPROG1C_MODE_CTRL_REG 0x77
#define DEV2_IMON_CM_VPROG1D_MODE_CTRL_REG 0x78
#define DEV2_IMON_CM_VPROG2A_MODE_CTRL_REG 0x79
#define DEV2_IMON_CM_VPROG2B_MODE_CTRL_REG 0x7A
#define DEV2_IMON_CM_VPROG2C_MODE_CTRL_REG 0x7B
#define DEV2_IMON_CM_VPROG3A_MODE_CTRL_REG 0x7C
#define DEV2_IMON_CM_VPROG3B_MODE_CTRL_REG 0x7D
#define DEV2_IMON_CM_TSPAN_CTRL_REG 0x7E
#define DEV2_IMON_CM_LDO1_THRSHLD_REG 0x7F
#define DEV2_IMON_CM_LDO2_THRSHLD_REG 0x80
#define DEV2_IMON_CM_LDO3_THRSHLD_REG 0x81
#define DEV2_IMON_CM_SMPS0_THRSHLD_REG 0x82
#define DEV2_IMON_CM_SMPS1_THRSHLD_REG 0x83
#define DEV2_IMON_CM_SMPS2_THRSHLD_REG 0x84
#define DEV2_IMON_CM_SMPS3_THRSHLD_REG 0x85
#define DEV2_IMON_CM_SMPS4_THRSHLD_REG 0x86
#define DEV2_IMON_CM_SMPS5_THRSHLD_REG 0x87
#define DEV2_IMON_CM_VCC0_DATA_REG 0x88
#define DEV2_IMON_CM_VCC1_DATA_REG 0x89
#define DEV2_IMON_CM_VCC_DATA_REG 0x8A
#define DEV2_IMON_CM_VNN_DATA_REG 0x8B
#define DEV2_IMON_CM_VNNAON_DATA_REG 0x8C
#define DEV2_IMON_CM_VDD1_DATA_REG 0x8D
#define DEV2_IMON_CM_VDD2_DATA_REG 0x8E
#define DEV2_IMON_CM_VCCRAM_DATA_REG 0x8F
#define DEV2_IMON_CM_VMEM_DATA_REG 0x90
#define DEV2_IMON_CM_VFLEX_DATA_REG 0x91
#define DEV2_IMON_CM_PROG1A_DATA_REG 0x92
#define DEV2_IMON_CM_PROG1B_DATA_REG 0x93
#define DEV2_IMON_CM_PROG1C_DATA_REG 0x94
#define DEV2_IMON_CM_PROG1D_DATA_REG 0x95
#define DEV2_IMON_CM_PROG2A_DATA_REG 0x96
#define DEV2_IMON_CM_PROG2B_DATA_REG 0x97
#define DEV2_IMON_CM_PROG2C_DATA_REG 0x98
#define DEV2_IMON_CM_PROG3A_DATA_REG 0x99
#define DEV2_IMON_CM_PROG3B_DATA_REG 0x9A
#define DEV2_IMON_CM_VCC0_INT_LVL_REG 0x9B
#define DEV2_IMON_CM_VCC1_INT_LVL_REG 0x9C
#define DEV2_IMON_CM_VCC_INT_LVL_REG 0x9D
#define DEV2_IMON_CM_VNN_INT_LVL_REG 0x9E
#define DEV2_IMON_CM_VNNAON_INT_LVL_REG 0x9F
#define DEV2_IMON_CM_VDD1_INT_LVL_REG 0xA0
#define DEV2_IMON_CM_VDD2_INT_LVL_REG 0xA1
#define DEV2_IMON_CM_VCCRAM_INT_LVL_REG 0xA2
#define DEV2_IMON_CM_VMEM_INT_LVL_REG 0xA3
#define DEV2_IMON_CM_VFLEX_INT_LVL_REG 0xA4
#define DEV2_IMON_CM_VPROG1A_INT_LVL_REG 0xA5
#define DEV2_IMON_CM_VPROG1B_INT_LVL_REG 0xA6
#define DEV2_IMON_CM_VPROG1C_INT_LVL_REG 0xA7
#define DEV2_IMON_CM_VPROG1D_INT_LVL_REG 0xA8
#define DEV2_IMON_CM_VPROG2A_INT_LVL_REG 0xA9
#define DEV2_IMON_CM_VPROG2B_INT_LVL_REG 0xAA
#define DEV2_IMON_CM_VPROG2C_INT_LVL_REG 0xAB
#define DEV2_IMON_CM_VPROG3A_INT_LVL_REG 0xAC
#define DEV2_IMON_CM_VPROG3B_INT_LVL_REG 0xAD
#define DEV2_IMON_CM_VROCIRQSTAT0_REG 0xAE
#define DEV2_IMON_CM_VROCIRQSTAT1_REG 0xAF
#define DEV2_IMON_CM_VROCIRQSTAT2_REG 0xB0
#define DEV2_IMON_CM_VROCIRQSTAT3_REG 0xB1
#define DEV2_RTC_VRTCCTRL_REG 0xB5
#define DEV2_TMU_TMUIRQ_REG 0xB6
#define DEV2_TMU_MTMUIRQ_REG 0xB7
#define DEV2_TMU_TMUSTATUS_REG 0xB8
#define DEV2_TMU_TMUCONFIG_REG 0xB9
#define DEV2_TMU_SECONDS_REG 0xBA
#define DEV2_TMU_SECONDSW_REG 0xBA
#define DEV2_TMU_SECONDSSA_REG 0xBB
#define DEV2_TMU_SECONDSWA_REG 0xBC
#define DEV2_TMU_MINUTES_REG 0xBD
#define DEV2_TMU_MINUTESW_REG 0xBD
#define DEV2_TMU_MINUTESSA_REG 0xBE
#define DEV2_TMU_MINUTESWA_REG 0xBF
#define DEV2_TMU_HOURS_REG 0xC0
#define DEV2_TMU_HOURSW_REG 0xC0
#define DEV2_TMU_HOURSSA_REG 0xC1
#define DEV2_TMU_HOURSWA_REG 0xC2
#define DEV2_TMU_DWEEK_REG 0xC3
#define DEV2_TMU_DWEEKW_REG 0xC3
#define DEV2_TMU_DMONTH_REG 0xC4
#define DEV2_TMU_DMONTHW_REG 0xC4
#define DEV2_TMU_MONTH_REG 0xC5
#define DEV2_TMU_MONTHW_REG 0xC5
#define DEV2_TMU_YEAR_REG 0xC6
#define DEV2_TMU_YEARW_REG 0xC6
#define DEV2_TMU_STCB1_REG 0xC7
#define DEV2_TMU_STCB2_REG 0xC8
#define DEV2_TMU_STCB3_REG 0xC9
#define DEV2_TMU_STCB4_REG 0xCA
#define DEV2_TMU_DMONTHWA_REG 0xCB
#define DEV2_CLK_CLKCONFIG_REG 0xCC
#define DEV2_CLKGEN_FLLCTRL_REG 0xCD
#define DEV2_CLKGEN_FLLDACSH_REG 0xCE
#define DEV2_CLKGEN_FLLDACSL_REG 0xCF
#define DEV2_CLKGEN_FLLDAC_STATUSH_REG 0xD0
#define DEV2_CLKGEN_FLLDAC_STATUSL_REG 0xD1
#define DEV2_CLKGEN_FLLFRQDIV_REG 0xD2
#define DEV2_CLKGEN_CLK32CTRL_REG 0xD3
#define DEV2_GPLED_GPLEDCTRL_REG 0xDF
#define DEV2_GPLED_GPLEDFSM_REG 0xE0
#define DEV2_GPLED_GPLEDPWM_REG 0xE1
#define DEV2_INTVREF_INTVREFCTRL_REG 0xE2
#define DEV2_INTVREF_IREFTRIM_REG 0xE3
#define DEV2_INTVREF_VREFTRIM0_REG 0xE4
#define DEV2_INTVREF_VREFTRIM1_REG 0xE5
#define DEV2_COULCNT_CC_THRH_REG 0xE6
#define DEV2_COULCNT_CC_THRL_REG 0xE7
#define DEV2_COULCNT_CC_CURR_SHRTH_REG 0xE8
#define DEV2_COULCNT_CC_CURR_SHRTL_REG 0xE9
#define DEV2_COULCNT_CC_CURR_LNGH_REG 0xEA
#define DEV2_COULCNT_CC_CURR_LNGL_REG 0xEB
#define DEV2_COULCNT_CC_CTRL0_REG 0xEC
#define DEV2_COULCNT_CC_CTRL1_REG 0xED
#define DEV2_COULCNT_CC_DOWN_B3_REG 0xEE
#define DEV2_COULCNT_CC_DOWN_B2_REG 0xEF
#define DEV2_COULCNT_CC_DOWN_B1_REG 0xF0
#define DEV2_COULCNT_CC_DOWN_B0_REG 0xF1
#define DEV2_COULCNT_CC_UP_B3_REG 0xF2
#define DEV2_COULCNT_CC_UP_B2_REG 0xF3
#define DEV2_COULCNT_CC_UP_B1_REG 0xF4
#define DEV2_COULCNT_CC_UP_B0_REG 0xF5
#define DEV2_COULCNT_VBATMAXH_REG 0xF5
#define DEV2_COULCNT_VBATMAXHW_REG 0xF6
#define DEV2_COULCNT_VBATMAXL_REG 0xF6
#define DEV2_COULCNT_VBATMAXLW_REG 0xF7
#define DEV2_COULCNT_MAX_CURR_SHRTH_REG 0xF8
#define DEV2_COULCNT_MAX_CURR_SHRTL_REG 0xF9
#define DEV2_COULCNT_MAX_CURR_LNGH_REG 0xFA
#define DEV2_COULCNT_MAX_CURR_LNGL_REG 0xFB
#define DEV2_ID_PROVERSION_REG 0xFF

// DEV 3 definitions

#define DEV3_CRIT_PMICWDTCNT_REG 0x00
#define DEV3_CRIT_PMICWDTTC_REG 0x01
#define DEV3_CRIT_SCRITIRQ_REG 0x02
#define DEV3_USB_USBIDCTRL_REG 0x05
#define DEV3_USB_USBIDDETTYPE_REG 0x06
#define DEV3_USB_USBPHYCTRL_REG 0x07
#define DEV3_USB_USBRSTGPO_REG 0x08
#define DEV3_USB_USBRSTGPI_REG 0x09
#define DEV3_VCTRL_VSYSCTRL_REG 0x0C
#define DEV3_VCTRL_VOTPCTRL_REG 0x0D
#define DEV3_VCTRL_VXOCNT_REG 0x0E
#define DEV3_SVID_DEV3_STATUS_1_REG 0x10
#define DEV3_SVID_DEV3_STATUS_2_REG 0x11
#define DEV3_CHARGER_CHGDETGPO_REG 0x12
#define DEV3_CHARGER_CHGDETGPI_REG 0x13
#define DEV3_CHARGER_DBPTIMEOUT_REG 0x14
#define DEV3_CHARGER_DBPTIMER_REG 0x15
#define DEV3_CHARGER_CHGRCTRL0_REG 0x16
#define DEV3_CHARGER_CHGRCTRL1_REG 0x17
#define DEV3_CHARGER_CHGRCTRL2_REG 0x18
#define DEV3_CHARGER_CHGRSTATUS_REG 0x19
#define DEV3_CHARGER_SCHGRIRQ_REG 0x1A
#define DEV3_SVID_DEV3_STATUS2_LASTREAD_REG 0x1C
#define DEV3_CHARGER_VBUSDETCTRL_REG 0x1D
#define DEV3_CHARGER_VDCINDETCTRL_REG 0x1E
#define DEV3_CHARGER_CHRLEDCTRL_REG 0x1F
#define DEV3_CHARGER_CHRLEDFSM_REG 0x20
#define DEV3_CHARGER_CHRLEDPWM_REG 0x21
#define DEV3_CHARGER_CHRTTADDR_REG 0x22
#define DEV3_CHARGER_CHRTTDATA_REG 0x23
#define DEV3_CHARGER_I2COVRCTRL_REG 0x24
#define DEV3_CHARGER_I2COVRDADDR_REG 0x25
#define DEV3_CHARGER_I2COVROFFSET_REG 0x26
#define DEV3_CHARGER_I2COVRWRDATA_REG 0x27
#define DEV3_CHARGER_I2COVRRDDATA_REG 0x28
#define DEV3_CHARGER_USBSRCDETSTATUS0_REG 0x29
#define DEV3_CHARGER_USBSRCDETSTATUS1_REG 0x2A
#define DEV3_CHARGER_CCSMCMDSKIP_REG 0x2B
#define DEV3_CHARGER_CCSMSFTTIMER_REG 0x2C
#define DEV3_CHARGER_SCCSMSFTTIMER_REG 0x2D
#define DEV3_CHARGER_CHGRCTRL3_REG 0x2E
#define DEV3_CHARGER_CHGDISCTRL_REG 0x2F
#define DEV3_TLP_TLP1CTRL_REG 0x30
#define DEV3_TLP_TLP1EVSTATUS0_REG 0x31
#define DEV3_TLP_TLP1EVSTATUS1_REG 0x32
#define DEV3_TLP_TLP1EVSTATUS2_REG 0x33
#define DEV3_TLP_TLP1EVSTATUS3_REG 0x34
#define DEV3_SVID_DEV3_SETREGADR_REG 0x35
#define DEV3_TLP_TLP1TRACEINSTH_REG 0x36
#define DEV3_TLP_TLP1TRACEINSTL_REG 0x37
#define DEV3_TLP_TLP1INSTMEMADDRH_REG 0x38
#define DEV3_TLP_TLP1INSTMEMADDRL_REG 0x39
#define DEV3_TLP_TLP1INSTMEMDATAH_REG 0x3A
#define DEV3_TLP_TLP1INSTMEMDATAHW_REG 0x3A
#define DEV3_TLP_TLP1INSTMEMDATAL_REG 0x3B
#define DEV3_TLP_TLP1COLDBOOTH_REG 0x3C
#define DEV3_TLP_TLP1COLDBOOTL_REG 0x3D
#define DEV3_TLP_TLP1COLDOFFH_REG 0x3E
#define DEV3_TLP_TLP1COLDOFFL_REG 0x3F
#define DEV3_TLP_TLP1COLDRSTH_REG 0x40
#define DEV3_TLP_TLP1COLDRSTL_REG 0x41
#define DEV3_TLP_TLP1WARMRSTH_REG 0x42
#define DEV3_TLP_TLP1WARMRSTL_REG 0x43
#define DEV3_TLP_TLP1ESBS0I1H_REG 0x44
#define DEV3_TLP_TLP1ESBS0I1L_REG 0x45
#define DEV3_TLP_TLP1ESBS0I1VNNH_REG 0x46
#define DEV3_TLP_TLP1ESBS0I1VNNL_REG 0x47
#define DEV3_TLP_TLP1ESBS0I1VNNLPH_REG 0x48
#define DEV3_TLP_TLP1ESBS0I1VNNLPL_REG 0x49
#define DEV3_TLP_TLP1ESBS0I2H_REG 0x4A
#define DEV3_TLP_TLP1ESBS0I2L_REG 0x4B
#define DEV3_TLP_TLP1ESBS0I3H_REG 0x4C
#define DEV3_TLP_TLP1ESBS0I3L_REG 0x4D
#define DEV3_TLP_TLP1ESBS0I3LPH_REG 0x4E
#define DEV3_TLP_TLP1ESBS0I3LPL_REG 0x4F
#define DEV3_TLP_TLP1EXSBH_REG 0x50
#define DEV3_TLP_TLP1EXSBL_REG 0x51
#define DEV3_TLP_TLP1ESBS0IXH_REG 0x52
#define DEV3_TLP_TLP1ESBS0IXL_REG 0x53
#define DEV3_TLP_TLP1ESBS3H_REG 0x54
#define DEV3_TLP_TLP1ESBS3L_REG 0x55
#define DEV3_TLP_TLP1EXSBS0IXH_REG 0x56
#define DEV3_TLP_TLP1EXSBS0IXL_REG 0x57
#define DEV3_TLP_TLP1EXSBS3H_REG 0x58
#define DEV3_TLP_TLP1EXSBS3L_REG 0x59
#define DEV3_TLP_TLP1MODEMRSTH_REG 0x5A
#define DEV3_TLP_TLP1MODEMRSTL_REG 0x5B
#define DEV3_TLP_TLP1VRSETTLED_REG 0x5C
#define DEV3_TLP_TLP2CTRL_REG 0x61
#define DEV3_TLP_TLP2EVSTATUS_REG 0x62
#define DEV3_TLP_TLP2TRACEINST_REG 0x63
#define DEV3_TLP_TLP2INSTMEMADDR_REG 0x64
#define DEV3_TLP_TLP2INSTMEMDATA_REG 0x65
#define DEV3_TLP_TLP2SYSTEMP_REG 0x66
#define DEV3_TLP_TLP2BATTID_REG 0x67
#define DEV3_TLP_TLP2BATTV_REG 0x68
#define DEV3_TLP_TLP2USBID_REG 0x69
#define DEV3_TLP_TLP2PEAK_REG 0x6A
#define DEV3_TLP_TLP2GPMEAS_REG 0x6B
#define DEV3_IMON_CM_VPROG1E_MODE_CTRL_REG 0x70
#define DEV3_IMON_CM_VPROG1F_MODE_CTRL_REG 0x71
#define DEV3_IMON_CM_VPROG2D_MODE_CTRL_REG 0x72
#define DEV3_IMON_CM_VPROG4A_MODE_CTRL_REG 0x73
#define DEV3_IMON_CM_VPROG4B_MODE_CTRL_REG 0x74
#define DEV3_IMON_CM_VPROG4C_MODE_CTRL_REG 0x75
#define DEV3_IMON_CM_VPROG4D_MODE_CTRL_REG 0x76
#define DEV3_IMON_CM_VPROG5A_MODE_CTRL_REG 0x77
#define DEV3_IMON_CM_VPROG5B_MODE_CTRL_REG 0x78
#define DEV3_IMON_CM_VPROG6A_MODE_CTRL_REG 0x79
#define DEV3_IMON_CM_VPROG6B_MODE_CTRL_REG 0x7A
#define DEV3_IMON_CM_VPROG7A_MODE_CTRL_REG 0x7B
#define DEV3_IMON_CM_LDO4_THRSHLD_REG 0x81
#define DEV3_IMON_CM_LDO5_THRSHLD_REG 0x82
#define DEV3_IMON_CM_LDO6_THRSHLD_REG 0x83
#define DEV3_IMON_CM_PROG1E_DATA_REG 0x86
#define DEV3_IMON_CM_PROG1F_DATA_REG 0x87
#define DEV3_IMON_CM_PROG2D_DATA_REG 0x88
#define DEV3_IMON_CM_PROG4A_DATA_REG 0x89
#define DEV3_IMON_CM_PROG4B_DATA_REG 0x8A
#define DEV3_IMON_CM_PROG4C_DATA_REG 0x8B
#define DEV3_IMON_CM_PROG4D_DATA_REG 0x8C
#define DEV3_IMON_CM_PROG5A_DATA_REG 0x8D
#define DEV3_IMON_CM_PROG5B_DATA_REG 0x8E
#define DEV3_IMON_CM_PROG6A_DATA_REG 0x8F
#define DEV3_IMON_CM_PROG6B_DATA_REG 0x90
#define DEV3_IMON_CM_PROG7A_DATA_REG 0x91
#define DEV3_IMON_CM_VPROG1E_INT_LVL_REG 0x97
#define DEV3_IMON_CM_VPROG1F_INT_LVL_REG 0x98
#define DEV3_IMON_CM_VPROG2D_INT_LVL_REG 0x99
#define DEV3_IMON_CM_VPROG4A_INT_LVL_REG 0x9A
#define DEV3_IMON_CM_VPROG4B_INT_LVL_REG 0x9B
#define DEV3_IMON_CM_VPROG4C_INT_LVL_REG 0x9C
#define DEV3_IMON_CM_VPROG4D_INT_LVL_REG 0x9D
#define DEV3_IMON_CM_VPROG5A_INT_LVL_REG 0x9E
#define DEV3_IMON_CM_VPROG5B_INT_LVL_REG 0x9F
#define DEV3_IMON_CM_VPROG6A_INT_LVL_REG 0xA0
#define DEV3_IMON_CM_VPROG6B_INT_LVL_REG 0xA1
#define DEV3_IMON_CM_VPROG7A_INT_LVL_REG 0xA2

// DEV 4 definitions

#define DEV4_SVID_DEV4_STATUS_1_REG 0x10
#define DEV4_SVID_DEV4_STATUS_2_REG 0x11
#define DEV4_SVID_DEV4_STATUS2_LASTREAD_REG 0x1C
#define DEV4_SVID_DEV4_SETREGADR_REG 0x35
#define DEV4_VENDOR_VENDCTL0_REG 0x36
#define DEV4_VENDOR_VENDCTL1_REG 0x37
#define DEV4_VENDOR_VENDCTL2_REG 0x38
#define DEV4_VENDOR_VENDCTL3_REG 0x39
#define DEV4_VENDOR_NVM_MB_ADDRH_REG 0x3A
#define DEV4_VENDOR_NVM_MB_ADDRL_REG 0x3B
#define DEV4_VENDOR_NVM_MB_DATA_REG 0x3C
#define DEV4_VENDOR_NVMDBUF0_REG 0x3D
#define DEV4_VENDOR_NVMDBUF1_REG 0x3E
#define DEV4_VENDOR_NVMDBUF2_REG 0x3F
#define DEV4_VENDOR_NVMDBUF3_REG 0x40
#define DEV4_VENDOR_NVMDBUF4_REG 0x41
#define DEV4_VENDOR_NVMDBUF5_REG 0x42
#define DEV4_VENDOR_NVMDBUF6_REG 0x43
#define DEV4_VENDOR_NVMDBUF7_REG 0x44
#define DEV4_VENDOR_NVMDBUF8_REG 0x45
#define DEV4_VENDOR_NVMDBUF9_REG 0x46
#define DEV4_VENDOR_NVMDBUF10_REG 0x47
#define DEV4_VENDOR_NVMDBUF11_REG 0x48
#define DEV4_VENDOR_NVMDBUF12_REG 0x49
#define DEV4_VENDOR_NVMDBUF13_REG 0x4A
#define DEV4_VENDOR_NVMDBUF14_REG 0x4B
#define DEV4_VENDOR_NVMDBUF15_REG 0x4C
#define DEV4_VENDOR_NVMDBUF16_REG 0x4D
#define DEV4_VENDOR_NVMDBUF17_REG 0x4E
#define DEV4_VENDOR_NVMDBUF18_REG 0x4F
#define DEV4_VENDOR_NVMDBUF19_REG 0x50
#define DEV4_VENDOR_NVMDBUF20_REG 0x51
#define DEV4_VENDOR_NVMDBUF21_REG 0x52
#define DEV4_VENDOR_NVMDBUF22_REG 0x53
#define DEV4_VENDOR_NVMDBUF23_REG 0x54
#define DEV4_VENDOR_NVMDBUF24_REG 0x55
#define DEV4_VENDOR_NVMDBUF25_REG 0x56
#define DEV4_VENDOR_NVMDBUF26_REG 0x57
#define DEV4_VENDOR_NVMDBUF27_REG 0x58
#define DEV4_VENDOR_NVMDBUF28_REG 0x59
#define DEV4_VENDOR_NVMDBUF29_REG 0x5A
#define DEV4_VENDOR_NVMDBUF30_REG 0x5B
#define DEV4_VENDOR_NVMDBUF31_REG 0x5C
#define DEV4_VENDOR_NVMDBUF32_REG 0x5D
#define DEV4_VENDOR_NVMDBUF33_REG 0x5E
#define DEV4_VENDOR_NVMCTL0_REG 0x5F
#define DEV4_VENDOR_NVMCTL1_REG 0x60
#define DEV4_VENDOR_OTPMR_REG 0x61
#define DEV4_VENDOR_OTPMRA_RD1_REG 0x62
#define DEV4_VENDOR_OTPMRA_RD2_REG 0x63
#define DEV4_VENDOR_OTPMRB0_RD1_REG 0x64
#define DEV4_VENDOR_OTPMRB0_RD2_REG 0x65
#define DEV4_VENDOR_OTPMRB1_REG 0x66
#define DEV4_VENDOR_NVMSTAT0_REG 0x67
#define DEV4_VENDOR_SOAKING_STAT0_REG 0x68
#define DEV4_VENDOR_SOAKING_STAT1_REG 0x69
#define DEV4_VENDOR_NVM_USAGE_STATH_REG 0x6A
#define DEV4_VENDOR_NVM_USAGE_STATL_REG 0x6B
#define DEV4_VENDOR_CODSRC_REG 0x6C
#define DEV4_VENDOR_ISOCTRL_REG 0x6D
#define DEV4_VENDOR_OTPCONFIG_REG 0x6E
#define DEV4_VIRQ_VENDIRQLVL1_REG 0x77
#define DEV4_VIRQ_NVMVIRQ_REG 0x78
#define DEV4_VIRQ_ADCTLP2VIRQ_REG 0x79
#define DEV4_VIRQ_I2CSIFVIRQ_REG 0x7A
#define DEV4_VIRQ_REGBUSVIRQ_REG 0x7B
#define DEV4_VIRQ_CHGRVIRQ_REG 0x7C
#define DEV4_VIRQ_TLP1VIRQ_REG 0x7D
#define DEV4_VIRQ_DCDCVIRQ0_REG 0x7E
#define DEV4_VIRQ_DCDCVIRQ1_REG 0x7F
#define DEV4_VIRQ_VROCIRQ0_REG 0x80
#define DEV4_VIRQ_VROCIRQ1_REG 0x81
#define DEV4_VIRQ_VROCIRQ2_REG 0x82
#define DEV4_VIRQ_VROCIRQ3_REG 0x83
#define DEV4_VIRQ_MVENDIRQLVL1_REG 0x84
#define DEV4_VIRQ_MNVMVIRQ_REG 0x85
#define DEV4_VIRQ_MADCTLP2VIRQ_REG 0x86
#define DEV4_VIRQ_MI2CSIFVIRQ_REG 0x87
#define DEV4_VIRQ_MREGBUSVIRQ_REG 0x88
#define DEV4_VIRQ_MCHGRVIRQ_REG 0x89
#define DEV4_VIRQ_MTLP1VIRQ_REG 0x8A
#define DEV4_VIRQ_MDCDCVIRQ0_REG 0x8B
#define DEV4_VIRQ_MDCDCVIRQ1_REG 0x8C
#define DEV4_VIRQ_MVROCIRQ0_REG 0x8D
#define DEV4_VIRQ_MVROCIRQ1_REG 0x8E
#define DEV4_VIRQ_MVROCIRQ2_REG 0x8F
#define DEV4_VIRQ_MVROCIRQ3_REG 0x90
#define DEV4_VIRQ_M_VEND_INT_REG 0x91
#define DEV4_VIRQ_VROCIRQ4_REG 0x92
#define DEV4_VIRQ_MVROCIRQ4_REG 0x93
#define DEV4_TEST_TST_STARTUP_REG 0x9A
#define DEV4_TEST_TST_FREQ_DIV0_REG 0x9B
#define DEV4_TEST_TST_FREQ_DIV1_REG 0x9C
#define DEV4_TEST_TST_FREQ_SEL0_REG 0x9D
#define DEV4_TEST_TST_FREQ_SEL1_REG 0x9E
#define DEV4_TEST_TST_COUNT_CTRL0_REG 0x9F
#define DEV4_TEST_TST_COUNT_CTRL1_REG 0xA0
#define DEV4_TEST_TST_COUNT0_TIME_REG 0xA1
#define DEV4_TEST_TST_COUNT1_TIME_REG 0xA2
#define DEV4_TEST_TST_COUNT0_REG 0xA3
#define DEV4_TEST_TST_COUNT1_REG 0xA4
#define DEV4_TEST_TST_VINMON_REG 0xA5
#define DEV4_TEST_TST_VINMONRSLT_REG 0xA6
#define DEV4_TEST_TST_SRCDET0_REG 0xA7
#define DEV4_TEST_TST_SRCDET1_REG 0xA8
#define DEV4_TEST_TST_USB_REG 0xA9
#define DEV4_TEST_TST_VSWITCH0_REG 0xAA
#define DEV4_TEST_TST_VSWITCH1_REG 0xAB
#define DEV4_TEST_VUSBPHY_CP_REG 0xAC
#define DEV4_TEST_VUSBPHY_CP_VOUT_REG 0xAD
#define DEV4_TEST_TST_ATE_STRTUP_REG 0xAE
#define DEV4_TEST_GPADC_TEST0_REG 0xAF
#define DEV4_TEST_GPADC_TEST1_REG 0xB0
#define DEV4_TEST_GPADC_PKTST_REG 0xB1
#define DEV4_TEST_COMPTEST0_REG 0xB2
#define DEV4_TEST_COMPTEST1_REG 0xB3
#define DEV4_TEST_TST_ATE_CFG_REG 0xB4
#define DEV4_TEST_TST_ATE_REF0_REG 0xB5
#define DEV4_TEST_TST_ATE_REF1_REG 0xB6
#define DEV4_DEBUG_PMICSPARE01_AO_REG 0xC0
#define DEV4_DEBUG_PMICSPARE02_AI_REG 0xC1
#define DEV4_DEBUG_PMICSPARE03_AO_REG 0xC2
#define DEV4_DEBUG_PMICSPARE04_AI_REG 0xC3
#define DEV4_DEBUG_PMICSPARE05_REG 0xC4
#define DEV4_DEBUG_PMICSPARE06_REG 0xC5
#define DEV4_DEBUG_PMICSPARE07_REG 0xC6
#define DEV4_DEBUG_PMICSPARE08_REG 0xC7
#define DEV4_DEBUG_PMICSPARE09_REG 0xC8
#define DEV4_DEBUG_PMICSPARE10_REG 0xC9
#define DEV4_DEBUG_PMICSPARE11_REG 0xCA
#define DEV4_DEBUG_PMICSPARE12_REG 0xCB
#define DEV4_DEBUG_I2C_HS_TIMING_REG 0xCC
#define DEV4_DEBUG_DBGMON1_BLK_SEL_REG 0xCD
#define DEV4_DEBUG_DBGMON1_SIG_SEL_REG 0xCE
#define DEV4_DEBUG_DBGMON2_BLK_SEL_REG 0xCF
#define DEV4_DEBUG_DBGMON2_SIG_SEL_REG 0xD0
#define DEV4_DEBUG_DBGMON3_BLK_SEL_REG 0xD1
#define DEV4_DEBUG_DBGMON3_SIG_SEL_REG 0xD2
#define DEV4_DEBUG_DBGMON4_BLK_SEL_REG 0xD3
#define DEV4_DEBUG_DBGMON4_SIG_SEL_REG 0xD4
#define DEV4_DEBUG_PMICDBGCTRL1_REG 0xD5
#define DEV4_DEBUG_PMICDBGCTRL2_REG 0xD6
#define DEV4_DEBUG_REGBUS_ERR_CTL_REG 0xD7
#define DEV4_DEBUG_REGBUS_ERR_STATUS_REG 0xD8
#define DEV4_DEBUG_REGBUS_ERR_ADDRH_REG 0xD9
#define DEV4_DEBUG_REGBUS_ERR_ADDRL_REG 0xDA
#define DEV4_DEBUG_ANAMON0CTL0_REG 0xDB
#define DEV4_DEBUG_ANAMON0CTL1_REG 0xDC
#define DEV4_DEBUG_ANAMON1CTL0_REG 0xDD
#define DEV4_DEBUG_ANAMON1CTL1_REG 0xDE
#define DEV4_DEBUG_VCOMPTEST_REG 0xDF
#define DEV4_DEBUG_DBG_USBBC1_REG 0xE0
#define DEV4_DEBUG_DBG_USBBC2_REG 0xE1
#define DEV4_DEBUG_DBG_USBBCSTAT_REG 0xE2
#define DEV4_DEBUG_ANAMON2CTL0_REG 0xE3
#define DEV4_DEBUG_ANAMON2CTL1_REG 0xE4

// DEV5 definitions

#define DEV5_ID_ID0_REG 0x00
#define DEV5_ID_ID1_REG 0x01
#define DEV5_IRQ_IRQLVL1_REG 0x02
#define DEV5_IRQ_PWRSRCIRQ_REG 0x03
#define DEV5_IRQ_THRMIRQ0_REG 0x04
#define DEV5_IRQ_THRMIRQ1_REG 0x05
#define DEV5_IRQ_THRMIRQ2_REG 0x06
#define DEV5_IRQ_BCUIRQ_REG 0x07
#define DEV5_IRQ_ADCIRQ_REG 0x08
#define DEV5_IRQ_CHGRIRQ_REG 0x0A
#define DEV5_IRQ_GPIO0IRQ_REG 0x0B
#define DEV5_IRQ_GPIO1IRQ_REG 0x0C
#define DEV5_IRQ_MTHRMIRQ0_REG 0x0D
#define DEV5_IRQ_MIRQLVL1_REG 0x0E
#define DEV5_IRQ_MPWRSRCIRQ_REG 0x0F
#define DEV5_SVID_DEV5_STATUS_1_REG 0x10
#define DEV5_SVID_DEV5_STATUS_2_REG 0x11
#define DEV5_IRQ_MTHRMIRQ1_REG 0x12
#define DEV5_IRQ_MTHRMIRQ2_REG 0x13
#define DEV5_IRQ_MBCUIRQ_REG 0x14
#define DEV5_IRQ_MADCIRQ_REG 0x15
#define DEV5_IRQ_MCHGRIRQ_REG 0x17
#define DEV5_IRQ_MGPIO0IRQ_REG 0x19
#define DEV5_IRQ_MGPIO1IRQ_REG 0x1A
#define DEV5_SVID_DEV5_STATUS2_LASTREAD_REG 0x1C
#define DEV5_PWRSRC_SPWRSRC_REG 0x1E
#define DEV5_EXTCTRL_REGLOCK_REG 0x1F
#define DEV5_RESET_RESETSRC0_REG 0x20
#define DEV5_RESET_RESETSRC1_REG 0x21
#define DEV5_WAKE_WAKESRC_REG 0x22
#define DEV5_PWRSRC_LOWBATTDET0_REG 0x23
#define DEV5_PWRSRC_LOWBATTDET1_REG 0x24
#define DEV5_PWRSRC_PSDETCTRL_REG 0x25
#define DEV5_PB_PBCONFIG1_REG 0x26
#define DEV5_PB_PBSTATUS_REG 0x27
#define DEV5_PB_UBSTATUS_REG 0x28
#define DEV5_EXTCTRL_MODEMCTRL_REG 0x29
#define DEV5_EXTCTRL_BBCHGRCFG_REG 0x2A
#define DEV5_GPIO_GPIO0P0CTLO_REG 0x2B
#define DEV5_GPIO_GPIO0P1CTLO_REG 0x2C
#define DEV5_GPIO_GPIO0P2CTLO_REG 0x2D
#define DEV5_GPIO_GPIO0P3CTLO_REG 0x2E
#define DEV5_GPIO_GPIO0P5CTLO_REG 0x30
#define DEV5_GPIO_GPIO0P6CTLO_REG 0x31
#define DEV5_GPIO_GPIO0P0CTLI_REG 0x33
#define DEV5_GPIO_GPIO0P2CTLI_REG 0x34
#define DEV5_SVID_DEV5_SETREGADR_REG 0x35
#define DEV5_GPIO_GPIO0P3CTLI_REG 0x36
#define DEV5_IRQ_CRITIRQ_REG 0x37
#define DEV5_GPIO_GPIO0P5CTLI_REG 0x38
#define DEV5_GPIO_GPIO0P6CTLI_REG 0x39
#define DEV5_GPIO_GPIO1P0CTLO_REG 0x3B
#define DEV5_GPIO_GPIO1P1CTLO_REG 0x3C
#define DEV5_GPIO_GPIO1P0CTLI_REG 0x43
#define DEV5_GPIO_GPIO1P1CTLI_REG 0x44
#define DEV5_RESET_COLDRST_REG 0x53
#define DEV5_VREG_V1P8ACNT_REG 0x56
#define DEV5_VREG_V1P8SXCNT_REG 0x57
#define DEV5_VREG_VDDQCNT_REG 0x58
#define DEV5_VREG_V1P2ACNT_REG 0x59
#define DEV5_VREG_V1P2SXCNT_REG 0x5A
#define DEV5_VREG_V1P8AVSEL_REG 0x5B
#define DEV5_VREG_VDDQVSEL_REG 0x5C
#define DEV5_VREG_V2P8SXCNT_REG 0x5D
#define DEV5_VREG_V3P3ACNT_REG 0x5E
#define DEV5_VREG_V3P3SDCNT_REG 0x5F
#define DEV5_VREG_VNNCNT_REG 0x63
#define DEV5_VREG_VCC0CNT_REG 0x64
#define DEV5_VREG_VCC1CNT_REG 0x65
#define DEV5_VREG_VGGCNT_REG 0x66
#define DEV5_VREG_VSDIOCNT_REG 0x67
#define DEV5_VREG_V3P3AVSEL_REG 0x68
#define DEV5_VREG_VLDOCNT_REG 0x69
#define DEV5_VREG_VSWITCHCNT0_REG 0x6A
#define DEV5_VREG_VSWITCHCNT1_REG 0x6C
#define DEV5_ID_FWREV_REG 0x6D
#define DEV5_WAKE_SRCWAKECFG_REG 0x8B
#define DEV5_VREG_VPROG1ACNT_REG 0x90
#define DEV5_VREG_VPROG1BCNT_REG 0x91
#define DEV5_VREG_VPROG1FCNT_REG 0x95
#define DEV5_VREG_VPROG2DCNT_REG 0x99
#define DEV5_VREG_VPROG3ACNT_REG 0x9A
#define DEV5_VREG_VPROG3BCNT_REG 0x9B
#define DEV5_VREG_VPROG4ACNT_REG 0x9C
#define DEV5_VREG_VPROG4BCNT_REG 0x9D
#define DEV5_VREG_VPROG4CCNT_REG 0x9E
#define DEV5_VREG_VPROG4DCNT_REG 0x9F
#define DEV5_VREG_VPROG5ACNT_REG 0xA0
#define DEV5_VREG_VPROG5BCNT_REG 0xA1
#define DEV5_VREG_VPROG6ACNT_REG 0xA2
#define DEV5_VREG_VPROG6BCNT_REG 0xA3
#define DEV5_VREG_VPROG7ACNT_REG 0xA4
#define DEV5_BCU_VWARNA_CFG_REG 0xB4
#define DEV5_BCU_VWARNB_CFG_REG 0xB5
#define DEV5_BCU_VCRIT_CFG_REG 0xB6
#define DEV5_BCU_BCUDISB_BEH_REG 0xB8
#define DEV5_BCU_BCUDISCRIT_BEH_REG 0xB9
#define DEV5_BCU_BCUVSYS_DRP_BEH_REG 0xBA
#define DEV5_BCU_SBCUIRQ_REG 0xBB
#define DEV5_BCU_SBCUCTRL_REG 0xBC
#define DEV5_VREG_VPROG1AVSEL_REG 0xC0
#define DEV5_VREG_VPROG1BVSEL_REG 0xC1
#define DEV5_VREG_V1P8SXVSEL_REG 0xC2
#define DEV5_VREG_V1P2SXVSEL_REG 0xC3
#define DEV5_VREG_V1P2AVSEL_REG 0xC4
#define DEV5_VREG_VPROG1FVSEL_REG 0xC5
#define DEV5_VREG_VSDIOVSEL_REG 0xC6
#define DEV5_VREG_V2P8SXVSEL_REG 0xC7
#define DEV5_VREG_V3P3SDVSEL_REG 0xC8
#define DEV5_VREG_VPROG2DVSEL_REG 0xC9
#define DEV5_VREG_VPROG3AVSEL_REG 0xCA
#define DEV5_VREG_VPROG3BVSEL_REG 0xCB
#define DEV5_VREG_VPROG4AVSEL_REG 0xCC
#define DEV5_VREG_VPROG4BVSEL_REG 0xCD
#define DEV5_VREG_VPROG4CVSEL_REG 0xCE
#define DEV5_VREG_VPROG4DVSEL_REG 0xCF
#define DEV5_VREG_VPROG5AVSEL_REG 0xD0
#define DEV5_VREG_VPROG5BVSEL_REG 0xD1
#define DEV5_VREG_VPROG6AVSEL_REG 0xD2
#define DEV5_VREG_VPROG6BVSEL_REG 0xD3
#define DEV5_VREG_VPROG7AVSEL_REG 0xD4
#define DEV5_IRQ_THRMIRQ3_REG 0xD9
#define DEV5_IRQ_MTHRMIRQ3_REG 0xDA
#define DEV5_PB_PBCONFIG2_REG 0xDB
#define DEV5_PMON_PSOCMONCTL_REG 0xDC
#define DEV5_PMON_PSOCRSLTH_REG 0xDD
#define DEV5_PMON_PSOCRSLTL_REG 0xDE
#define DEV5_PMON_SOC_PALERTH_REG 0xE3
#define DEV5_PMON_SOC_PALERTL_REG 0xE4
#define DEV5_WAKE_WAKESRC2_REG 0xE5
#define DEV5_WAKE_SPLTIMER_REG 0xE6
#define DEV5_WAKE_SSPLTIMER_REG 0xE7
#define DEV5_PWRSRC_BATTDETCTRL0_REG 0xF0
#define DEV5_PWRSRC_BATTDETCTRL1_REG 0xF1
#define DEV5_EXTCTRL_SOCCTRL_REG 0xF8
#define DEV5_IRQ_MCRITIRQ_REG 0xFA
#define DEV5_BCU_ICCMAXVCC_CFG_REG 0xFB
#define DEV5_BCU_ICCMAXVNN_CFG_REG 0xFC
#define DEV5_BCU_ICCMAXVGG_CFG_REG 0xFD
#define DEV5_IRQ_MSVIDALERT_REG 0xFE

/*
USB Type C PD controller I2C and register definitions
ToDo -- Move to EM code space 
*/

#define USB_TYPEC_PD_CHANNEL_NUMBER 0x0
#define USB_TYPEC_PD_SLAVE_ADDRESS  0x22
#define USB_TYPEC_PD_POWER_REG      0x0B
#define USB_TYPEC_PD_SWITCH0_REG    0x02
#define USB_TYPEC_PD_MASK0_REG      0x0A
#define USB_TYPEC_PD_STS_REG        0x40
#define USB_TYPEC_PD_INTR_REG       0x42

typedef struct _WC_PMIC_CONFIGURATION {
	UINT8 Offset;
    UINT8 Value;
}WC_PMIC_CONFIGURATION;

EFI_STATUS ConfigureWcPmicDev2();

EFI_STATUS ConfigureWcPmicDev5();

/*
For DDR3L memory
Sequence needs to happen before MRC init.

Write to DEV5_VDDQVSEL_REG to change voltage from 1.24V to 1.35V.
->Write 0x6E to offset 0x5C
Enable V1P2A LDO
->Write 0x01 to DEV_V1P2ACNT_REG
*/
EFI_STATUS
EFIAPI
VGGWrite (
  IN UINT8    Register,
  IN UINT8    Value
  );

UINT8
EFIAPI
WcPmicRead8 (
  IN      UINT8                     Register
  );

EFI_STATUS
EFIAPI
WcPmicWrite8 (
  IN      UINT8                     Register,
  IN      UINT8                     Value
  );

EFI_STATUS
EFIAPI
WcPmicThermInit (void);

EFI_STATUS
EFIAPI
WcPmicGpioInit (void);

EFI_STATUS
EFIAPI
WcPmicIntrInit (void);

EFI_STATUS
EFIAPI
WcPmicBcuInit (void);

EFI_STATUS
EFIAPI
WcPmicMiscInit (void);

EFI_STATUS
EFIAPI
WcPmicPage0Init (void *Profile);

UINT8
EFIAPI
WcPmicRead8_page0 (
  IN      UINT8                     Register
  );

EFI_STATUS
EFIAPI
WcPmicWrite8_page0 (
  IN      UINT8                     Register,
  IN      UINT8                     Value
  );

EFI_STATUS
EFIAPI
WcPmicVbusControl (BOOLEAN bTurnOn);

EFI_STATUS
EFIAPI
WcPmicVhostControl (BOOLEAN bTurnOn);

EFI_STATUS
EFIAPI
WcPmicGetDevID (UINT8 *DevId, UINT8 *RevId);

UINT16
EFIAPI
WcPmicGetBATID (void);

UINT8
EFIAPI
WcPmicGetBoardID(void);

UINT8
EFIAPI
WcPmicGetMemCfgID(void);

UINT8
EFIAPI
WcPmicGetFABID(void);

UINT16
EFIAPI
WcPmicGetVBAT (void);

BOOLEAN
EFIAPI
WcPmicIsACOn (void);

BOOLEAN
EFIAPI
WcPmicIsPwrBtnPressed(void);

BOOLEAN
EFIAPI
WcPmicIsUIBtnPressed(void);

UINT16
EFIAPI
WcPmicGetResetCause (void);

VOID
EFIAPI
WcPmicClearResetCause (void);

EFI_STATUS
EFIAPI
WcPmicGetWakeCause (IN OUT UINT8 *WakeCause);

VOID
EFIAPI
WcPmicClearWakeCause (void);

EFI_STATUS
EFIAPI
WcPmicDebugRegDump (void);

BOOLEAN
EFIAPI
WcPmicIsUsbConnected (void);

BOOLEAN
EFIAPI
WcPmicIsBatOn (void);

EFI_STATUS
EFIAPI
WcPmicSetVDDQ (void);

EFI_STATUS
EFIAPI
WcPmicGpioToggleForLpcConfig(void);

VOID
WcPmicForceOffModem (
  VOID
  );

EFI_STATUS
EFIAPI
WcPmicBatchRegisterInit (
  IN      RegInit_st               *RegInit,
  IN      UINT32                    length
  );

EFI_STATUS
EFIAPI
WcPmicSetVIDDecayWA (void);

VOID
WcProgramPunitPwrConfigRegisters (
  VOID
  );

EFI_STATUS
EFIAPI
WcPmicNVMUpdate(void);

#endif
