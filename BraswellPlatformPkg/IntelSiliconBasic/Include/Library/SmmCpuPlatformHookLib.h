/** @file
  Public include file for the SMM CPU Platform Hook Library.

  Copyright (c) 2010 - 2015, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __SMM_CPU_PLATFORM_HOOK_LIB_H__
#define __SMM_CPU_PLATFORM_HOOK_LIB_H__

/**
  Checks if platform produces a valid SMI.

  This function checks if platform produces a valid SMI. This function is
  called at SMM entry to detect if this is a spurious SMI. This function
  must be implemented in an MP safe way because it is called by multiple CPU
  threads.

  @retval TRUE              There is a valid SMI
  @retval FALSE             There is no valid SMI

**/
BOOLEAN
EFIAPI
PlatformValidSmi (
  VOID
  );

/**
  Clears platform top level SMI status bit.

  This function clears platform top level SMI status bit.

  @retval TRUE              The platform top level SMI status is cleared.
  @retval FALSE             The paltform top level SMI status cannot be cleared.

**/
BOOLEAN
EFIAPI
ClearTopLevelSmiStatus (
  VOID
  );

/**
  Performs platform specific way of SMM BSP election.

  This function performs platform specific way of SMM BSP election.

  @param[out] IsBsp             Output parameter. TRUE: the CPU this function executes
                                on is elected to be the SMM BSP. FALSE: the CPU this 
                                function executes on is to be SMM AP.

  @retval     EFI_SUCCESS       The function executes successfully.
  @retval     EFI_NOT_READY     The function does not determine whether this CPU should be
                                BSP or AP. This may occur if hardware init sequence to
                                enable the determination is yet to be done, or the function
                                chooses not to do BSP election and will let SMM CPU driver to
                                use its default BSP election process.
  @retval     EFI_DEVICE_ERROR  The function cannot determine whether this CPU should be
                                BSP or AP due to hardware error.

**/
EFI_STATUS
EFIAPI
PlatformSmmBspElection (
  OUT BOOLEAN     *IsBsp
  );

typedef enum {
    SmmPageSize4K,
    SmmPageSize2M,
    SmmPageSize1G,
    MaxSmmPageSizeType
} SMM_PAGE_SIZE_TYPE;

/**
  Get platform page table attribute.

  This function gets page table attribute of platform.

  @param[in]      Address          Obtain the page table entries attribute on this address.
  @param[in][out] PageSize         The size of the page.
  @param[in][out] NumOfPages       Number of page.
  @param[in][out] PageAttribute    Paging Attributes (WB, UC, etc).

  @retval         EFI_SUCCESS      The platform page table attribute from the address is determined.
  @retval         EFI_UNSUPPORTED  The paltform not supoort to get page table attribute from the address.

**/
EFI_STATUS
EFIAPI
GetPlatformPageTableAttribute (
  IN  UINT64                Address,
  OUT SMM_PAGE_SIZE_TYPE    *PageSize,
  OUT UINTN                 *NumOfPages,
  OUT UINTN                 *PageAttribute
  );

#endif
