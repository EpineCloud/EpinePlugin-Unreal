// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "EpineNative.h"

#include "EpineComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCallbackSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCallbackSignatureWithStringArray, const TArray<FString>&, StringArray);

UENUM(BlueprintType)
enum class ChainType : uint8
{
	EVM = static_cast<uint8>(Epine::Constants::Chains::Type::EVM) UMETA(DisplayName = "EVM (Ethereum, Polygon, zkSync, etc.)"),
	TVM = static_cast<uint8>(Epine::Constants::Chains::Type::TVM) UMETA(DisplayName = "TVM (TON)"),

	None = 0 UMETA(DisplayName = "Not implemented")
};

UENUM(BlueprintType)
enum class ChainId : uint8
{
	EVM_ETHEREUM = static_cast<uint8>(Epine::Constants::Chains::ID::EVM_ETHEREUM) UMETA(DisplayName = "EVM: Ethereum"),
	EVM_POLYGON = static_cast<uint8>(Epine::Constants::Chains::ID::EVM_POLYGON) UMETA(DisplayName = "EVM: Polygon"),
	EVM_TESTNET_ZK_SYNC = static_cast<uint8>(Epine::Constants::Chains::ID::EVM_TESTNET_ZK_SYNC) UMETA(DisplayName = "EVM: Testnet: zkSync"),
	None = 0 UMETA(DisplayName = "Other (no chain ID)")
};

#pragma pack(push, 1)
USTRUCT(BlueprintType)
struct FToken
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString address;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString symbol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float balance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool native;
};
#pragma pack(pop)

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EPINEPLUGIN_API UEpineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCallbackSignature OnInit;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCallbackSignatureWithStringArray OnWalletConnected;

	UFUNCTION(BlueprintCallable, DisplayName = "Request Wallet Connection")
	FString ConnectWallet(ChainType type);

	UFUNCTION(BlueprintCallable, DisplayName = "Get address balance")
	TArray<FToken> GetAddressBalance(FString address, ChainType type, ChainId id);

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
