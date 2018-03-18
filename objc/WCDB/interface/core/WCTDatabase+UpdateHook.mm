//
//  WCTDatabase+UpdateHook.m
//  BlocksKit
//
//  Created by wenhamzhou on 2018/2/28.
//

#import <WCDB/WCTDatabase+Private.h>
#import "WCTDatabase+UpdateHook.h"

@implementation WCTDatabase (UpdateHook)

- (void)SetUpdateHook:(WCTRowUpdateHook)hook
{
    if (hook) {
        _database->setUpdateHook([hook](WCDB::Handle *handle, int op, char const * zDb, char const * zName, int64_t rowid, void *info) {
            if(hook){
               hook(op,handle->path.c_str(),zDb,zName,rowid);
            }
        });
    } else {
        _database->setUpdateHook(nullptr);
    }
}

+ (void)SetGlobalUpdateHook:(WCTRowUpdateHook)hook
{
    if (hook) {
        WCDB::Database::SetGlobalUpdateHook([hook](WCDB::Handle *handle, int op, char const * zDb, char const * zName, int64_t rowid, void *info) {
            if(hook){
               hook(op,handle->path.c_str(),zDb,zName,rowid);
            }
        });
    } else {
        WCDB::Database::SetGlobalUpdateHook(nullptr);
    }
}

@end
