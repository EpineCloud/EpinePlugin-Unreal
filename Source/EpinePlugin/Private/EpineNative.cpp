#include "EpineNative.h"

FEpineNative::FEpineNative() {
  InitPrivateClient();

	ClearAllCallbacks();
}

void FEpineNative::InitPrivateClient() {
  PrivateClient = MakeShareable(new Epine::Client(Epine::Client::Environment::LOCAL));
}

void FEpineNative::ClearAllCallbacks() {
  OnInitCallback = nullptr;
}

void FEpineNative::Init() {
  // UE_LOG(Epine, Log, TEXT("Epine: Initializing..."));
  PrivateClient->init([&]{
    // UE_LOG(Epine, Log, TEXT("SocketIO Initialized"));
    if (OnInitCallback) {
      OnInitCallback();
    }
  });
}
