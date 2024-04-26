// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "C:\Program Files\Epic Games\UE_5.2\Engine\Plugins\EnhancedInput\Source\EnhancedInput\Public\InputModifiers.h"
#include "AFirstPersonPawn.generated.h"

UCLASS()
class ASSIGMENT2_API AAFirstPersonPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAFirstPersonPawn();
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	UPROPERTY()
	class UInputMappingContext* PawnMappingContext;

	UPROPERTY()
	class UInputAction* MoveAction;


	UPROPERTY()
	UInputAction* RotateAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	//void MoveRight(float Value);
	void LookUp(float Value);
	void LookRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to inpu
	void Move(const struct FInputActionValue& ActionValue);
	void Rotate(const struct FInputActionValue& ActionValue);

	UPROPERTY()
	class UFloatingPawnMovement* pMovement;

	UPROPERTY(EditAnywhere)
	float MoveScale;
	
	UPROPERTY(EditAnywhere)
	float RotateScale;


private:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

};
