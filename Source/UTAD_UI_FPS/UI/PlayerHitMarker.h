// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "UTAD_UI_FPS/UTAD_UI_FPSCharacter.h"
#include "PlayerHitMarker.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerHitMarker : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetOwnerCharacter(AUTAD_UI_FPSCharacter* Player) {OwnerPlayer = Player;}
	
protected:
	virtual void NativeConstruct() override;
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY()
	TObjectPtr<AUTAD_UI_FPSCharacter> OwnerPlayer;
	
private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess="true"))
	UImage* HitMarkerImage;
	
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* WidgetAnimationHitPlayer;
	
	UFUNCTION()
	void OnPlayerDamaged();

	int PlayerPreviousHealth = 100;
};
