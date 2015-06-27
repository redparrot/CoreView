#pragma once

#ifdef DLLEXPORTS
#ifdef __cplusplus
#define DLLEXPORT extern "C" __declspec ( dllexport )
#else
#define DLLEXPORT __declspec ( dllexport )
#endif
#else
#ifdef __cplusplus
#define DLLEXPORT extern "C" __declspec ( dllimport )
#else
#define DLLEXPORT __declspec ( dllimport )
#endif
#endif

DLLEXPORT void ShowEditDialog();
