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
}

void FEpineNative::Init() {
  UE_LOG(Epine, Log, TEXT("EpineNative: init()"));
  PrivateClient->init([&]{
    UE_LOG(Epine, Log, TEXT("EpineNative: init().callback"));
    if (OnInitCallback) {
      OnInitCallback();
    }
  });
}
