#pragma once

/*
#############################################################################################
# Mass Effect 2 (1.2.1604.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: SdkHeaders.h
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

/*
# ========================================================================================= #
# Defines
# ========================================================================================= #
*/

#define GObjects			0x0129BA44
#define GNames				0x0129BA00

/*
# ========================================================================================= #
# Structs
# ========================================================================================= #
*/

template< class T > struct TArray 
{ 
public: 
	T* Data; 
	int Count; 
	int Max; 

public: 
	TArray() 
	{ 
		Data = NULL; 
		Count = Max = 0; 
	}; 

public: 
	int Num() const
	{ 
		return this->Count; 
	};

	bool Any() const {
		return this->Count > 0;
	}

	T& operator() ( int i ) 
	{ 
		return this->Data[ i ]; 
	}; 

	const T& operator() ( int i ) const 
	{ 
		return this->Data[ i ]; 
	}; 

	void Add ( T InputData ) 
	{ 
		Data = (T*) realloc ( Data, sizeof ( T ) * ( Count + 1 ) ); 
		Data[ Count++ ] = InputData; 
		Max = Count; 
	}; 

	void Clear() 
	{ 
		free ( Data ); 
		Count = Max = 0; 
	}; 
}; 

struct FNameEntry 
{ 
	unsigned char	UnknownData00[ 0x08 ]; 
	char			Name[ 0x10 ]; 
}; 

struct FName 
{ 
	int				Index; 
	//unsigned char	unknownData00[ 0x4 ]; 
	UINT32	InstanceIndex;


	FName() : Index ( 0 ) {}; 

	FName ( int i ) : Index ( i ) {}; 

	~FName() {}; 

	FName ( char* FindName ) 
	{ 
		static TArray< int > NameCache; 

		for ( int i = 0; i < NameCache.Count; ++i ) 
		{ 
		if ( ! strcmp ( this->Names()->Data[ NameCache ( i ) ]->Name, FindName ) ) 
			{ 
				Index = NameCache ( i ); 
				return; 
			} 
		} 

		for ( int i = 0; i < this->Names()->Count; ++i ) 
		{ 
			if ( this->Names()->Data[ i ] ) 
			{ 
				if ( ! strcmp ( this->Names()->Data[ i ]->Name, FindName ) ) 
				{ 
					NameCache.Add ( i ); 
					Index = i; 
				} 
			} 
		} 
	}; 

	UINT32 GetInstanceIndex()
	{
		return this->InstanceIndex;
	};

	static TArray< FNameEntry* >* Names() 
	{ 
		return (TArray< FNameEntry* >*) GNames; 
	}; 

	char* GetName() 
	{ 
		return this->Names()->Data[ Index ]->Name; 
	}; 

	bool operator == ( const FName& A ) const 
	{ 
		return ( Index == A.Index ); 
	}; 
}; 

struct FString : public TArray< wchar_t > 
{ 
	FString() {}; 

	FString ( wchar_t* Other ) 
	{ 
		this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 

		if ( this->Count ) 
			this->Data = Other; 
	}; 

	~FString() {}; 

	FString operator = ( wchar_t* Other ) 
	{ 
		if ( this->Data != Other ) 
		{ 
			this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 

			if ( this->Count ) 
				this->Data = Other; 
		} 

		return *this; 
	};

	bool operator == (const wchar_t* str) const
	{
		return wcscmp(Data, str) == 0;
	};
}; 

struct FScriptDelegate 
{ 
	unsigned char UnknownData00[ 0xC ]; 
}; 

/*
# ========================================================================================= #
# Includes
# ========================================================================================= #
*/

#include "SDK_HEADERS\Core_structs.h"
#include "SDK_HEADERS\Core_classes.h"
#include "SDK_HEADERS\Core_f_structs.h"
#include "SDK_HEADERS\Core_functions.h"
#include "SDK_HEADERS\Engine_structs.h"
#include "SDK_HEADERS\Engine_classes.h"
#include "SDK_HEADERS\Engine_f_structs.h"
#include "SDK_HEADERS\Engine_functions.h"
#include "SDK_HEADERS\GameFramework_structs.h"
#include "SDK_HEADERS\GameFramework_classes.h"
#include "SDK_HEADERS\GameFramework_f_structs.h"
#include "SDK_HEADERS\GameFramework_functions.h"
#include "SDK_HEADERS\IpDrv_structs.h"
#include "SDK_HEADERS\IpDrv_classes.h"
#include "SDK_HEADERS\IpDrv_f_structs.h"
#include "SDK_HEADERS\IpDrv_functions.h"
#include "SDK_HEADERS\GFxUI_structs.h"
#include "SDK_HEADERS\GFxUI_classes.h"
#include "SDK_HEADERS\GFxUI_f_structs.h"
#include "SDK_HEADERS\GFxUI_functions.h"
#include "SDK_HEADERS\WwiseAudio_structs.h"
#include "SDK_HEADERS\WwiseAudio_classes.h"
#include "SDK_HEADERS\WwiseAudio_f_structs.h"
#include "SDK_HEADERS\WwiseAudio_functions.h"
#include "SDK_HEADERS\WinDrv_structs.h"
#include "SDK_HEADERS\WinDrv_classes.h"
#include "SDK_HEADERS\WinDrv_f_structs.h"
#include "SDK_HEADERS\WinDrv_functions.h"
#include "SDK_HEADERS\OnlineSubsystemPC_structs.h"
#include "SDK_HEADERS\OnlineSubsystemPC_classes.h"
#include "SDK_HEADERS\OnlineSubsystemPC_f_structs.h"
#include "SDK_HEADERS\OnlineSubsystemPC_functions.h"
#include "SDK_HEADERS\SFXOnlineFoundation_structs.h"
#include "SDK_HEADERS\SFXOnlineFoundation_classes.h"
#include "SDK_HEADERS\SFXOnlineFoundation_f_structs.h"
#include "SDK_HEADERS\SFXOnlineFoundation_functions.h"
#include "SDK_HEADERS\SFXGame_structs.h"
#include "SDK_HEADERS\SFXGame_classes.h"
#include "SDK_HEADERS\SFXGame_f_structs.h"
#include "SDK_HEADERS\SFXGame_functions.h"
#include "SDK_HEADERS\PlotManagerMap_structs.h"
#include "SDK_HEADERS\PlotManagerMap_classes.h"
#include "SDK_HEADERS\PlotManagerMap_f_structs.h"
#include "SDK_HEADERS\PlotManagerMap_functions.h"
#include "SDK_HEADERS\PlotManager_structs.h"
#include "SDK_HEADERS\PlotManager_classes.h"
#include "SDK_HEADERS\PlotManager_f_structs.h"
#include "SDK_HEADERS\PlotManager_functions.h"
#include "SDK_HEADERS\BIOC_Materials_structs.h"
#include "SDK_HEADERS\BIOC_Materials_classes.h"
#include "SDK_HEADERS\BIOC_Materials_f_structs.h"
#include "SDK_HEADERS\BIOC_Materials_functions.h"
#include "SDK_HEADERS\SFXGameContent_Powers_structs.h"
#include "SDK_HEADERS\SFXGameContent_Powers_classes.h"
#include "SDK_HEADERS\SFXGameContent_Powers_f_structs.h"
#include "SDK_HEADERS\SFXGameContent_Powers_functions.h"
#include "SDK_HEADERS\SFXGameContent_Bonuses_structs.h"
#include "SDK_HEADERS\SFXGameContent_Bonuses_classes.h"
#include "SDK_HEADERS\SFXGameContent_Bonuses_f_structs.h"
#include "SDK_HEADERS\SFXGameContent_Bonuses_functions.h"
#include "SDK_HEADERS\SFXGameContent_structs.h"
#include "SDK_HEADERS\SFXGameContent_classes.h"
#include "SDK_HEADERS\SFXGameContent_f_structs.h"
#include "SDK_HEADERS\SFXGameContent_functions.h"
#include "SDK_HEADERS\SFXGamePawns_structs.h"
#include "SDK_HEADERS\SFXGamePawns_classes.h"
#include "SDK_HEADERS\SFXGamePawns_f_structs.h"
#include "SDK_HEADERS\SFXGamePawns_functions.h"
#include "SDK_HEADERS\SFXGameContent_Inventory_structs.h"
#include "SDK_HEADERS\SFXGameContent_Inventory_classes.h"
#include "SDK_HEADERS\SFXGameContent_Inventory_f_structs.h"
#include "SDK_HEADERS\SFXGameContent_Inventory_functions.h"
