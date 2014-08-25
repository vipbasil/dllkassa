#include "global.h"

#ifndef _DB_ANALYSE_H
#define _DB_ANALYSE_H

#ifdef __DLL__
#  define DLL_SPEC __declspec(dllexport)
#else
#  define DLL_SPEC __declspec(dllimport)
#endif

//TTable* - таблица с которой необходимо получить количество параметров
//int* - массив размерностью MAX_TYPE_COUNT для получения присутствующих типов
extern "C" int DLL_SPEC GetChannelsTypeCount(func_param_description*);

//TTable* - таблица с которой необходимо получить количество параметров
//int* - тип параметра для которого нужно получить количество каналов
extern "C" int DLL_SPEC GetChannelsCountOfSomeType(func_param_description*);

//TTable* - таблица с которой необходимо получить количество параметров
//int* - тип параметра для которого нужно получить данные
//chan_params - указатель на массив данных для нужного параметра
extern "C" int DLL_SPEC GetChannelsDataOfSomeType(func_param_description*);

#endif




