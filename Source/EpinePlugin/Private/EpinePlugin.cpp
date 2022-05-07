// Copyright Epic Games, Inc. All Rights Reserved.

#include "EpinePlugin.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "ThirdPartyLibraries/EpineSDK/src/epine.h"

#define LOCTEXT_NAMESPACE "FEpinePluginModule"

void FEpinePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("EpinePlugin")->GetBaseDir();
	// Add on the relative location of the third party dll and load it
	FString EpineSDKPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/EpineSDK/Mac/libepine-sdk.a"));

	if (!FPaths::FileExists(*EpineSDKPath)) {
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "EpineSDK: Library file does not exist"));
	}

	EpineSDKHandle = !EpineSDKPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*EpineSDKPath) : nullptr;
	// if (EpineSDKHandle)
	// {
	// 	// Some code that will be executed if dll was found
	// }
	// else
	// {
	// 	FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "EpineSDK: Failed to load"));
	// }
}

void FEpinePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	// Free the dll handle
	if (EpineSDKHandle) {
		FPlatformProcess::FreeDllHandle(EpineSDKHandle);
		EpineSDKHandle = nullptr;
	}
}

TSharedPtr<FEpineNative> FEpinePluginModule::NewValidNativePointer()
{
	TSharedPtr<FEpineNative> NewPointer = MakeShareable(new FEpineNative());

	return NewPointer;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEpinePluginModule, EpinePlugin)