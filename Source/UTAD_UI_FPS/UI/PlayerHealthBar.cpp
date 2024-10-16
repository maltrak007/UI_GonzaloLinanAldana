// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"

#define BLINK_ANIMATION_TIME 1.f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	if(!OwnerPlayer)
	{
		return;
	}
	
	float BarPercentaje = static_cast<float>(OwnerPlayer->GetHealth()) / static_cast<float>(OwnerPlayer->GetMaxHealth());

	PlayerHealthBar->SetPercent(BarPercentaje);
	
	if(static_cast<float>(OwnerPlayer->GetHealth()) < 0.25f * static_cast<float>(OwnerPlayer->GetMaxHealth()) && bIsLowHealth == false)
	{
		bIsLowHealth = true;
	}
	if(bIsLowHealth)
	{
		LowHealthBlink();
	}
	else
	{
		BlinkTimer = 0.f;
	}
}

void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::LowHealthBlink()
{
	// Tiempo que ha transcurrido desde el último tick
	BlinkTimer += GetWorld()->GetDeltaSeconds();

	// Normalizar el tiempo para que parpadee entre 0 y 1 (usando sin o cos para suavizar)
	float BlinkAlpha = FMath::Abs(FMath::Sin(BlinkTimer / BLINK_ANIMATION_TIME * PI));

	// Interpolar entre el color original y rojo
	FLinearColor BlendedColor = FLinearColor::LerpUsingHSV(ActualColor, DesiredColor, BlinkAlpha);
    
	// Establecer el color de la barra
	PlayerHealthBar->SetFillColorAndOpacity(BlendedColor);
}
