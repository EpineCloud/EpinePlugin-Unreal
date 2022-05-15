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

	NativeClient = FEpinePluginModule::Get().NewValidNativePointer();
}

// Called when the game starts
void UEpineComponent::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::White, FString("BeginPlay -> Init"));
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay -> Init"));

	NativeClient->OnInitCallback = [this]()
	{
		if (NativeClient.IsValid()) {
			OnInit.Broadcast();
		}
	};

	NativeClient->Init();
}


// Called every frame
void UEpineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

