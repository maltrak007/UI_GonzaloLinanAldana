// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "UTAD_UI_FPS/UTAD_UI_FPSCharacter.h"
#include "Crosshair.generated.h"
/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UCrosshair : public UUserWidget
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

	virtual void NativeDestruct() override;
	
	UPROPERTY()
	TObjectPtr<AUTAD_UI_FPSCharacter> OwnerPlayer;

	UFUNCTION()
	void OnPlayerFire();
	
private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess="true"))
	UImage* Crosshair = nullptr;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* WidgetAnimationShoot;

	UPROPERTY()
	UTP_WeaponComponent* Weapon = nullptr;
	
	FLinearColor BaseColor = FLinearColor::Black;

	FLinearColor ChangedColor = FLinearColor::Red;

	void ChangeCrosshairColor(FLinearColor DesiredColor);

	bool bBinded = false;
};
