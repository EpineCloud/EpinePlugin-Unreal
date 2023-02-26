// Fill out your copyright notice in the Description page of Project Settings.


#include "EpineComponent.h"
#include "EpinePlugin.h"

// Sets default values for this component's properties
UEpineComponent::UEpineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	bWantsInitializeComponent = true;
}

void UEpineComponent::InitializeComponent()
{
	Super::InitializeComponent();

	GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, FString("InitializeComponent -> Define NativeClient"));
	UE_LOG(LogTemp, Warning, TEXT("InitializeComponent -> Define NativeClient"));

	// Initialize NativeClient
	NativeClient = FEpinePluginModule::Get().NewValidNativePointer();

	// Assign callbacks
	NativeClient->OnInitCallback = [this](){
		GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, FString("NativeClient -> OnInitCallback"));
		UE_LOG(LogTemp, Warning, TEXT("NativeClient -> OnInitCallback"));

		OnInit.Broadcast();
	};
	NativeClient->OnWalletConnectedCallback = [this](std::string addresses_std[]){
		GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, FString("NativeClient -> OnWalletConnectedCallback"));
		UE_LOG(LogTemp, Warning, TEXT("NativeClient -> OnWalletConnectedCallback"));

		FString message = FString(("Wallet #0: " + addresses_std[0]).c_str());
		GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, message);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *message);

		TArray<FString> Addresses;
		std::string* p = addresses_std;
    while (!p->empty())
    {
			const std::string& address_std = *p;
			FString Address = FString(address_std.c_str());
			Addresses.Add(Address);
			
			++p;
    }

		OnWalletConnected.Broadcast(Addresses);
	};
}

FString UEpineComponent::ConnectWallet(ChainType type) {
	FString connection_uri = NativeClient->ConnectWallet(static_cast<Epine::Constants::Chains::Type>(type));
	GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, FString("NativeClient -> ConnectWallet: ") + connection_uri);
	UE_LOG(LogTemp, Warning, TEXT("NativeClient -> ConnectWallet"));
	return connection_uri;
}

// Called when the game starts
void UEpineComponent::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, FString("BeginPlay -> Init"));
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay -> Init"));

	NativeClient->Init();
}


// Called every frame
void UEpineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

