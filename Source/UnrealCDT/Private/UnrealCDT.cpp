// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCDT.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"

#define LOCTEXT_NAMESPACE "FUnrealCDTModule"

void FUnrealCDTModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	// FString BaseDir = IPluginManager::Get().FindPlugin("UnrealCDT")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	// FString LibraryPath;
}

void FUnrealCDTModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	ExampleLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealCDTModule, UnrealCDT)
