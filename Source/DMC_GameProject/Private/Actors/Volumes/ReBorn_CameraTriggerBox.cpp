// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_CameraTriggerBox.h"
#include "Components/ShapeComponent.h"

AReBorn_CameraTriggerBox::AReBorn_CameraTriggerBox()
{
	//CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AReBorn_CameraTriggerBox::OnOverlapBegin);
	//CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AReBorn_CameraTriggerBox::OnOverlapEnd);
}

void AReBorn_CameraTriggerBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (OtherActor != nullptr)
	//{
	//	AReBorn_Character* Character = Cast<AReBorn_Character>(OtherActor);
	//	if (Character)
	//	{
	//		Character->SwitchCamera(Camera);
	//	}
	//}
}

void AReBorn_CameraTriggerBox::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
