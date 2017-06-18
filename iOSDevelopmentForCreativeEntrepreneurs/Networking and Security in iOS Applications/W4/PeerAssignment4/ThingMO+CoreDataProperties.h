//
//  ThingMO+CoreDataProperties.h
//  PeerAssignment4
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ThingMO+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface ThingMO (CoreDataProperties)

+ (NSFetchRequest<ThingMO *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *thing;

@end

NS_ASSUME_NONNULL_END
