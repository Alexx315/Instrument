// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "instrument.h"
#include "registers.h"
#include "helper.h"


#pragma comment(linker, "/EXPORT:InitInst=_InitInst@4")
#pragma comment(linker, "/EXPORT:Shutter=_Shutter@4")
#pragma comment(linker, "/EXPORT:Filter=_Filter@4")
#pragma comment(linker, "/EXPORT:Lamp=_Lamp@8")
#pragma comment(linker, "/EXPORT:Disp=_Disp@8")
#pragma comment(linker, "/EXPORT:Slit=_Slit@4")
#pragma comment(linker, "/EXPORT:CloseInst=_CloseInst@0")
#pragma comment(linker, "/EXPORT:GetZero=_GetZero@4")
#pragma comment(linker, "/EXPORT:SetTick=_SetTick@4")

//////////////////////////////////////////
/*		���������� ���������			*/
//////////////////////////////////////////

//modbus ����������
modbus_t *mb;

//---------------------------------------------------------




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH: {
		
						
		}
		break;

		case DLL_THREAD_ATTACH:
		{

		}
		break;

		case DLL_THREAD_DETACH:
		{
			
		}
		break;

		case DLL_PROCESS_DETACH:
		{
		}
		break;
       
	}
    return TRUE;
}

extern "C" {
	// �������� � ������� X008, ���-0, �������� 1. 
	// ���� ������ ������ �������, ������� � ������� �������� true.
	// ������ ������ � �������, ������ ��������� "������ ������ �����", ������ �������� ������� false.
	IMPEXP bool CALLCONV  InitInst(const char* path)
	{
		// ���� �������� ������ ������ � ���� "ipaddress:port" "192.168.10.18:502" 
		std::pair<std::string, int> opt = helper::connection(path);
		mb = modbus_new_tcp(opt.first.c_str(), opt.second);
		int connected = modbus_connect(mb);			   

		//���� �� ����������� ������� ��������� �� ����� path
		if (connected == -1)
		{
			std::ifstream input;
			input.open(path);

			std::pair<std::string, int> opt = helper::connection(input);
			mb = modbus_new_tcp(opt.first.c_str(), opt.second);
			connected = modbus_connect(mb);
		}

		//���� �� ����������� ������� ��������� �� ����� � ������� ���������� "connect.txt"
		if (connected == -1)
		{
			std::ifstream input;
			input.open("connect.txt");

			std::pair<std::string, int> opt = helper::connection(input);
			mb = modbus_new_tcp(opt.first.c_str(), opt.second);
			connected = modbus_connect(mb);
		}

		//���� �� ������� ���������� ����������  false  
		if (connected == -1)
			return false;	

		uint16_t tab_reg[32];
		int readCount = modbus_read_input_registers(mb, 0, 1, tab_reg);

		tab_reg[0] = 200;
		int writeConut = modbus_write_registers(mb, 1, 1, tab_reg); 


		return true;
	}

	//���������(state = 1) � ���������(state = 0) ������.
	IMPEXP bool CALLCONV Shutter(unsigned char state)
	{
		
		return false;
	}

	//������������� ������ ���������� �������� � �������� ������� n.
	IMPEXP bool CALLCONV Filter(int value)
	{
		return false;
	}

	//�������� (state=1) ��� ��������� (state=0) ����� �������� ���� (kind=FF) ��� ������� ��������� (kind=CS).
	IMPEXP bool CALLCONV Lamp(const char *kind, unsigned char state)
	{
		return false;
	}

	//���������� ������ state ��� n-�� ��������������� ���������� ������������.
	IMPEXP bool CALLCONV Disp(unsigned char n, const char *state)
	{
		return false;
	}

	//���������� ������ ���� ������������ ������ state.
	IMPEXP bool CALLCONV Slit(const char *state)
	{
		return false;
	}

	//��������� ��� ����������� �������� �� ���������� ������������ � ����������, � ���������� � ���������� �� ������.
	IMPEXP bool CALLCONV CloseInst()
	{
		return false;
	}

	//��������� 
	IMPEXP bool CALLCONV GetZero(const char *state)
	{
		return false;
	}

	//��������� 
	IMPEXP bool CALLCONV SetTick(const char *state)
	{
		return false;
	}
}