/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 2/4/2023 07:21 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType HeightStatus, SlideStatus, InclineStatus;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	
	/* Data Receive Points */
	HeightStatus = Rte_Read_rpSeatCtrlData_Height(&Height);
	InclineStatus = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	SlideStatus = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	
	if(Height == 0 || HeightStatus == NOT_UPDATED || HeightStatus == TIMEOUT)
	{
		HeightBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Height == 1)
	{
		HeightBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Height == 2)
	{
		HeightBtnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		// ERROR
	}

	if(Slide == 0 || SlideStatus == NOT_UPDATED || SlideStatus == TIMEOUT)
	{
		SlideBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Slide == 1)
	{
		SlideBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Slide == 2)
	{
		SlideBtnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		// ERROR
	}

	if(Incline == 0 || InclineStatus == NOT_UPDATED || InclineStatus == TIMEOUT)
	{
		InclineBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Incline == 1)
	{
		InclineBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Incline == 2)
	{
		InclineBtnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		// ERROR
	}

	/* Data Send Points */
	Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
}

