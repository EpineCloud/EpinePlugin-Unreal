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
  UE_LOG(LogTemp, Log, TEXT("EpineNative: init()"));
  auto on_init_callback = [&]{
    UE_LOG(LogTemp, Log, TEXT("EpineNative: init().callback"));
    if (OnInitCallback) {
      OnInitCallback();
    }
  };
  PrivateClient->set_on_init_callback(on_init_callback);
  PrivateClient->init();
}
