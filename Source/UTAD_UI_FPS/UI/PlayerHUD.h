// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerHitMarker.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

class AUTAD_UI_FPSCharacter;
class UAmmoCounter;
class UCrosshair;
class UPlayerHealthBar;
class UReloadBar;

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;
	
	void InitializeHUD(AUTAD_UI_FPSCharacter* PlayerCharacter);
	
	/** Show the Minimap and the PlayerHealthBar */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void ShowNoWeapon();

	/** Show all the widgets */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void ShowAll();

	/** Hide all the widgets */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

private:
	// Pointer to the player character
	UPROPERTY()
	AUTAD_UI_FPSCharacter* OwningPlayer;

	// Widgets
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UPlayerHealthBar> PlayerHealthBarWidget;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAmmoCounter> AmmoCounterWidget;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UReloadBar> ReloadBarWidget;

	UPROPERTY(meta = (BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCrosshair> CrosshairWidget;

	UPROPERTY(meta = (BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UPlayerHitMarker> PlayerHitMarkerWidget;

	UPROPERTY(meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<USplasherScreenWidget> SplasherScreenWidget;
};
