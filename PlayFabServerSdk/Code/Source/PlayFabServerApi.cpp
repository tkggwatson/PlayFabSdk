#include "StdAfx.h"
#include "PlayFabServerApi.h"
#include "PlayFabSettings.h"

#include <AzCore/EBus/EBus.h>
#include "PlayFabServerSdk/PlayFabServer_ServerNotificationBus.h" // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)

using namespace PlayFabServerSdk;


// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
void PlayFabServerApi::OnError(const PlayFabRequest& request, const PlayFabError& error)
{
    EBUS_EVENT_ID(request.mRequestId,PlayFabServer_ServerNotificationBus, OnError, error);     
    EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnError, error, request.mRequestId);
}
// THIRD_KIND_END

// PlayFabServer Api
PlayFabServerApi::PlayFabServerApi() {}

int PlayFabServerApi::AuthenticateSessionTicket(
    ServerModels::AuthenticateSessionTicketRequest& request,
    ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AuthenticateSessionTicket"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAuthenticateSessionTicketResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAuthenticateSessionTicketResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::AuthenticateSessionTicketResult* outResult = new ServerModels::AuthenticateSessionTicketResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAuthenticateSessionTicket, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAuthenticateSessionTicket, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetPlayerSecret(
    ServerModels::SetPlayerSecretRequest& request,
    ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetPlayerSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPlayerSecretResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetPlayerSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetPlayerSecretResult* outResult = new ServerModels::SetPlayerSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetPlayerSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetPlayerSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetPlayerSecret, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetPlayerSecret, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::BanUsers(
    ServerModels::BanUsersRequest& request,
    ProcessApiCallback<ServerModels::BanUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/BanUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnBanUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnBanUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::BanUsersResult* outResult = new ServerModels::BanUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::BanUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::BanUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnBanUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnBanUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayerProfile(
    ServerModels::GetPlayerProfileRequest& request,
    ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayerProfile"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerProfileResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayerProfileResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayerProfileResult* outResult = new ServerModels::GetPlayerProfileResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayerProfileResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayerProfileResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayerProfile, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayerProfile, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayFabIDsFromFacebookIDs(
    ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayFabIDsFromFacebookIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromFacebookIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayFabIDsFromFacebookIDsResult* outResult = new ServerModels::GetPlayFabIDsFromFacebookIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayFabIDsFromFacebookIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayFabIDsFromFacebookIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayFabIDsFromSteamIDs(
    ServerModels::GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayFabIDsFromSteamIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromSteamIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayFabIDsFromSteamIDsResult* outResult = new ServerModels::GetPlayFabIDsFromSteamIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayFabIDsFromSteamIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayFabIDsFromSteamIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserAccountInfo(
    ServerModels::GetUserAccountInfoRequest& request,
    ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserAccountInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserAccountInfoResult* outResult = new ServerModels::GetUserAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserAccountInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserAccountInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserBans(
    ServerModels::GetUserBansRequest& request,
    ProcessApiCallback<ServerModels::GetUserBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserBansResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserBansResult* outResult = new ServerModels::GetUserBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserBansResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserBans, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserBans, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RevokeAllBansForUser(
    ServerModels::RevokeAllBansForUserRequest& request,
    ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RevokeAllBansForUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeAllBansForUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRevokeAllBansForUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RevokeAllBansForUserResult* outResult = new ServerModels::RevokeAllBansForUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RevokeAllBansForUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRevokeAllBansForUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRevokeAllBansForUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RevokeBans(
    ServerModels::RevokeBansRequest& request,
    ProcessApiCallback<ServerModels::RevokeBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RevokeBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeBansResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRevokeBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RevokeBansResult* outResult = new ServerModels::RevokeBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RevokeBansResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RevokeBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRevokeBans, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRevokeBans, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SendPushNotification(
    ServerModels::SendPushNotificationRequest& request,
    ProcessApiCallback<ServerModels::SendPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SendPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSendPushNotificationResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSendPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SendPushNotificationResult* outResult = new ServerModels::SendPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SendPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SendPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSendPushNotification, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSendPushNotification, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateAvatarUrl(
    ServerModels::UpdateAvatarUrlRequest& request,
    ProcessApiCallback<ServerModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateAvatarUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateAvatarUrlResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateAvatarUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EmptyResult* outResult = new ServerModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateAvatarUrl, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateAvatarUrl, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateBans(
    ServerModels::UpdateBansRequest& request,
    ProcessApiCallback<ServerModels::UpdateBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateBansResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateBansResult* outResult = new ServerModels::UpdateBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateBansResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateBans, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateBans, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::DeleteUsers(
    ServerModels::DeleteUsersRequest& request,
    ProcessApiCallback<ServerModels::DeleteUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/DeleteUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnDeleteUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::DeleteUsersResult* outResult = new ServerModels::DeleteUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::DeleteUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::DeleteUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnDeleteUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnDeleteUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetFriendLeaderboard(
    ServerModels::GetFriendLeaderboardRequest& request,
    ProcessApiCallback<ServerModels::GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetFriendLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetFriendLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetLeaderboardResult* outResult = new ServerModels::GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetFriendLeaderboard, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetFriendLeaderboard, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetLeaderboard(
    ServerModels::GetLeaderboardRequest& request,
    ProcessApiCallback<ServerModels::GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetLeaderboardResult* outResult = new ServerModels::GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetLeaderboard, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetLeaderboard, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetLeaderboardAroundUser(
    ServerModels::GetLeaderboardAroundUserRequest& request,
    ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetLeaderboardAroundUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetLeaderboardAroundUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetLeaderboardAroundUserResult* outResult = new ServerModels::GetLeaderboardAroundUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetLeaderboardAroundUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetLeaderboardAroundUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayerCombinedInfo(
    ServerModels::GetPlayerCombinedInfoRequest& request,
    ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayerCombinedInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerCombinedInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayerCombinedInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayerCombinedInfoResult* outResult = new ServerModels::GetPlayerCombinedInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayerCombinedInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayerCombinedInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayerStatistics(
    ServerModels::GetPlayerStatisticsRequest& request,
    ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayerStatisticsResult* outResult = new ServerModels::GetPlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayerStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayerStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayerStatisticVersions(
    ServerModels::GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayerStatisticVersionsResult* outResult = new ServerModels::GetPlayerStatisticVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayerStatisticVersions, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayerStatisticVersions, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserData(
    ServerModels::GetUserDataRequest& request,
    ProcessApiCallback<ServerModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserDataResult* outResult = new ServerModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserInternalData(
    ServerModels::GetUserDataRequest& request,
    ProcessApiCallback<ServerModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserDataResult* outResult = new ServerModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserPublisherData(
    ServerModels::GetUserDataRequest& request,
    ProcessApiCallback<ServerModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserDataResult* outResult = new ServerModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserPublisherInternalData(
    ServerModels::GetUserDataRequest& request,
    ProcessApiCallback<ServerModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserPublisherInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserDataResult* outResult = new ServerModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserPublisherInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserPublisherInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserPublisherReadOnlyData(
    ServerModels::GetUserDataRequest& request,
    ProcessApiCallback<ServerModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserDataResult* outResult = new ServerModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserPublisherReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserPublisherReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserReadOnlyData(
    ServerModels::GetUserDataRequest& request,
    ProcessApiCallback<ServerModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserDataResult* outResult = new ServerModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdatePlayerStatistics(
    ServerModels::UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdatePlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdatePlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdatePlayerStatisticsResult* outResult = new ServerModels::UpdatePlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdatePlayerStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdatePlayerStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserData(
    ServerModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateUserDataResult* outResult = new ServerModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserInternalData(
    ServerModels::UpdateUserInternalDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateUserDataResult* outResult = new ServerModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserPublisherData(
    ServerModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateUserDataResult* outResult = new ServerModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserPublisherInternalData(
    ServerModels::UpdateUserInternalDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateUserDataResult* outResult = new ServerModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserPublisherInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserPublisherInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserPublisherReadOnlyData(
    ServerModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateUserDataResult* outResult = new ServerModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserPublisherReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserPublisherReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserReadOnlyData(
    ServerModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateUserDataResult* outResult = new ServerModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCatalogItems(
    ServerModels::GetCatalogItemsRequest& request,
    ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCatalogItemsResult* outResult = new ServerModels::GetCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCatalogItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCatalogItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPublisherData(
    ServerModels::GetPublisherDataRequest& request,
    ProcessApiCallback<ServerModels::GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPublisherDataResult* outResult = new ServerModels::GetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetTime(

    ProcessApiCallback<ServerModels::GetTimeResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetTime"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetTimeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetTimeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetTimeResult* outResult = new ServerModels::GetTimeResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetTimeResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetTimeResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetTime, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetTime, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetTitleData(
    ServerModels::GetTitleDataRequest& request,
    ProcessApiCallback<ServerModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetTitleDataResult* outResult = new ServerModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetTitleData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetTitleData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetTitleInternalData(
    ServerModels::GetTitleDataRequest& request,
    ProcessApiCallback<ServerModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetTitleDataResult* outResult = new ServerModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetTitleInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetTitleInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetTitleNews(
    ServerModels::GetTitleNewsRequest& request,
    ProcessApiCallback<ServerModels::GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetTitleNews"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleNewsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetTitleNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetTitleNewsResult* outResult = new ServerModels::GetTitleNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetTitleNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetTitleNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetTitleNews, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetTitleNews, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetPublisherData(
    ServerModels::SetPublisherDataRequest& request,
    ProcessApiCallback<ServerModels::SetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetPublisherDataResult* outResult = new ServerModels::SetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetTitleData(
    ServerModels::SetTitleDataRequest& request,
    ProcessApiCallback<ServerModels::SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetTitleDataResult* outResult = new ServerModels::SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetTitleData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetTitleData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetTitleInternalData(
    ServerModels::SetTitleDataRequest& request,
    ProcessApiCallback<ServerModels::SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetTitleDataResult* outResult = new ServerModels::SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetTitleInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetTitleInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::AddCharacterVirtualCurrency(
    ServerModels::AddCharacterVirtualCurrencyRequest& request,
    ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AddCharacterVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddCharacterVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAddCharacterVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ModifyCharacterVirtualCurrencyResult* outResult = new ServerModels::ModifyCharacterVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAddCharacterVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAddCharacterVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::AddUserVirtualCurrency(
    ServerModels::AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ModifyUserVirtualCurrencyResult* outResult = new ServerModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAddUserVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAddUserVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::ConsumeItem(
    ServerModels::ConsumeItemRequest& request,
    ProcessApiCallback<ServerModels::ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/ConsumeItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnConsumeItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnConsumeItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ConsumeItemResult* outResult = new ServerModels::ConsumeItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ConsumeItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ConsumeItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnConsumeItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnConsumeItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::EvaluateRandomResultTable(
    ServerModels::EvaluateRandomResultTableRequest& request,
    ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/EvaluateRandomResultTable"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnEvaluateRandomResultTableResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnEvaluateRandomResultTableResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EvaluateRandomResultTableResult* outResult = new ServerModels::EvaluateRandomResultTableResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnEvaluateRandomResultTable, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnEvaluateRandomResultTable, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCharacterInventory(
    ServerModels::GetCharacterInventoryRequest& request,
    ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCharacterInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInventoryResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCharacterInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCharacterInventoryResult* outResult = new ServerModels::GetCharacterInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCharacterInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCharacterInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCharacterInventory, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCharacterInventory, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetRandomResultTables(
    ServerModels::GetRandomResultTablesRequest& request,
    ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetRandomResultTablesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetRandomResultTablesResult* outResult = new ServerModels::GetRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetRandomResultTables, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetRandomResultTables, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetUserInventory(
    ServerModels::GetUserInventoryRequest& request,
    ProcessApiCallback<ServerModels::GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInventoryResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetUserInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetUserInventoryResult* outResult = new ServerModels::GetUserInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetUserInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetUserInventory, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetUserInventory, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GrantItemsToCharacter(
    ServerModels::GrantItemsToCharacterRequest& request,
    ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GrantItemsToCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToCharacterResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGrantItemsToCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GrantItemsToCharacterResult* outResult = new ServerModels::GrantItemsToCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GrantItemsToCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGrantItemsToCharacter, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGrantItemsToCharacter, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GrantItemsToUser(
    ServerModels::GrantItemsToUserRequest& request,
    ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GrantItemsToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGrantItemsToUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GrantItemsToUserResult* outResult = new ServerModels::GrantItemsToUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GrantItemsToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GrantItemsToUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGrantItemsToUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGrantItemsToUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GrantItemsToUsers(
    ServerModels::GrantItemsToUsersRequest& request,
    ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GrantItemsToUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGrantItemsToUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GrantItemsToUsersResult* outResult = new ServerModels::GrantItemsToUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GrantItemsToUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GrantItemsToUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGrantItemsToUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGrantItemsToUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::ModifyItemUses(
    ServerModels::ModifyItemUsesRequest& request,
    ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/ModifyItemUses"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyItemUsesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnModifyItemUsesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ModifyItemUsesResult* outResult = new ServerModels::ModifyItemUsesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ModifyItemUsesResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ModifyItemUsesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnModifyItemUses, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnModifyItemUses, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::MoveItemToCharacterFromCharacter(
    ServerModels::MoveItemToCharacterFromCharacterRequest& request,
    ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/MoveItemToCharacterFromCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnMoveItemToCharacterFromCharacterResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnMoveItemToCharacterFromCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::MoveItemToCharacterFromCharacterResult* outResult = new ServerModels::MoveItemToCharacterFromCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnMoveItemToCharacterFromCharacter, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnMoveItemToCharacterFromCharacter, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::MoveItemToCharacterFromUser(
    ServerModels::MoveItemToCharacterFromUserRequest& request,
    ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/MoveItemToCharacterFromUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnMoveItemToCharacterFromUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnMoveItemToCharacterFromUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::MoveItemToCharacterFromUserResult* outResult = new ServerModels::MoveItemToCharacterFromUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnMoveItemToCharacterFromUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnMoveItemToCharacterFromUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::MoveItemToUserFromCharacter(
    ServerModels::MoveItemToUserFromCharacterRequest& request,
    ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/MoveItemToUserFromCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnMoveItemToUserFromCharacterResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnMoveItemToUserFromCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::MoveItemToUserFromCharacterResult* outResult = new ServerModels::MoveItemToUserFromCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnMoveItemToUserFromCharacter, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnMoveItemToUserFromCharacter, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RedeemCoupon(
    ServerModels::RedeemCouponRequest& request,
    ProcessApiCallback<ServerModels::RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RedeemCoupon"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRedeemCouponResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRedeemCouponResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RedeemCouponResult* outResult = new ServerModels::RedeemCouponResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RedeemCouponResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RedeemCouponResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRedeemCoupon, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRedeemCoupon, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::ReportPlayer(
    ServerModels::ReportPlayerServerRequest& request,
    ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/ReportPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnReportPlayerResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnReportPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ReportPlayerServerResult* outResult = new ServerModels::ReportPlayerServerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ReportPlayerServerResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ReportPlayerServerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnReportPlayer, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnReportPlayer, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RevokeInventoryItem(
    ServerModels::RevokeInventoryItemRequest& request,
    ProcessApiCallback<ServerModels::RevokeInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RevokeInventoryItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeInventoryItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRevokeInventoryItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RevokeInventoryResult* outResult = new ServerModels::RevokeInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RevokeInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RevokeInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRevokeInventoryItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRevokeInventoryItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SubtractCharacterVirtualCurrency(
    ServerModels::SubtractCharacterVirtualCurrencyRequest& request,
    ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SubtractCharacterVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractCharacterVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSubtractCharacterVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ModifyCharacterVirtualCurrencyResult* outResult = new ServerModels::ModifyCharacterVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSubtractCharacterVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSubtractCharacterVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SubtractUserVirtualCurrency(
    ServerModels::SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ModifyUserVirtualCurrencyResult* outResult = new ServerModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSubtractUserVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSubtractUserVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UnlockContainerInstance(
    ServerModels::UnlockContainerInstanceRequest& request,
    ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UnlockContainerInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerInstanceResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUnlockContainerInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UnlockContainerItemResult* outResult = new ServerModels::UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUnlockContainerInstance, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUnlockContainerInstance, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UnlockContainerItem(
    ServerModels::UnlockContainerItemRequest& request,
    ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UnlockContainerItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUnlockContainerItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UnlockContainerItemResult* outResult = new ServerModels::UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUnlockContainerItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUnlockContainerItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateUserInventoryItemCustomData(
    ServerModels::UpdateUserInventoryItemDataRequest& request,
    ProcessApiCallback<ServerModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateUserInventoryItemCustomData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInventoryItemCustomDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateUserInventoryItemCustomDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EmptyResult* outResult = new ServerModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateUserInventoryItemCustomData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateUserInventoryItemCustomData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::AddFriend(
    ServerModels::AddFriendRequest& request,
    ProcessApiCallback<ServerModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AddFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddFriendResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAddFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EmptyResult* outResult = new ServerModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAddFriend, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAddFriend, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetFriendsList(
    ServerModels::GetFriendsListRequest& request,
    ProcessApiCallback<ServerModels::GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetFriendsList"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetFriendsListResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetFriendsListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetFriendsListResult* outResult = new ServerModels::GetFriendsListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetFriendsListResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetFriendsListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetFriendsList, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetFriendsList, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RemoveFriend(
    ServerModels::RemoveFriendRequest& request,
    ProcessApiCallback<ServerModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RemoveFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveFriendResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRemoveFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EmptyResult* outResult = new ServerModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRemoveFriend, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRemoveFriend, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetFriendTags(
    ServerModels::SetFriendTagsRequest& request,
    ProcessApiCallback<ServerModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetFriendTags"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetFriendTagsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetFriendTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EmptyResult* outResult = new ServerModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetFriendTags, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetFriendTags, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::DeregisterGame(
    ServerModels::DeregisterGameRequest& request,
    ProcessApiCallback<ServerModels::DeregisterGameResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/DeregisterGame"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeregisterGameResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnDeregisterGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::DeregisterGameResponse* outResult = new ServerModels::DeregisterGameResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::DeregisterGameResponse> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::DeregisterGameResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnDeregisterGame, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnDeregisterGame, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::NotifyMatchmakerPlayerLeft(
    ServerModels::NotifyMatchmakerPlayerLeftRequest& request,
    ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/NotifyMatchmakerPlayerLeft"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnNotifyMatchmakerPlayerLeftResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnNotifyMatchmakerPlayerLeftResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::NotifyMatchmakerPlayerLeftResult* outResult = new ServerModels::NotifyMatchmakerPlayerLeftResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnNotifyMatchmakerPlayerLeft, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnNotifyMatchmakerPlayerLeft, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RedeemMatchmakerTicket(
    ServerModels::RedeemMatchmakerTicketRequest& request,
    ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RedeemMatchmakerTicket"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRedeemMatchmakerTicketResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRedeemMatchmakerTicketResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RedeemMatchmakerTicketResult* outResult = new ServerModels::RedeemMatchmakerTicketResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRedeemMatchmakerTicket, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRedeemMatchmakerTicket, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RefreshGameServerInstanceHeartbeat(
    ServerModels::RefreshGameServerInstanceHeartbeatRequest& request,
    ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RefreshGameServerInstanceHeartbeat"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRefreshGameServerInstanceHeartbeatResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRefreshGameServerInstanceHeartbeatResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RefreshGameServerInstanceHeartbeatResult* outResult = new ServerModels::RefreshGameServerInstanceHeartbeatResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRefreshGameServerInstanceHeartbeat, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRefreshGameServerInstanceHeartbeat, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RegisterGame(
    ServerModels::RegisterGameRequest& request,
    ProcessApiCallback<ServerModels::RegisterGameResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RegisterGame"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRegisterGameResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRegisterGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RegisterGameResponse* outResult = new ServerModels::RegisterGameResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RegisterGameResponse> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RegisterGameResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRegisterGame, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRegisterGame, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetGameServerInstanceData(
    ServerModels::SetGameServerInstanceDataRequest& request,
    ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetGameServerInstanceData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetGameServerInstanceDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetGameServerInstanceDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetGameServerInstanceDataResult* outResult = new ServerModels::SetGameServerInstanceDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetGameServerInstanceData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetGameServerInstanceData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetGameServerInstanceState(
    ServerModels::SetGameServerInstanceStateRequest& request,
    ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetGameServerInstanceState"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetGameServerInstanceStateResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetGameServerInstanceStateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetGameServerInstanceStateResult* outResult = new ServerModels::SetGameServerInstanceStateResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetGameServerInstanceState, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetGameServerInstanceState, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::SetGameServerInstanceTags(
    ServerModels::SetGameServerInstanceTagsRequest& request,
    ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/SetGameServerInstanceTags"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetGameServerInstanceTagsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnSetGameServerInstanceTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::SetGameServerInstanceTagsResult* outResult = new ServerModels::SetGameServerInstanceTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnSetGameServerInstanceTags, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnSetGameServerInstanceTags, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::WriteCharacterEvent(
    ServerModels::WriteServerCharacterEventRequest& request,
    ProcessApiCallback<ServerModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/WriteCharacterEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnWriteCharacterEventResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnWriteCharacterEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::WriteEventResponse* outResult = new ServerModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnWriteCharacterEvent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnWriteCharacterEvent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::WritePlayerEvent(
    ServerModels::WriteServerPlayerEventRequest& request,
    ProcessApiCallback<ServerModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/WritePlayerEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnWritePlayerEventResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnWritePlayerEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::WriteEventResponse* outResult = new ServerModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnWritePlayerEvent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnWritePlayerEvent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::WriteTitleEvent(
    ServerModels::WriteTitleEventRequest& request,
    ProcessApiCallback<ServerModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/WriteTitleEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnWriteTitleEventResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnWriteTitleEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::WriteEventResponse* outResult = new ServerModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnWriteTitleEvent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnWriteTitleEvent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::AddSharedGroupMembers(
    ServerModels::AddSharedGroupMembersRequest& request,
    ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AddSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddSharedGroupMembersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAddSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::AddSharedGroupMembersResult* outResult = new ServerModels::AddSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::AddSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAddSharedGroupMembers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAddSharedGroupMembers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::CreateSharedGroup(
    ServerModels::CreateSharedGroupRequest& request,
    ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/CreateSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreateSharedGroupResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnCreateSharedGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::CreateSharedGroupResult* outResult = new ServerModels::CreateSharedGroupResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::CreateSharedGroupResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::CreateSharedGroupResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnCreateSharedGroup, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnCreateSharedGroup, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::DeleteSharedGroup(
    ServerModels::DeleteSharedGroupRequest& request,
    ProcessApiCallback<ServerModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/DeleteSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteSharedGroupResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnDeleteSharedGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::EmptyResult* outResult = new ServerModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnDeleteSharedGroup, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnDeleteSharedGroup, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetSharedGroupData(
    ServerModels::GetSharedGroupDataRequest& request,
    ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetSharedGroupDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetSharedGroupDataResult* outResult = new ServerModels::GetSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetSharedGroupData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetSharedGroupData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RemoveSharedGroupMembers(
    ServerModels::RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RemoveSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveSharedGroupMembersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRemoveSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RemoveSharedGroupMembersResult* outResult = new ServerModels::RemoveSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRemoveSharedGroupMembers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRemoveSharedGroupMembers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateSharedGroupData(
    ServerModels::UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateSharedGroupDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateSharedGroupDataResult* outResult = new ServerModels::UpdateSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateSharedGroupData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateSharedGroupData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::ExecuteCloudScript(
    ServerModels::ExecuteCloudScriptServerRequest& request,
    ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/ExecuteCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnExecuteCloudScriptResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnExecuteCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ExecuteCloudScriptResult* outResult = new ServerModels::ExecuteCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ExecuteCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnExecuteCloudScript, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnExecuteCloudScript, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetContentDownloadUrl(
    ServerModels::GetContentDownloadUrlRequest& request,
    ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetContentDownloadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentDownloadUrlResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetContentDownloadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetContentDownloadUrlResult* outResult = new ServerModels::GetContentDownloadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetContentDownloadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetContentDownloadUrl, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetContentDownloadUrl, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::DeleteCharacterFromUser(
    ServerModels::DeleteCharacterFromUserRequest& request,
    ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/DeleteCharacterFromUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteCharacterFromUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnDeleteCharacterFromUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::DeleteCharacterFromUserResult* outResult = new ServerModels::DeleteCharacterFromUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnDeleteCharacterFromUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnDeleteCharacterFromUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetAllUsersCharacters(
    ServerModels::ListUsersCharactersRequest& request,
    ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetAllUsersCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetAllUsersCharactersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetAllUsersCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::ListUsersCharactersResult* outResult = new ServerModels::ListUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::ListUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::ListUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetAllUsersCharacters, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetAllUsersCharacters, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCharacterLeaderboard(
    ServerModels::GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCharacterLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterLeaderboardResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCharacterLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCharacterLeaderboardResult* outResult = new ServerModels::GetCharacterLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCharacterLeaderboard, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCharacterLeaderboard, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCharacterStatistics(
    ServerModels::GetCharacterStatisticsRequest& request,
    ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCharacterStatisticsResult* outResult = new ServerModels::GetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCharacterStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCharacterStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetLeaderboardAroundCharacter(
    ServerModels::GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetLeaderboardAroundCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCharacterResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetLeaderboardAroundCharacterResult* outResult = new ServerModels::GetLeaderboardAroundCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetLeaderboardAroundCharacter, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetLeaderboardAroundCharacter, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetLeaderboardForUserCharacters(
    ServerModels::GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetLeaderboardForUserCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardForUserCharactersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetLeaderboardForUsersCharactersResult* outResult = new ServerModels::GetLeaderboardForUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetLeaderboardForUserCharacters, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetLeaderboardForUserCharacters, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GrantCharacterToUser(
    ServerModels::GrantCharacterToUserRequest& request,
    ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GrantCharacterToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantCharacterToUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGrantCharacterToUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GrantCharacterToUserResult* outResult = new ServerModels::GrantCharacterToUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GrantCharacterToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GrantCharacterToUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGrantCharacterToUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGrantCharacterToUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateCharacterStatistics(
    ServerModels::UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateCharacterStatisticsResult* outResult = new ServerModels::UpdateCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateCharacterStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateCharacterStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCharacterData(
    ServerModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ServerModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCharacterDataResult* outResult = new ServerModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCharacterData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCharacterData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCharacterInternalData(
    ServerModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ServerModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCharacterInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCharacterInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCharacterDataResult* outResult = new ServerModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCharacterInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCharacterInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetCharacterReadOnlyData(
    ServerModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ServerModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetCharacterReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetCharacterDataResult* outResult = new ServerModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetCharacterReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetCharacterReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateCharacterData(
    ServerModels::UpdateCharacterDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateCharacterDataResult* outResult = new ServerModels::UpdateCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateCharacterData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateCharacterData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateCharacterInternalData(
    ServerModels::UpdateCharacterDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateCharacterInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateCharacterInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateCharacterDataResult* outResult = new ServerModels::UpdateCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateCharacterInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateCharacterInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::UpdateCharacterReadOnlyData(
    ServerModels::UpdateCharacterDataRequest& request,
    ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/UpdateCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnUpdateCharacterReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::UpdateCharacterDataResult* outResult = new ServerModels::UpdateCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::UpdateCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnUpdateCharacterReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnUpdateCharacterReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::AddPlayerTag(
    ServerModels::AddPlayerTagRequest& request,
    ProcessApiCallback<ServerModels::AddPlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AddPlayerTag"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddPlayerTagResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAddPlayerTagResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::AddPlayerTagResult* outResult = new ServerModels::AddPlayerTagResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::AddPlayerTagResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::AddPlayerTagResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAddPlayerTag, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAddPlayerTag, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetAllActionGroups(

    ProcessApiCallback<ServerModels::GetAllActionGroupsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetAllActionGroups"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetAllActionGroupsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetAllActionGroupsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetAllActionGroupsResult* outResult = new ServerModels::GetAllActionGroupsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetAllActionGroupsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetAllActionGroupsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetAllActionGroups, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetAllActionGroups, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetAllSegments(

    ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetAllSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetAllSegmentsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetAllSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetAllSegmentsResult* outResult = new ServerModels::GetAllSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetAllSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetAllSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetAllSegments, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetAllSegments, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayerSegments(
    ServerModels::GetPlayersSegmentsRequest& request,
    ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayerSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerSegmentsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayerSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayerSegmentsResult* outResult = new ServerModels::GetPlayerSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayerSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayerSegments, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayerSegments, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayersInSegment(
    ServerModels::GetPlayersInSegmentRequest& request,
    ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayersInSegment"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayersInSegmentResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayersInSegmentResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayersInSegmentResult* outResult = new ServerModels::GetPlayersInSegmentResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayersInSegmentResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayersInSegment, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayersInSegment, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::GetPlayerTags(
    ServerModels::GetPlayerTagsRequest& request,
    ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/GetPlayerTags"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTagsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnGetPlayerTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::GetPlayerTagsResult* outResult = new ServerModels::GetPlayerTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::GetPlayerTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::GetPlayerTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnGetPlayerTags, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnGetPlayerTags, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::RemovePlayerTag(
    ServerModels::RemovePlayerTagRequest& request,
    ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/RemovePlayerTag"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemovePlayerTagResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnRemovePlayerTagResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::RemovePlayerTagResult* outResult = new ServerModels::RemovePlayerTagResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::RemovePlayerTagResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::RemovePlayerTagResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnRemovePlayerTag, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnRemovePlayerTag, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabServerApi::AwardSteamAchievement(
    ServerModels::AwardSteamAchievementRequest& request,
    ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Server/AwardSteamAchievement"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAwardSteamAchievementResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabServerApi::OnAwardSteamAchievementResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ServerModels::AwardSteamAchievementResult* outResult = new ServerModels::AwardSteamAchievementResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ServerModels::AwardSteamAchievementResult> successCallback = reinterpret_cast<ProcessApiCallback<ServerModels::AwardSteamAchievementResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_ServerNotificationBus, OnAwardSteamAchievement, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_ServerGlobalNotificationBus, OnAwardSteamAchievement, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

