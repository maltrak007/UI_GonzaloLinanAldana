// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "UTAD_UI_FPS/UTAD_UI_FPS_Enemy.h"
#include "EnemyHealthBar.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UEnemyHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetOwnerEnemy(AUTAD_UI_FPS_Enemy* Enemy) { OwnerEnemy = Enemy; }

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY()
	TObjectPtr<AUTAD_UI_FPS_Enemy> OwnerEnemy;

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess="true"))
	UProgressBar* EnemyHealthBar = nullptr;
};
