// Copyright Vladyslav Kulinych 2018. All Rights Reserved.

#include "BTService_CheckForPlayer.h"
#include "EnemyAIBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Engine/World.h"
#include "BehaviorTree/BTNode.h"

UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
	bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	// TODO Make this proper OOP, you dipsh*t!
	AEnemyAIBase* EnemyAI = Cast<AEnemyAIBase>(OwnerComp.GetAIOwner());

	APawn* Enemy = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (EnemyAI)
	{
		if (Enemy)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyAI->EnemyKeyID, Enemy);
		}
	}
}

