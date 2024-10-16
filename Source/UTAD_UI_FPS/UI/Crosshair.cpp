// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"

#include "Animation/UMGSequencePlayer.h"
#include "UTAD_UI_FPS/TP_WeaponComponent.h"

void UCrosshair::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCrosshair::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UCrosshair::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!OwnerPlayer)
	{
		return;
	}
	
	if (OwnerPlayer->bIsHittingEnemy)
	{
		ChangeCrosshairColor(ChangedColor);
	}
	else
	{
		Crosshair->SetColorAndOpacity(BaseColor);
	}

	if(OwnerPlayer->bHasRifle && bBinded == false)
	{
		Weapon = OwnerPlayer->GetAttachedWeaponComponent();
		Weapon->OnWeaponFired.AddDynamic(this,&UCrosshair::OnPlayerFire);
		bBinded=true;
	}
}

void UCrosshair::NativeDestruct()
{
	Super::NativeDestruct();
	if(Weapon)
	{
		Weapon->OnWeaponFired.RemoveDynamic(this,&UCrosshair::OnPlayerFire);
		Weapon = nullptr;
	}
	
}

void UCrosshair::OnPlayerFire()
{
	if(WidgetAnimationShoot)
	{
		PlayAnimation(WidgetAnimationShoot,0.f,1,EUMGSequencePlayMode::Forward);
	}
}

void UCrosshair::ChangeCrosshairColor(FLinearColor DesiredColor)
{
	Crosshair->SetColorAndOpacity(DesiredColor);
}
