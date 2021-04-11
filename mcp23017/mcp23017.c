#include "mcp23017.h"

// ������ �������� �������� �-����� D-������
void MCP23017_write_Register(char A, char D)
{
	I2C_StartCondition();									// ���������� ������� �����
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_W);	// ����� ���������� + ��� ������ w
	I2C_SendByte(A);										// �������� ����� ��������
	I2C_StartCondition();									// ��������� ������� ����� (�������)
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_W);	// ����� ���������� + ��� ������ w
	I2C_SendByte(D);										// ���������� ���� ������
	I2C_StopCondition();									// ��������� ������� ����
}

// ������ �������� � ������� A-�����
char MCP23017_read_Register (char A)
{
	char R;
	I2C_StartCondition();									// ���������� ������� �����
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_W);	// ����� ���������� + ��� ������ w
	I2C_SendByte(A);										// �������� ����� ��������
	I2C_StartCondition();									// ��������� ������� ����� (�������)
	I2C_SendByte(MCP23017_ADDRES|MCP23017_AAA|MCP23017_R);	// ����� ���������� + ��� ������ R
	R = I2C_ReadByte();										// ������ ���� ������
	I2C_StopCondition();									// ��������� ������� ����
	return R;
}