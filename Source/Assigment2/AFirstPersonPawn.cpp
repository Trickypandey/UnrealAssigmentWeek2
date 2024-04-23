// Fill out your copyright notice in the Description page of Project Settings.


#include "AFirstPersonPawn.h"

// Sets default values
AAFirstPersonPawn::AAFirstPersonPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;

}

// Called when the game starts or when spawned
void AAFirstPersonPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAFirstPersonPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAFirstPersonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) 
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAFirstPersonPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAFirstPersonPawn::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AAFirstPersonPawn::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AAFirstPersonPawn::LookRight);

}

void AAFirstPersonPawn::MoveForward(float Value)
{
	FVector MovementDirection = FVector::ZeroVector;

	if (Controller != nullptr)
	{
		
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	
		MovementDirection = ForwardDirection * Value;
	}


	AddMovementInput(MovementDirection);
}


void AAFirstPersonPawn::MoveRight(float Value)
{
	
}

void AAFirstPersonPawn::LookUp(float Value)
{
	
}

void AAFirstPersonPawn::LookRight(float Value)
{
	
}

