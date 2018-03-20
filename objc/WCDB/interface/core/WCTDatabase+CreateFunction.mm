//
//  WCTDatabase+CreateFunction.m
//  BlocksKit
//
//  Created by wenhamzhou on 2018/2/28.
//

#import <WCDB/WCTDatabase+Private.h>
#import "WCTDatabase+CreateFunction.h"

@implementation WCTDatabase (CreateFunction)

- (void)CreateFunction:(NSString *)name handle:(WCTFunction)handle
{
    if (name.length > 0 && handle) {
        _database->createFunction(name.UTF8String, [handle](WCDB::Handle *db, void* sqlite3_content, int argc, void** argv) {
            if(handle){
               handle(sqlite3_content, argc, argv);
            }
        });
    }
}


@end
