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

std::string FEpineNative::ConnectWallet(Epine::Constants::Chains::Type type) {
  UE_LOG(LogTemp, Log, TEXT("EpineNative: ConnectWallet()"));

  PrivateClient->auth->wallet->on(Epine::Auth::Wallet::Event::CONNECTED, OnWalletConnectedCallback);
  return PrivateClient->auth->wallet->connect(type);
}

std::vector<Epine::Tokens::Token> FEpineNative::GetAddressBalance(std::string address, Epine::Constants::Chains::Type type, Epine::Constants::Chains::ID id) {
  UE_LOG(LogTemp, Log, TEXT("EpineNative: GetAddressBalance()"));

  return PrivateClient->tokens->getAddressBalance(address, type, id);
}
