// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "instrument.h"
#include "registers.h"
#include "helper.h"
#include "ModbusTCPConnection.h"

#pragma comment(linker, "/EXPORT:InitInst=_InitInst@4")
#pragma comment(linker, "/EXPORT:Shutter=_Shutter@4")
#pragma comment(linker, "/EXPORT:Filter=_Filter@4")
#pragma comment(linker, "/EXPORT:Lamp=_Lamp@8")
#pragma comment(linker, "/EXPORT:Disp=_Disp@8")
#pragma comment(linker, "/EXPORT:Slit=_Slit@4")
#pragma comment(linker, "/EXPORT:CloseInst=_CloseInst@0")
#pragma comment(linker, "/EXPORT:GetZero=_GetZero@4")
#pragma comment(linker, "/EXPORT:SetTick=_SetTick@4")


CModbusTCPConnection dev;
std::ofstream logger;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH: {
		
			//�������� ���������� ������ modbus ���������� 
			//pConnection = new CModbusTCPConnection();

			WSADATA ws;
			if (::WSAStartup(MAKEWORD(2, 2), &ws) != 0)
			{
				std::cerr << "Unable to initialize sockets" << std::endl;
				return FALSE;
			}

			logger.open("log.txt");

		}
		break;

		case DLL_THREAD_ATTACH:
		{

		}
		break;

		case DLL_THREAD_DETACH:
		{
			logger.close();
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
		bool connected = dev.Establish(path, &logger);

		//���� �� ����������� ������� ��������� �� �����
		if (!connected)
		{
			std::ifstream input;
			input.open(path);

			connected = dev.Establish(input, &logger);
		}	

		//���� �� ������� ���������� ����������  false  
		if (!connected)
			return false;	


		std::vector<unsigned char> res;
		unsigned short szData[] =
		{
			1,
			1
		};

		dev.Transact(ReadInputRegisters, (char*)szData, sizeof(szData), res, &logger);

		return true;
	}

	//���������(state = 1) � ���������(state = 0) ������.
	IMPEXP bool CALLCONV Shutter(unsigned char state)
	{
		//if (connection.)
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