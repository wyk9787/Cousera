//
//  ChoreMO+CoreDataProperties.m
//  CoreData
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ChoreMO+CoreDataProperties.h"

@implementation ChoreMO (CoreDataProperties)

+ (NSFetchRequest<ChoreMO *> *)fetchRequest {
	return [[NSFetchRequest alloc] initWithEntityName:@"Chore"];
}

@dynamic chore_name;
@dynamic chore_log;

@end
