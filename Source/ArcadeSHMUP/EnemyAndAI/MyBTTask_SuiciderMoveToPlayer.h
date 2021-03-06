// Copyright Vladyslav Kulinych 2018. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_SuiciderMoveToPlayer.generated.h"

/**
 * Task that only works for Suicider. Tells it's ai to set the force towards player.
 */
UCLASS()
class ARCADESHMUP_API UMyBTTask_SuiciderMoveToPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
