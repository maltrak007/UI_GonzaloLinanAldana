// Fill out your copyright notice in the Description page of Project Settings.
#include "EnemyHealthBar.h"

#include "Components/ProgressBar.h"


void UEnemyHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(!OwnerEnemy)
	{
		return;
	}

	float x = static_cast<float>(OwnerEnemy->GetHealth()) / static_cast<float>(OwnerEnemy->GetMaxHealth());

	EnemyHealthBar->SetPercent(x);
}
