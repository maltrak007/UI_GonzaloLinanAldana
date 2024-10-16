// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"
#include "SkillTree.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USkillTree : public UUserWidget
{
	GENERATED_BODY()
public:
	
protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	//Buttons
	UPROPERTY(meta=(BindWidget))
	UButton* HealthSkill_1_B;
	UPROPERTY(meta=(BindWidget))
	UButton* HealthSkill_2_B;
	UPROPERTY(meta=(BindWidget))
	UButton* StaminaSkill_1_B;
	UPROPERTY(meta=(BindWidget))
	UButton* StaminaSkill_2_B;
	UPROPERTY(meta=(BindWidget))
	UButton* DamageSkill_1_B;
	UPROPERTY(meta=(BindWidget))
	UButton* DamageSkill_2_B;
	
	//Progress Bar
	UPROPERTY(meta=(BindWidget))
	UProgressBar* HealthSkill_1_P;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* HealthSkill_2_P;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* StaminaSkill_1_P;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* StaminaSkill_2_P;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* DamageSkill_1_P;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* DamageSkill_2_P;

	//Float Variables
	float HealthSkill_1_CurrentProgress;
	float HealthSkill_2_CurrentProgress;
	float StaminaSkill_1_CurrentProgress;
	float StaminaSkill_2_CurrentProgress;
	float DamageSkill_1_CurrentProgress;
	float DamageSkill_2_CurrentProgress;

	//Bools to check if they are already purchased
	bool bHealthSkill1;
	bool bHealthSkill2;
	bool bStaminaSkill_1;
	bool bStaminaSkill_2;
	bool bDamageSkill_1;
	bool bDamageSkill_2;
};
