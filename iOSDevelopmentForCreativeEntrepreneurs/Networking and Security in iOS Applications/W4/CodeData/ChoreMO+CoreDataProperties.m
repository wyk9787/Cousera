//
//  ChoreMO+CoreDataProperties.m
//  CodeData
//
//  Created by Garrett Wang on 3/9/17.
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
