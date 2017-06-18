//
//  ChoreLogMO+CoreDataProperties.h
//  CoreData
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ChoreLogMO+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface ChoreLogMO (CoreDataProperties)

+ (NSFetchRequest<ChoreLogMO *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSDate *when;
@property (nullable, nonatomic, retain) ChoreMO *chore_done;
@property (nullable, nonatomic, retain) PersonMO *person_who_did_it;

@end

NS_ASSUME_NONNULL_END
