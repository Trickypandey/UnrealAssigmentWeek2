// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseCharacter.h"
#include "../AFirstPersonPawn.h"
#include "FPawnAttributesStruct.h"
#include "ADynamicPawnController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGMENT2_API AADynamicPawnController : public APlayerController
{
	GENERATED_BODY()
public:
	//AADynamicPawnController();

protected:
    UPROPERTY()
    UDataTable* MyDataTable;

    UPROPERTY()
    APawn* CurrentlySpawnedActor;

    int32 CurrentActorIndex;

    virtual void BeginPlay() override;

    void SpawnCharacter();

    UFUNCTION(BlueprintImplementableEvent)
    void DisplayAttributes(UPawnAttributeAsset* AttributeAsset);

    void SetupInputComponent() override;

    //EPawnType GetNextPawnType();

    //UClass* GetPawnClassFromDataTable(EPawnType PawnType);
	
};
