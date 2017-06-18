//
//  ChoreLogMO+CoreDataProperties.m
//  CoreData
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ChoreLogMO+CoreDataProperties.h"

@implementation ChoreLogMO (CoreDataProperties)

+ (NSFetchRequest<ChoreLogMO *> *)fetchRequest {
	return [[NSFetchRequest alloc] initWithEntityName:@"ChoreLog"];
}

@dynamic when;
@dynamic chore_done;
@dynamic person_who_did_it;

@end
