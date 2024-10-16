// Fill out your copyright notice in the Description page of Project Settings.
#include "SkillTree.h"

void USkillTree::NativeConstruct()
{
	Super::NativeConstruct();
	//Image
	HealthSkill_1_P->SetPercent(0.0f);
	HealthSkill_2_P->SetPercent(0.0f);
	StaminaSkill_1_P->SetPercent(0.0f);
	StaminaSkill_2_P->SetPercent(0.0f);
	DamageSkill_1_P->SetPercent(0.0f);
	DamageSkill_2_P->SetPercent(0.0f);
	//Float
	HealthSkill_1_CurrentProgress = 0.f;
	HealthSkill_2_CurrentProgress = 0.f;
	StaminaSkill_1_CurrentProgress = 0.f;
	StaminaSkill_2_CurrentProgress = 0.f;
	DamageSkill_1_CurrentProgress = 0.f;
	DamageSkill_2_CurrentProgress = 0.f;
}

void USkillTree::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	//HEALTH
	if(HealthSkill_1_B->IsPressed() && bHealthSkill1 == false)
	{
		HealthSkill_1_CurrentProgress+=InDeltaTime;
		float HealthSkill_1_Clamp = FMath::Clamp(HealthSkill_1_CurrentProgress,0.0f,1.0f);
		HealthSkill_1_P->SetPercent(HealthSkill_1_Clamp);
		if(HealthSkill_1_P->GetPercent() >= 1)
		{
			bHealthSkill1 = true;
		}
	}
	else
	{
		if(HealthSkill_1_CurrentProgress > 0 && bHealthSkill1 == false)
		{
			HealthSkill_1_CurrentProgress-=InDeltaTime;
			float HealthSkill_1_Clamp = FMath::Clamp(HealthSkill_1_CurrentProgress,0.0f,1.0f);
			HealthSkill_1_P->SetPercent(HealthSkill_1_Clamp);
		}
	}

	if(bHealthSkill1)
	{
		HealthSkill_2_B->SetVisibility(ESlateVisibility::Visible);
		if(HealthSkill_2_B->IsPressed() && bHealthSkill2 == false)
		{
			HealthSkill_2_CurrentProgress+=InDeltaTime;
			float HealthSkill_2_Clamp = FMath::Clamp(HealthSkill_2_CurrentProgress,0.0f,1.0f);
			HealthSkill_2_P->SetPercent(HealthSkill_2_Clamp);
			if(HealthSkill_2_P->GetPercent() >= 1)
			{
				bHealthSkill2 = true;
			}
		}
		else
		{
			if(HealthSkill_2_CurrentProgress > 0 && bHealthSkill2 == false)
			{
				HealthSkill_2_CurrentProgress-=InDeltaTime;
				float HealthSkill_2_Clamp = FMath::Clamp(HealthSkill_2_CurrentProgress,0.0f,1.0f);
				HealthSkill_2_P->SetPercent(HealthSkill_2_Clamp);
			}
		}
	}
	else
	{
		HealthSkill_2_B->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	
	//STAMINA
	if(StaminaSkill_1_B->IsPressed() && bStaminaSkill_1 == false)
	{
		StaminaSkill_1_CurrentProgress+=InDeltaTime;
		float StaminaSkill_1_Clamp = FMath::Clamp(StaminaSkill_1_CurrentProgress,0.0f,1.0f);
		StaminaSkill_1_P->SetPercent(StaminaSkill_1_Clamp);
		if(StaminaSkill_1_P->GetPercent() >= 1)
		{
			bStaminaSkill_1 = true;
		}
	}
	else
	{
		if(StaminaSkill_1_CurrentProgress > 0 && bStaminaSkill_1 == false)
		{
			StaminaSkill_1_CurrentProgress-=InDeltaTime;
			float StaminaSkill_1_Clamp = FMath::Clamp(StaminaSkill_1_CurrentProgress,0.0f,1.0f);
			StaminaSkill_1_P->SetPercent(StaminaSkill_1_Clamp);
		}
	}

	if(bStaminaSkill_1)
	{
		StaminaSkill_2_B->SetVisibility(ESlateVisibility::Visible);
		if(StaminaSkill_2_B->IsPressed() && bStaminaSkill_2 == false)
		{
			StaminaSkill_2_CurrentProgress+=InDeltaTime;
			float StaminaSkill_2_Clamp = FMath::Clamp(StaminaSkill_2_CurrentProgress,0.0f,1.0f);
			StaminaSkill_2_P->SetPercent(StaminaSkill_2_Clamp);
			if(StaminaSkill_2_P->GetPercent() >= 1)
			{
				bStaminaSkill_2 = true;
			}
		}
		else
		{
			if(StaminaSkill_2_CurrentProgress > 0 && bStaminaSkill_2 == false)
			{
				StaminaSkill_2_CurrentProgress-=InDeltaTime;
				float StaminaSkill_2_Clamp = FMath::Clamp(StaminaSkill_2_CurrentProgress,0.0f,1.0f);
				StaminaSkill_2_P->SetPercent(StaminaSkill_2_Clamp);
			}
		}
	}
	else
	{
		StaminaSkill_2_B->SetVisibility(ESlateVisibility::HitTestInvisible);
	}

	//DAMAGE
	if(DamageSkill_1_B->IsPressed() && bDamageSkill_1 == false)
	{
		DamageSkill_1_CurrentProgress+=InDeltaTime;
		float DamageSkill_1_Clamp = FMath::Clamp(DamageSkill_1_CurrentProgress,0.0f,1.0f);
		DamageSkill_1_P->SetPercent(DamageSkill_1_Clamp);
		if(DamageSkill_1_P->GetPercent() >= 1)
		{
			bDamageSkill_1 = true;
		}
	}
	else
	{
		if(DamageSkill_1_CurrentProgress > 0 && bDamageSkill_1 == false)
		{
			DamageSkill_1_CurrentProgress-=InDeltaTime;
			float DamageSkill_1_Clamp = FMath::Clamp(DamageSkill_1_CurrentProgress,0.0f,1.0f);
			DamageSkill_1_P->SetPercent(DamageSkill_1_Clamp);
		}
	}

	if(bDamageSkill_1)
	{
		DamageSkill_2_B->SetVisibility(ESlateVisibility::Visible);
		if(DamageSkill_2_B->IsPressed() && bDamageSkill_2 == false)
		{
			DamageSkill_2_CurrentProgress+=InDeltaTime;
			float DamageSkill_2_Clamp = FMath::Clamp(DamageSkill_2_CurrentProgress,0.0f,1.0f);
			DamageSkill_2_P->SetPercent(DamageSkill_2_Clamp);
			if(DamageSkill_2_P->GetPercent() >= 1)
			{
				bDamageSkill_2 = true;
			}
		}
		else
		{
			if(DamageSkill_2_CurrentProgress > 0 && bDamageSkill_2 == false)
			{
				DamageSkill_2_CurrentProgress-=InDeltaTime;
				float DamageSkill_2_Clamp = FMath::Clamp(DamageSkill_2_CurrentProgress,0.0f,1.0f);
				DamageSkill_2_P->SetPercent(DamageSkill_2_Clamp);
			}
		}
	}
	else
	{
		DamageSkill_2_B->SetVisibility(ESlateVisibility::HitTestInvisible);
	}

}