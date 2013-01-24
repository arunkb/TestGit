//
//  ViewsCache.h
//  Intonow
//
//  Created by Gregory Choi on 3/7/11.
//  Copyright 2011 IntoNow. All rights reserved.
//  reference http://www.dimzzy.com/blog/2010/02/uiviews-cache-for-reuse/

#include <UIKit/UIKit.h>

@protocol ReusableView <NSObject>

@property(copy) NSString *reuseIdentifier;

@end


@interface ViewsCache : NSObject {
	NSMutableDictionary *allViews; // reuseIdentifier -> NSMutableArray:UIView
	NSUInteger capacityPerType;
	NSUInteger capacityPerUnit;
}

@property(readonly) NSUInteger capacityPerType;

+ (ViewsCache *)sharedCache;

- (UIView<ReusableView> *)dequeueReusableViewWithIdentifier:(NSString *)reuseIdentifier;
- (void)enqueueReusableView:(UIView<ReusableView> *)view;
- (void)removeReusableView:(UIView<ReusableView> *)view;
- (void)clear;

@end
