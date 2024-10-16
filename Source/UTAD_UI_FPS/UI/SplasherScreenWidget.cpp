// Fill out your copyright notice in the Description page of Project Settings.


#include "SplasherScreenWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Kismet/GameplayStatics.h"


void USplasherScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(WidgetFadeAnimation)
	{
		FadeTime = WidgetFadeAnimation->GetEndTime();
		PlayAnimation(WidgetFadeAnimation,0.f,1,EUMGSequencePlayMode::Forward);
	}
}

void USplasherScreenWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	FadeTime -= InDeltaTime;
	if(FadeTime <= 0.f)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "FirstPersonMap");
	}
}


