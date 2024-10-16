// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "SplasherScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USplasherScreenWidget : public UUserWidget
{
	GENERATED_BODY()

public:


protected:

	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
private:
	UPROPERTY(meta=(AllowPrivateAccess="true",BindWidget))
	UImage* SplasherImage;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* WidgetFadeAnimation;

	UPROPERTY(EditAnywhere)
	float FadeTime;
};
