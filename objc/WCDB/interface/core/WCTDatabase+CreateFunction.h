//
//  WCTDatabase+CreateFunction.h
//  BlocksKit
//
//  Created by wenhamzhou on 2018/2/28.
//

#import <WCDB/WCDB.h>


typedef void (^WCTFunction)( void* sqlite3_content, int argc, void** argv);

@interface WCTDatabase (CreateFunction)

- (void)CreateFunction:(NSString *)name handle:(WCTFunction)handle;

@end
