






	// Fill out your copyright notice in the Description page of Project Settings.


#include "AtorFlutuante.h"

// Sets default values
AAtorFlutuante::AAtorFlutuante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TempoExecucao = 0.0f;
	AlturaDelta = 0.0f;
	NovaLocalizacao = FVector(0.f, 0.f, 0.f);

}

// Called when the game starts or when spawned
void AAtorFlutuante::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAtorFlutuante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NovaLocalizacao = this->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("NovaLocalizacao: %s\n"), *NovaLocalizacao.ToString());
	AlturaDelta = (FMath::Sin(TempoExecucao + DeltaTime) - FMath::Sin(TempoExecucao));
	UE_LOG(LogTemp, Warning, TEXT("AlturaDelta: %f\n"), AlturaDelta);
	NovaLocalizacao.Z += AlturaDelta * 20.f;
	UE_LOG(LogTemp, Warning, TEXT("NovaLocalizacao: %s\n"), *NovaLocalizacao.ToString());
	TempoExecucao += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("TempoExecucao: %f"), TempoExecucao);
	this->SetActorLocation(NovaLocalizacao);

}

