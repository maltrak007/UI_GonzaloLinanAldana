// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Crosshair.h"
#include "AmmoCounter.h"
#include "PlayerHealthBar.h"
#include "ReloadBar.h"


void UPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();
	SplasherScreenWidget->SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHUD::InitializeHUD(AUTAD_UI_FPSCharacter* PlayerCharacter)
{
	OwningPlayer = PlayerCharacter;

	UWorld* CurrentWorld = GetWorld();
	FString CurrentMap = CurrentWorld->GetMapName();
	FString DesiredMap = "UEDPIE_0_SplasherMap";
	if(CurrentMap.Equals(DesiredMap))
	{
		SplasherScreenWidget->SetVisibility(ESlateVisibility::Visible);
		CrosshairWidget->SetVisibility(ESlateVisibility::Hidden);
		PlayerHealthBarWidget->SetVisibility(ESlateVisibility::Hidden);
		AmmoCounterWidget->SetVisibility(ESlateVisibility::Hidden);
		ReloadBarWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (PlayerHealthBarWidget)
	{
		PlayerHealthBarWidget->SetOwnerCharacter(OwningPlayer);
	}
	
	// if (AmmoCounterWidget)
	// {
	// 	AmmoCounterWidget->SetOwnerCharacter(OwningPlayer);
	// }
	//
	// if(ReloadBar)
	// {
	// 	
	// }
	
	if(CrosshairWidget)
	{
		CrosshairWidget->SetOwnerCharacter(OwningPlayer);
	}

	if(PlayerHitMarkerWidget)
	{
		PlayerHitMarkerWidget->SetOwnerCharacter(OwningPlayer);
	}
}

void UPlayerHUD::ShowNoWeapon()
{
	
}

void UPlayerHUD::ShowAll()
{

}

void UPlayerHUD::Hide()
{

}
