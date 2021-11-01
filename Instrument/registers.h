#pragma once

//��������� ������ ���������
enum RegisterStartAddress : int
{

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
	StatusRegister = 0x08,

	//������� ���������
	ProgressRegister = 0x09,

	//������� ������ ��������
	VersionRegister = 0x10
};


//����� �������� ����������
enum ControlRegisterBits : unsigned char
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
enum InputRegisterBits : unsigned char
{
	//��� ��������� ��������� �������
	LimitSW,

	//��� ��������� ������� ����� �������	
	ZeroSW
};

//���� �������� ������
enum CommandRegisterBits : unsigned char
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
enum StatusRegisterBits : unsigned char
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



