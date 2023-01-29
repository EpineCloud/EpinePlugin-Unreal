#pragma once

THIRD_PARTY_INCLUDES_START
#include "EpineSDK/src/epine.h"
THIRD_PARTY_INCLUDES_END

class EPINEPLUGIN_API FEpineNative {
  public:
    FEpineNative();

    // Native callbacks
    TFunction<void()> OnInitCallback;
    TFunction<void()> OnWalletConnectedCallback;

    void ClearAllCallbacks();

    void Init();
    FString ConnectWallet();
  
  protected:
    void SetupInternalCallbacks();

    void InitPrivateClient();

    TSharedPtr<Epine::Client> PrivateClient;
};
