// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHitMarker.h"

void UPlayerHitMarker::NativeConstruct()
{
	Super::NativeConstruct();
	HitMarkerImage->SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHitMarker::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if(PlayerPreviousHealth != OwnerPlayer->GetHealth())
	{
		PlayerPreviousHealth = OwnerPlayer->GetHealth();
		OnPlayerDamaged();
	}
}

void UPlayerHitMarker::OnPlayerDamaged()
{
	if(WidgetAnimationHitPlayer)
	{
		PlayAnimation(WidgetAnimationHitPlayer,0.f,1,EUMGSequencePlayMode::Forward);
	}
}

