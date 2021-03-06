// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArcadeSHMUPPawn.generated.h"

UCLASS(Blueprintable)
class AArcadeSHMUPPawn : public APawn
{
	GENERATED_BODY()

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/* The particle component that is activated when the player is hurt and activates a brief window of invulnurability */
	UPROPERTY(Category = Particles, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UParticleSystemComponent* InvulnurabilityParticles;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// Arrows to spawm weapoms at
	UPROPERTY(Category = "Shooting", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UShootingComponent* ShootingComponent;
	
	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForShotgun1;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForShotgun2;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForMachinegun1;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForMachinegun2;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForRifle1;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForRifle2;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForLazer1;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForLazer2;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForRocket1;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForRocket2;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForArc1;

	UPROPERTY(Category = "Arrows", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ArrowForArc2;

public:
	AArcadeSHMUPPawn();

	// Function that is called by enemies or enemy projectiles that deal damage
	void TakeDamage();

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	/* Fire a shot in the specified direction */
	void AttemptFireShot();

	//Getter for the shooting component of a player
	UShootingComponent* GetShootingComponent();

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName TurnClockwiseBinding;
	static const FName FireBinding;

	// Function that is called by shooting component to find a proper arrow to attach a weapon at 
	UArrowComponent* GetArrowForWeapon(int32 WeaponIndex, bool bIsFirst);

	UFUNCTION(BlueprintImplementableEvent)
	void AddMessageOnScreen(const FString& ToAdd);
private:
	// Force to apply at movement
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		float ShipThrottle = 30000.f;

	// Rate at which ship is turning
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		float TurnRate = 30.f;

	// Function to attempt at using super move
	void AttemptSuper();

	//Damage System Interface
	bool bIsInvincible = false;

	// Health that is left
	int32 HowMuchHPLeft = 3;

	
public:
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	

	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE int32 GetRemainingHealth() const { return HowMuchHPLeft; }
};

