// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "S1.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "S1GameInstance.generated.h"

class AS1Player;

/**
 * 
 */
UCLASS()
class S1_API US1GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ConnectToGameServer();

	UFUNCTION(BlueprintCallable)
	void DisconnectFromGameServer();

	UFUNCTION(BlueprintCallable)
	void HandleRecvPackets();

	void SendPacket(SendBufferRef SendBuffer);

public:
	void HandleSpawn(const Protocol::ObjectInfo& ObjectInfo, bool IsMine);
	void HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt);
	void HandleSpawn(const Protocol::S_SPAWN& SpawnPkt);

	void HandleDespawn(uint64 ObjectId);
	void HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt);

	void HandleMove(const Protocol::S_MOVE& MovePkt);


public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT("127.0.0.1");
	int16 Port = 7777;
	TSharedPtr<class PacketSession> GameServerSession;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  OtherPlayerClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  OtherPlayerYoshika;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  OtherPlayerLynette;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  OtherPlayerSanya;


	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  MyPlayerClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  MyPlayerYoshika;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  MyPlayerLynette;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player>  MyPlayerSanya;

	AS1Player* MyPlayer;
	TMap<uint64, AS1Player*> Players;

	
};
