//
//  WCTDatabase+UpdateHook.h
//  BlocksKit
//
//  Created by wenhamzhou on 2018/2/28.
//

#import <WCDB/WCDB.h>

/**
 Trigger when a row is updated, inserted or deleted in a rowid table.
 */
typedef void (^WCTRowUpdateHook)(int op, char const *zDbPath, char const *zDb, char const *zName, int64_t rowid);

@interface WCTDatabase (UpdateHook)

/**
 @brief You can register a callback to monitor the operations when a row is updated, inserted or deleted in a rowid table.
 
 [WCTStatistics SetGlobalUpdateHook:^(int op, char const *zDb, char const *zName, int64_t rowid) {
 
 }];
 
 @see WCTRowUpdateHook
 @param hook hook
 */
+ (void)SetGlobalUpdateHook:(WCTRowUpdateHook)hook;

/**
 @brief You can register a callback to monitor the operations when a row is updated, inserted or deleted in a rowid table.
 
 [instance SetUpdateHook:^(int op, char const *zDb, char const *zName, int64_t rowid) {
 
 }];
 
 @see WCTRowUpdateHook
 @param hook hook
 */
- (void)SetUpdateHook:(WCTRowUpdateHook)hook;

@end
