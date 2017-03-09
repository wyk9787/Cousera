//
//  ChoreMO+CoreDataProperties.h
//  CodeData
//
//  Created by Garrett Wang on 3/9/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ChoreMO+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface ChoreMO (CoreDataProperties)

+ (NSFetchRequest<ChoreMO *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *chore_name;
@property (nullable, nonatomic, retain) NSSet<ChoreLogMO *> *chore_log;

@end

@interface ChoreMO (CoreDataGeneratedAccessors)

- (void)addChore_logObject:(ChoreLogMO *)value;
- (void)removeChore_logObject:(ChoreLogMO *)value;
- (void)addChore_log:(NSSet<ChoreLogMO *> *)values;
- (void)removeChore_log:(NSSet<ChoreLogMO *> *)values;

@end

NS_ASSUME_NONNULL_END
