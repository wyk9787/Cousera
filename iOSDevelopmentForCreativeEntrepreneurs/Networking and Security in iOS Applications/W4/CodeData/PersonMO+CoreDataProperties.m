//
//  PersonMO+CoreDataProperties.m
//  CodeData
//
//  Created by Garrett Wang on 3/9/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "PersonMO+CoreDataProperties.h"

@implementation PersonMO (CoreDataProperties)

+ (NSFetchRequest<PersonMO *> *)fetchRequest {
	return [[NSFetchRequest alloc] initWithEntityName:@"Person"];
}

@dynamic person_name;
@dynamic chore_log;

@end
