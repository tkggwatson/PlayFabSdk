#pragma once

#include <PlayFabComboSdk/PlayFabError.h>
#include <PlayFabComboSdk/PlayFabServerDataModels.h>
#include <PlayFabComboSdk/PlayFabHttp.h>

namespace PlayFabComboSdk
{
    class PlayFabServerApi
    {
    public:


        // ------------ Error callback
        static void OnError(const PlayFabRequest& request, const PlayFabError& error);

        // ------------ Generated Api calls
        static int AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTime(ProcessApiCallback<ServerModels::GetTimeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetAllActionGroups(ProcessApiCallback<ServerModels::GetAllActionGroupsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetAllSegments(ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabServerApi();

        // ------------ Generated result handlers
        static void OnAuthenticateSessionTicketResult(PlayFabRequest* request);
        static void OnSetPlayerSecretResult(PlayFabRequest* request);
        static void OnBanUsersResult(PlayFabRequest* request);
        static void OnGetPlayerProfileResult(PlayFabRequest* request);
        static void OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request);
        static void OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request);
        static void OnGetUserAccountInfoResult(PlayFabRequest* request);
        static void OnGetUserBansResult(PlayFabRequest* request);
        static void OnRevokeAllBansForUserResult(PlayFabRequest* request);
        static void OnRevokeBansResult(PlayFabRequest* request);
        static void OnSendPushNotificationResult(PlayFabRequest* request);
        static void OnUpdateAvatarUrlResult(PlayFabRequest* request);
        static void OnUpdateBansResult(PlayFabRequest* request);
        static void OnDeleteUsersResult(PlayFabRequest* request);
        static void OnGetFriendLeaderboardResult(PlayFabRequest* request);
        static void OnGetLeaderboardResult(PlayFabRequest* request);
        static void OnGetLeaderboardAroundUserResult(PlayFabRequest* request);
        static void OnGetPlayerCombinedInfoResult(PlayFabRequest* request);
        static void OnGetPlayerStatisticsResult(PlayFabRequest* request);
        static void OnGetPlayerStatisticVersionsResult(PlayFabRequest* request);
        static void OnGetUserDataResult(PlayFabRequest* request);
        static void OnGetUserInternalDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherInternalDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request);
        static void OnGetUserReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdatePlayerStatisticsResult(PlayFabRequest* request);
        static void OnUpdateUserDataResult(PlayFabRequest* request);
        static void OnUpdateUserInternalDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdateUserReadOnlyDataResult(PlayFabRequest* request);
        static void OnGetCatalogItemsResult(PlayFabRequest* request);
        static void OnGetPublisherDataResult(PlayFabRequest* request);
        static void OnGetTimeResult(PlayFabRequest* request);
        static void OnGetTitleDataResult(PlayFabRequest* request);
        static void OnGetTitleInternalDataResult(PlayFabRequest* request);
        static void OnGetTitleNewsResult(PlayFabRequest* request);
        static void OnSetPublisherDataResult(PlayFabRequest* request);
        static void OnSetTitleDataResult(PlayFabRequest* request);
        static void OnSetTitleInternalDataResult(PlayFabRequest* request);
        static void OnAddCharacterVirtualCurrencyResult(PlayFabRequest* request);
        static void OnAddUserVirtualCurrencyResult(PlayFabRequest* request);
        static void OnConsumeItemResult(PlayFabRequest* request);
        static void OnEvaluateRandomResultTableResult(PlayFabRequest* request);
        static void OnGetCharacterInventoryResult(PlayFabRequest* request);
        static void OnGetRandomResultTablesResult(PlayFabRequest* request);
        static void OnGetUserInventoryResult(PlayFabRequest* request);
        static void OnGrantItemsToCharacterResult(PlayFabRequest* request);
        static void OnGrantItemsToUserResult(PlayFabRequest* request);
        static void OnGrantItemsToUsersResult(PlayFabRequest* request);
        static void OnModifyItemUsesResult(PlayFabRequest* request);
        static void OnMoveItemToCharacterFromCharacterResult(PlayFabRequest* request);
        static void OnMoveItemToCharacterFromUserResult(PlayFabRequest* request);
        static void OnMoveItemToUserFromCharacterResult(PlayFabRequest* request);
        static void OnRedeemCouponResult(PlayFabRequest* request);
        static void OnReportPlayerResult(PlayFabRequest* request);
        static void OnRevokeInventoryItemResult(PlayFabRequest* request);
        static void OnSubtractCharacterVirtualCurrencyResult(PlayFabRequest* request);
        static void OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request);
        static void OnUnlockContainerInstanceResult(PlayFabRequest* request);
        static void OnUnlockContainerItemResult(PlayFabRequest* request);
        static void OnUpdateUserInventoryItemCustomDataResult(PlayFabRequest* request);
        static void OnAddFriendResult(PlayFabRequest* request);
        static void OnGetFriendsListResult(PlayFabRequest* request);
        static void OnRemoveFriendResult(PlayFabRequest* request);
        static void OnSetFriendTagsResult(PlayFabRequest* request);
        static void OnDeregisterGameResult(PlayFabRequest* request);
        static void OnNotifyMatchmakerPlayerLeftResult(PlayFabRequest* request);
        static void OnRedeemMatchmakerTicketResult(PlayFabRequest* request);
        static void OnRefreshGameServerInstanceHeartbeatResult(PlayFabRequest* request);
        static void OnRegisterGameResult(PlayFabRequest* request);
        static void OnSetGameServerInstanceDataResult(PlayFabRequest* request);
        static void OnSetGameServerInstanceStateResult(PlayFabRequest* request);
        static void OnSetGameServerInstanceTagsResult(PlayFabRequest* request);
        static void OnWriteCharacterEventResult(PlayFabRequest* request);
        static void OnWritePlayerEventResult(PlayFabRequest* request);
        static void OnWriteTitleEventResult(PlayFabRequest* request);
        static void OnAddSharedGroupMembersResult(PlayFabRequest* request);
        static void OnCreateSharedGroupResult(PlayFabRequest* request);
        static void OnDeleteSharedGroupResult(PlayFabRequest* request);
        static void OnGetSharedGroupDataResult(PlayFabRequest* request);
        static void OnRemoveSharedGroupMembersResult(PlayFabRequest* request);
        static void OnUpdateSharedGroupDataResult(PlayFabRequest* request);
        static void OnExecuteCloudScriptResult(PlayFabRequest* request);
        static void OnGetContentDownloadUrlResult(PlayFabRequest* request);
        static void OnDeleteCharacterFromUserResult(PlayFabRequest* request);
        static void OnGetAllUsersCharactersResult(PlayFabRequest* request);
        static void OnGetCharacterLeaderboardResult(PlayFabRequest* request);
        static void OnGetCharacterStatisticsResult(PlayFabRequest* request);
        static void OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request);
        static void OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request);
        static void OnGrantCharacterToUserResult(PlayFabRequest* request);
        static void OnUpdateCharacterStatisticsResult(PlayFabRequest* request);
        static void OnGetCharacterDataResult(PlayFabRequest* request);
        static void OnGetCharacterInternalDataResult(PlayFabRequest* request);
        static void OnGetCharacterReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdateCharacterDataResult(PlayFabRequest* request);
        static void OnUpdateCharacterInternalDataResult(PlayFabRequest* request);
        static void OnUpdateCharacterReadOnlyDataResult(PlayFabRequest* request);
        static void OnAddPlayerTagResult(PlayFabRequest* request);
        static void OnGetAllActionGroupsResult(PlayFabRequest* request);
        static void OnGetAllSegmentsResult(PlayFabRequest* request);
        static void OnGetPlayerSegmentsResult(PlayFabRequest* request);
        static void OnGetPlayersInSegmentResult(PlayFabRequest* request);
        static void OnGetPlayerTagsResult(PlayFabRequest* request);
        static void OnRemovePlayerTagResult(PlayFabRequest* request);
        static void OnAwardSteamAchievementResult(PlayFabRequest* request);
    };
};
