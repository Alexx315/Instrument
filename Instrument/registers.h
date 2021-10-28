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
enum ControlRegisterMasks
{ 
	//��� ���������� ������� ��������
	ShutterBit = 1 << 0,

	//��� ���������� ������ FF
	LampFFBit = 1 << 1,

	//��� ���������� ������ FF
	LampCSBit = 1 << 2,

	//����������� �������� ������
	CameraBit = 1 << 3,

	//���������� ��������� scr
	ScrBit = 1 << 4
};

//����� �������� ������
enum InputRegisterMasks
{
	//����� ��������� ��������� �������
	LimitSW = 1 << 0,

	//����� ��������� ������� ����� �������	
	ZeroSW = 1 << 1	
};

//����� �������� ������
enum CommandRegisterMasks
{
	//����� �������� ���� � ����� �������
	Angle = 1 << 0,

	//����� ����� ���������� ������ �������
	Gap = 1 << 1,

	//��������� ���������
	StopEngine = 1 << 2,

	//����� ���������� ����
	ResetZero = 1 << 3,

	//��������� ���������� ����
	GetZeroCalibration = 1 << 4,
};

//����� �������� ���������
enum StatusRegisterMasks
{
	//����� ���������� ������� � ������
	Client = 1 << 0,

	//����� ������ �� ���������� �������
	CommandRequest = 1 << 1,

	//��������� ����������� �������
	CommandBusy = 1 << 2,

	//������ ���������� ������� �����
	ZeroState = 1 << 3	
};



