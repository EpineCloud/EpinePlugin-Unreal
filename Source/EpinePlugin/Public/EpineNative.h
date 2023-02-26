#pragma once

THIRD_PARTY_INCLUDES_START
#include "EpineSDK/src/epine.h"
THIRD_PARTY_INCLUDES_END

class EPINEPLUGIN_API FEpineNative {
  public:
    FEpineNative();

    // Native callbacks
    TFunction<void()> OnInitCallback;
    TFunction<void(std::string[])> OnWalletConnectedCallback;

    void ClearAllCallbacks();

    void Init();
    std::string ConnectWallet(Epine::Constants::Chains::Type type);
    std::vector<Epine::Tokens::Token> GetAddressBalance(std::string address, Epine::Constants::Chains::Type type, Epine::Constants::Chains::ID id);
  
  protected:
    void SetupInternalCallbacks();

    void InitPrivateClient();

    TSharedPtr<Epine::Client> PrivateClient;
};
