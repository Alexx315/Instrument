#pragma once

//��������� ������ ���������
enum RegisterStartAddress{

	//������� ����������
	ControlRegister = 0x01,

	//������� ������
	InputRegisters = 0x02,

	//������� ������� ���������
	PositionHightRegister = 0x03,

	//������ ������� ���������
	PositionLowRegister = 0x05,

	//��������� �������
	CommandRegister = 0x07,

	//������� ���������
	StatusRegistr = 0x08,

	//������� ���������
	ProgressRegister = 0x09,

	//������� ������ ��������
	VersionRegister = 0x10
};


//����� �������� ����������
enum ControlRegisterBits
{ 
	//��� ���������� ������� ��������
	ShutterBit,

	//��� ���������� ������ FF
	LampFFBit ,

	//��� ���������� ������ FF
	LampCSBit,

	//��� ����������� �������� ������
	CameraBit,

	//��� ���������� ��������� scr
	ScrBit
};

//���� �������� ������
enum InputRegisterBits
{
	//��� ��������� ��������� �������
	LimitSW,

	//��� ��������� ������� ����� �������	
	ZeroSW
};

//���� �������� ������
enum CommandRegisterBits
{
	//��� �������� ���� � ����� �������
	Angle,

	//��� ����� ���������� ������ �������
	Gap,

	//��� ��������� ���������
	StopEngine,

	//��� ����� ���������� ����
	ResetZero,

	//��� ��������� ���������� ����
	GetZeroCalibration,
};

//����� �������� ���������
enum StatusRegisterBits
{
	//��� ���������� ������� � ������
	Client,

	//��� ������ �� ���������� �������
	CommandRequest,

	//��� ��������� ����������� �������
	CommandBusy,

	//��� ������ ���������� ������� �����
	ZeroState	
};



