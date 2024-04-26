// Fill out your copyright notice in the Description page of Project Settings.


#include "ADynamicPawnController.h"

void AADynamicPawnController::BeginPlay()
{
	Super::BeginPlay();

	MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Script/Engine.DataTable'/Game/BluePrints/DT_PawnDataTable.DT_PawnDataTable'"));
	SpawnCharacter();
}

void AADynamicPawnController::SpawnCharacter()
{
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"S");
	if (CurrentlySpawnedActor)
	{
		CurrentlySpawnedActor->Destroy();
		CurrentlySpawnedActor = nullptr;
		CurrentActorIndex++;
		SetShowMouseCursor(false);
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"Destroy");
	}

	if (MyDataTable)
	{
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"T");
		TArray<FName> RowNames = MyDataTable->GetRowNames();

		if (RowNames.Num() == CurrentActorIndex) {
			CurrentActorIndex = 0;
		}

		FName RowNameByIndex = RowNames[CurrentActorIndex];

		FPawnAttributesStruct* RowData = MyDataTable->FindRow<FPawnAttributesStruct>(RowNameByIndex, TEXT(""));

		if (RowData)
		{
			GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"RowData");

			TSubclassOf<APawn> CharacterClassToSpawn = RowData->PawnClass;
			if (CharacterClassToSpawn)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				FVector SpawnLocation_ = FVector(50, 50, 50);
				FRotator SpawnRotation = FRotator(0, 0, 0);

				APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(CharacterClassToSpawn, SpawnLocation_, SpawnRotation, SpawnParams);

				if (SpawnedPawn)
				{
					Possess(SpawnedPawn);

					GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Spawn");

					CurrentlySpawnedActor = SpawnedPawn;

					if (RowData->CharacterType == EPawnType::TopDown) {
						SetShowMouseCursor(true);
						// DisplayAttributes((Cast<ABaseCharacter>(SpawnedPawn))->PawnAttributeAsset);
					}
					else if (RowData->CharacterType == EPawnType::ThirdPerson) {
						// DisplayAttributes((Cast<ABaseCharacter>(SpawnedPawn))->PawnAttributeAsset);
					}
					else {
						// DisplayAttributes((Cast<AFirstPersonPawn>(SpawnedPawn))->PawnAttributeAsset);
					}

				}
			}
		}
	}
}


void AADynamicPawnController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Spawn", IE_Pressed, this, &AADynamicPawnController::SpawnCharacter);
}