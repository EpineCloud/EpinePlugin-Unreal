// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "EpineNative.h"

class FEpinePluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FEpinePluginModule& Get() {
		return FModuleManager::LoadModuleChecked<FEpinePluginModule>("EpinePlugin");
	}

	// virtual TSharedPtr<FEpineNative> NewValidNativePointer() { return nullptr; };
	TSharedPtr<FEpineNative> NewValidNativePointer();

private:
	/** Handle to the dll we will load */
	void *EpineSDKHandle;
};
