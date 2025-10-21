// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LanWidget.generated.h"

class UEditableTextBox;
class UButton;
/**
 * 
 */
UCLASS() 
class PROYECTOEJERCICIO_API ULanWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	
public:

private:
	
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Hostear;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Unirse;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> EditableTextBox_DireccionIP;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> Level;

	UFUNCTION()
	void OnButtonHostearClicked();

	UFUNCTION()
	void OnButtonUnirseClicked();
};
