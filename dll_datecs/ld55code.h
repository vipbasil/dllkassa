#include "global.h"

#ifndef _DB_ANALYSE_H
#define _DB_ANALYSE_H

#ifdef __DLL__
#  define DLL_SPEC __declspec(dllexport)
#else
#  define DLL_SPEC __declspec(dllimport)
#endif

//TTable* - ������� � ������� ���������� �������� ���������� ����������
//int* - ������ ������������ MAX_TYPE_COUNT ��� ��������� �������������� �����
extern "C" int DLL_SPEC GetChannelsTypeCount(func_param_description*);

//TTable* - ������� � ������� ���������� �������� ���������� ����������
//int* - ��� ��������� ��� �������� ����� �������� ���������� �������
extern "C" int DLL_SPEC GetChannelsCountOfSomeType(func_param_description*);

//TTable* - ������� � ������� ���������� �������� ���������� ����������
//int* - ��� ��������� ��� �������� ����� �������� ������
//chan_params - ��������� �� ������ ������ ��� ������� ���������
extern "C" int DLL_SPEC GetChannelsDataOfSomeType(func_param_description*);

#endif




