// Copyright Vladyslav Kulinych 2018. All Rights Reserved.

#include "EnemyAIBase.h"
#include "Enemy.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

AEnemyAIBase::AEnemyAIBase()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BBComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
}

FVector AEnemyAIBase::GetOwnerPosition()
{
	// Getting owner location
	return Pawn->GetActorLocation();
}

void AEnemyAIBase::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	Pawn = Cast<AEnemy>(InPawn);

	if (Pawn && Pawn->BehaviorTree)
	{
		BlackboardComp->InitializeBlackboard(*Pawn->BehaviorTree->BlackboardAsset);

		EnemyKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*Pawn->BehaviorTree);
	}
}