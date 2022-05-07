#pragma once

THIRD_PARTY_INCLUDES_START
#include "EpineSDK/src/epine.h"
THIRD_PARTY_INCLUDES_END

class EPINEPLUGIN_API FEpineNative {
  public:
    FEpineNative();

    // Native callbacks
    TFunction<void()> OnInitCallback;

    void ClearAllCallbacks();

    void Init();
  
  protected:
    void SetupInternalCallbacks();

    void InitPrivateClient();

    TSharedPtr<Epine::Client> PrivateClient;
};
