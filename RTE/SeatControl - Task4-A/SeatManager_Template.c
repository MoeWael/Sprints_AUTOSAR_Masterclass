/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 2/13/2023 08:44 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


static boolean AutoStateMachine(SensorWeightType Weight,SensorPositionType Position,StepMotorStepType* Step)
{
	boolean PerformAdjust = FALSE;

	switch (Position)
	{
		case SENSOR_POSITION_STEP_0:
		{
			if(Weight < 60)
			{
				// Do nothing
			}
			else if(Weight >= 60 && Weight < 80)
			{
				*Step = MOTOR_STEP_PLUS;
				PerformAdjust = TRUE;
			}
			else if(Weight >= 80 && Weight < 100)
			{
				*Step = MOTOR_STEP_PLUS;
				PerformAdjust = TRUE;
			}
			else
			{
				*Step = MOTOR_STEP_PLUS;
				PerformAdjust = TRUE
			}
			break;
		}

		case SENSOR_POSITION_STEP_1:
		{
			if(Weight < 60)
			{
				*Step = MOTOR_STEP_MINUS;
				PerformAdjust = TRUE
			}
			else if(Weight >= 60 && Weight < 80)
			{
				// Do Nothing
			}
			else if(Weight >= 80 && Weight < 100)
			{
				*Step = MOTOR_STEP_PLUS;
				PerformAdjust = TRUE
			}
			else
			{
				*Step = MOTOR_STEP_PLUS;
				PerformAdjust = TRUE
			}
			break;
		}

		case SENSOR_POSITION_STEP_2:
		{
			if(Weight < 60)
			{
				*Step = MOTOR_STEP_MINUS;
				PerformAdjust = TRUE
			}
			else if(Weight >= 60 && Weight < 80)
			{
				*Step = MOTOR_STEP_MINUS;
				PerformAdjust = TRUE
			}
			else if(Weight >= 80 && Weight < 100)
			{
				// Do Nothing
			}
			else
			{
				*Step = MOTOR_STEP_PLUS;
				PerformAdjust = TRUE
			}
			break;
		}

		case SENSOR_POSITION_STEP_3:
		{
			if(Weight < 60)
			{
				*Step = MOTOR_STEP_MINUS;
				PerformAdjust = TRUE
			}
			else if(Weight >= 60 && Weight < 80)
			{
				*Step = MOTOR_STEP_MINUS;
				PerformAdjust = TRUE
			}
			else if(Weight >= 80 && Weight < 100)
			{
				*Step = MOTOR_STEP_MINUS;
				PerformAdjust = TRUE
			}
			else
			{
				// Do Nothing
			}
			break;
		}
	}

	return PerformAdjust;
}
/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	
	Rte_Call_rpWeightSensor_GetWeight(&weight);
	Rte_Call_rpHeightSensor_GetPosition(&position);

	if(AutoStateMachine(weight, position, &step))
	{
		Rte_Call_rpHeightMotor_Move(step);
	}
	else
	{
		// Do Nothing
	}
	
	
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	
	Rte_Call_rpWeightSensor_GetWeight(&weight);
	Rte_Call_rpInclineSensor_GetPosition(&position);

	if(AutoStateMachine(weight, position, &step))
	{
		Rte_Call_rpInclineMotor_Move(step);
	}
	else
	{
		// Do Nothing
	}	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	
	Rte_Call_rpWeightSensor_GetWeight(&weight);
	Rte_Call_rpSlideSensor_GetPosition(&position);

	if(AutoStateMachine(weight, position, &step))
	{
		Rte_Call_rpSlideMotor_Move(step);
	}
	else
	{
		// Do Nothing
	}	
}


void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if (HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	else
	{
		// Do Nothing
	}
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if (InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	else
	{
		// Do Nothing
	}
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if (SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	else
	{
		// Do Nothing
	}
}

