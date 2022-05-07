// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "EpineNative.h"

#include "EpineComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCallbackSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EPINEPLUGIN_API UEpineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCallbackSignature OnInit;

	// Sets default values for this component's properties
	UEpineComponent();

	virtual void InitializeComponent() override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TSharedPtr<FEpineNative> NativeClient;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
