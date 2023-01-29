#include "EpineNative.h"

FEpineNative::FEpineNative() {
  InitPrivateClient();

	ClearAllCallbacks();
}

void FEpineNative::InitPrivateClient() {
  PrivateClient = MakeShareable(new Epine::Client());
}

void FEpineNative::ClearAllCallbacks() {
  OnInitCallback = nullptr;
  OnWalletConnectedCallback = nullptr;
}

void FEpineNative::Init() {
  UE_LOG(LogTemp, Log, TEXT("EpineNative: Init()"));

  PrivateClient->set_on_init_callback(OnInitCallback);
  PrivateClient->init();
}

FString FEpineNative::ConnectWallet() {
  UE_LOG(LogTemp, Log, TEXT("EpineNative: ConnectWallet()"));

  PrivateClient->auth->wallet->on(Epine::Auth::Wallet::Event::CONNECTED, OnWalletConnectedCallback);
  std::string connection_uri = PrivateClient->auth->wallet->connect();

  return FString(connection_uri.c_str());
}
