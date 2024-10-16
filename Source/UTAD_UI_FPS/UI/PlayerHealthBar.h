// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "UTAD_UI_FPS/UTAD_UI_FPSCharacter.h"
#include "PlayerHealthBar.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	void SetOwnerCharacter(AUTAD_UI_FPSCharacter* Player) { OwnerPlayer = Player; }

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY()
	TObjectPtr<AUTAD_UI_FPSCharacter> OwnerPlayer;

private:
	float BlinkTimer = 0.f;
	bool bIsLowHealth = false;
	bool bBlinkTurningRed = true;
	
	void LowHealthBlink();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess="true"))
	UProgressBar* PlayerHealthBar = nullptr;

	FLinearColor ActualColor = FLinearColor::Green;
	FLinearColor DesiredColor = FLinearColor::Red;
};
