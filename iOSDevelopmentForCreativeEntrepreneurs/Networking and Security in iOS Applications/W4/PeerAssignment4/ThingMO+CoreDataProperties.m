//
//  ThingMO+CoreDataProperties.m
//  PeerAssignment4
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ThingMO+CoreDataProperties.h"

@implementation ThingMO (CoreDataProperties)

+ (NSFetchRequest<ThingMO *> *)fetchRequest {
	return [[NSFetchRequest alloc] initWithEntityName:@"Thing"];
}

@dynamic thing;

@end
