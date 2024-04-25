// Fill out your copyright notice in the Description page of Project Settings.


#include "AFirstPersonPawn.h"
#include "PawnController.h"		
#include "C:\Program Files\Epic Games\UE_5.2\Engine\Plugins\EnhancedInput\Source\EnhancedInput\Public\EnhancedInputComponent.h"
#include "C:\Program Files\Epic Games\UE_5.2\Engine\Plugins\EnhancedInput\Source\EnhancedInput\Public\EnhancedInputSubsystems.h"
#include "GameFrameWork/FloatingPawnMovement.h"


// Sets default values
AAFirstPersonPawn::AAFirstPersonPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;
	pMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	MoveScale = 1.0f;
	RotateScale = 50.f;
		
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

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	APawnController* PPC = Cast<APawnController>(Controller);

	check(PPC && EIC);
	EIC->BindAction(PPC->MoveAction, ETriggerEvent::Triggered, this, &AAFirstPersonPawn::Move);
	EIC->BindAction(PPC->RotateAction, ETriggerEvent::Triggered, this, &AAFirstPersonPawn::Rotate);
	ULocalPlayer* LocalPlayer = PPC->GetLocalPlayer();
	check(LocalPlayer);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(PPC->PawnMappingContext, 0);
	//PPC->bShowMouseCursor = true;
	/*PlayerInputComponent->BindAxis("MoveForward", this, &AAFirstPersonPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAFirstPersonPawn::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AAFirstPersonPawn::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AAFirstPersonPawn::LookRight);*/

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


void AAFirstPersonPawn::Move(const FInputActionValue& ActionValue)
{
	FVector Input = ActionValue.Get<FVector>();
	AddMovementInput(GetActorRotation().RotateVector(Input), MoveScale);
}

void AAFirstPersonPawn::Rotate(const FInputActionValue& ActionValue)
{
	FRotator Input(ActionValue[0], ActionValue[1], ActionValue[2]);
	Input *= GetWorld()->GetDeltaSeconds() * RotateScale;
	Input += GetActorRotation();
	Input.Pitch = FMath::ClampAngle(Input.Pitch, -89.9f, 89.9f);
	Input.Roll = 0;
	SetActorRotation(Input);
}


void AAFirstPersonPawn::LookUp(float Value)
{
	
}

void AAFirstPersonPawn::LookRight(float Value)
{
	
}

