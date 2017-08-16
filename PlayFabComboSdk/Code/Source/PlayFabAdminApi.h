#pragma once

#include <PlayFabComboSdk/PlayFabError.h>
#include <PlayFabComboSdk/PlayFabAdminDataModels.h>
#include <PlayFabComboSdk/PlayFabHttp.h>

namespace PlayFabComboSdk
{
    class PlayFabAdminApi
    {
    public:


        // ------------ Error callback
        static void OnError(const PlayFabRequest& request, const PlayFabError& error);

        // ------------ Generated Api calls
        static int CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerSharedSecrets(ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPolicy(AdminModels::GetPolicyRequest& request, ProcessApiCallback<AdminModels::GetPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request, ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdatePolicy(AdminModels::UpdatePolicyRequest& request, ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeletePlayer(AdminModels::DeletePlayerRequest& request, ProcessApiCallback<AdminModels::DeletePlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ResetUsers(AdminModels::ResetUsersRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteUsers(AdminModels::DeleteUsersRequest& request, ProcessApiCallback<AdminModels::DeleteUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetAllActionGroups(ProcessApiCallback<AdminModels::GetAllActionGroupsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetAllSegments(ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabAdminApi();

        // ------------ Generated result handlers
        static void OnCreatePlayerSharedSecretResult(PlayFabRequest* request);
        static void OnDeletePlayerSharedSecretResult(PlayFabRequest* request);
        static void OnGetPlayerSharedSecretsResult(PlayFabRequest* request);
        static void OnGetPolicyResult(PlayFabRequest* request);
        static void OnSetPlayerSecretResult(PlayFabRequest* request);
        static void OnUpdatePlayerSharedSecretResult(PlayFabRequest* request);
        static void OnUpdatePolicyResult(PlayFabRequest* request);
        static void OnBanUsersResult(PlayFabRequest* request);
        static void OnDeletePlayerResult(PlayFabRequest* request);
        static void OnGetUserAccountInfoResult(PlayFabRequest* request);
        static void OnGetUserBansResult(PlayFabRequest* request);
        static void OnResetUsersResult(PlayFabRequest* request);
        static void OnRevokeAllBansForUserResult(PlayFabRequest* request);
        static void OnRevokeBansResult(PlayFabRequest* request);
        static void OnSendAccountRecoveryEmailResult(PlayFabRequest* request);
        static void OnUpdateBansResult(PlayFabRequest* request);
        static void OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request);
        static void OnCreatePlayerStatisticDefinitionResult(PlayFabRequest* request);
        static void OnDeleteUsersResult(PlayFabRequest* request);
        static void OnGetDataReportResult(PlayFabRequest* request);
        static void OnGetPlayerStatisticDefinitionsResult(PlayFabRequest* request);
        static void OnGetPlayerStatisticVersionsResult(PlayFabRequest* request);
        static void OnGetUserDataResult(PlayFabRequest* request);
        static void OnGetUserInternalDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherInternalDataResult(PlayFabRequest* request);
        static void OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request);
        static void OnGetUserReadOnlyDataResult(PlayFabRequest* request);
        static void OnIncrementPlayerStatisticVersionResult(PlayFabRequest* request);
        static void OnRefundPurchaseResult(PlayFabRequest* request);
        static void OnResetUserStatisticsResult(PlayFabRequest* request);
        static void OnResolvePurchaseDisputeResult(PlayFabRequest* request);
        static void OnUpdatePlayerStatisticDefinitionResult(PlayFabRequest* request);
        static void OnUpdateUserDataResult(PlayFabRequest* request);
        static void OnUpdateUserInternalDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request);
        static void OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request);
        static void OnUpdateUserReadOnlyDataResult(PlayFabRequest* request);
        static void OnAddNewsResult(PlayFabRequest* request);
        static void OnAddVirtualCurrencyTypesResult(PlayFabRequest* request);
        static void OnDeleteStoreResult(PlayFabRequest* request);
        static void OnGetCatalogItemsResult(PlayFabRequest* request);
        static void OnGetPublisherDataResult(PlayFabRequest* request);
        static void OnGetRandomResultTablesResult(PlayFabRequest* request);
        static void OnGetStoreItemsResult(PlayFabRequest* request);
        static void OnGetTitleDataResult(PlayFabRequest* request);
        static void OnGetTitleInternalDataResult(PlayFabRequest* request);
        static void OnListVirtualCurrencyTypesResult(PlayFabRequest* request);
        static void OnRemoveVirtualCurrencyTypesResult(PlayFabRequest* request);
        static void OnSetCatalogItemsResult(PlayFabRequest* request);
        static void OnSetStoreItemsResult(PlayFabRequest* request);
        static void OnSetTitleDataResult(PlayFabRequest* request);
        static void OnSetTitleInternalDataResult(PlayFabRequest* request);
        static void OnSetupPushNotificationResult(PlayFabRequest* request);
        static void OnUpdateCatalogItemsResult(PlayFabRequest* request);
        static void OnUpdateRandomResultTablesResult(PlayFabRequest* request);
        static void OnUpdateStoreItemsResult(PlayFabRequest* request);
        static void OnAddUserVirtualCurrencyResult(PlayFabRequest* request);
        static void OnGetUserInventoryResult(PlayFabRequest* request);
        static void OnGrantItemsToUsersResult(PlayFabRequest* request);
        static void OnRevokeInventoryItemResult(PlayFabRequest* request);
        static void OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request);
        static void OnGetMatchmakerGameInfoResult(PlayFabRequest* request);
        static void OnGetMatchmakerGameModesResult(PlayFabRequest* request);
        static void OnModifyMatchmakerGameModesResult(PlayFabRequest* request);
        static void OnAddServerBuildResult(PlayFabRequest* request);
        static void OnGetServerBuildInfoResult(PlayFabRequest* request);
        static void OnGetServerBuildUploadUrlResult(PlayFabRequest* request);
        static void OnListServerBuildsResult(PlayFabRequest* request);
        static void OnModifyServerBuildResult(PlayFabRequest* request);
        static void OnRemoveServerBuildResult(PlayFabRequest* request);
        static void OnSetPublisherDataResult(PlayFabRequest* request);
        static void OnGetCloudScriptRevisionResult(PlayFabRequest* request);
        static void OnGetCloudScriptVersionsResult(PlayFabRequest* request);
        static void OnSetPublishedRevisionResult(PlayFabRequest* request);
        static void OnUpdateCloudScriptResult(PlayFabRequest* request);
        static void OnDeleteContentResult(PlayFabRequest* request);
        static void OnGetContentListResult(PlayFabRequest* request);
        static void OnGetContentUploadUrlResult(PlayFabRequest* request);
        static void OnResetCharacterStatisticsResult(PlayFabRequest* request);
        static void OnAddPlayerTagResult(PlayFabRequest* request);
        static void OnGetAllActionGroupsResult(PlayFabRequest* request);
        static void OnGetAllSegmentsResult(PlayFabRequest* request);
        static void OnGetPlayerSegmentsResult(PlayFabRequest* request);
        static void OnGetPlayersInSegmentResult(PlayFabRequest* request);
        static void OnGetPlayerTagsResult(PlayFabRequest* request);
        static void OnRemovePlayerTagResult(PlayFabRequest* request);
        static void OnAbortTaskInstanceResult(PlayFabRequest* request);
        static void OnCreateActionsOnPlayersInSegmentTaskResult(PlayFabRequest* request);
        static void OnCreateCloudScriptTaskResult(PlayFabRequest* request);
        static void OnDeleteTaskResult(PlayFabRequest* request);
        static void OnGetActionsOnPlayersInSegmentTaskInstanceResult(PlayFabRequest* request);
        static void OnGetCloudScriptTaskInstanceResult(PlayFabRequest* request);
        static void OnGetTaskInstancesResult(PlayFabRequest* request);
        static void OnGetTasksResult(PlayFabRequest* request);
        static void OnRunTaskResult(PlayFabRequest* request);
        static void OnUpdateTaskResult(PlayFabRequest* request);
    };
};
